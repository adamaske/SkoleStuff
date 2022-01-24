CREATE TABLE vann (
         provenr   INT,
         enr  INT,  #evt NOT NULL, UNIQUE  
         fornavn VARCHAR(20) NOT NULL,
         dato  DATE,
         vid  INT,  #evt NOT NULL, UNIQUE
         vnavn VARCHAR(20) NOT NULL,
         pH  DECIMAL(3,1) NOT NULL,
         temp DECIMAL(3,1) NOT NULL
);

DROP DATABASE IF EXISTS Vannprøve;
CREATE DATABASE IF NOT EXISTS Vannprøve;
USE Vannprøve;
CREATE TABLE elev (
         enr  INT PRIMARY KEY,
         fornavn VARCHAR(20) NOT NULL
) ENGINE=InnoDB;
CREATE TABLE vann (
         vid  INT PRIMARY KEY,
         vnavn VARCHAR(20) NOT NULL
) ENGINE=InnoDB;
CREATE TABLE prove (
         provenr   INT,
         dato  DATE,
         pH  DECIMAL(3,1) NOT NULL,
         temp DECIMAL(3,1) NOT NULL,
         enr  INT,
         vid  INT,
         CONSTRAINT PRIMARY KEY(provenr),
         CONSTRAINT FOREIGN KEY(enr) REFERENCES elev(enr),
Side 3 av 5
         CONSTRAINT FOREIGN KEY(vid) REFERENCES vann(vid)
) ENGINE=InnoDB;
DELETE FROM prove;
DELETE FROM elev;
DELETE FROM vann;
INSERT INTO elev VALUES (24, 'Kari'), (16, 'Jan') , (31, 'Stein') , (12, 'Anne') , (37, 'Inger') , 
                      (47, 'Gunnar') , (21, 'Unni') , (38, 'Milli') , (27, 'Roar');
INSERT INTO vann VALUES (5, 'Pyttvann'), (2, 'Steintjønn') , (3, 'Sortsjøen') , (1, 'Rokosjøen') , (6, 'Gaukilsjøen') , 
                       (7, 'Sætersjøen');
INSERT INTO prove VALUES
             (176, '2011-08-24', 5.6, 13.2, 24, 5),
             (181, '2011-08-24', 6.0, 16.5, 16, 2), 
             (153, '2011-08-24', 5.8, 14.3, 31, 3),
             (  45, '2011-08-23', 5.9, 16.0, 24, 1),
             (  18, '2011-08-23', 5.7, 13.5, 12, 5), 
             (  83, '2011-08-23', 5.7, 15.5, 31, 3),
             (  43, '2011-08-23', 5.7, 15.5, 37, 3),
             (  77, '2011-08-25', 5.5, 16.3, 47, 5),
             (    8, '2011-08-24', 5.9, 15.8, 24, 3),
             (123, '2011-08-25', 5.5, 13.8, 47, 6);
             
             
	Skriv alle verdier i databasen sortert stigende etter fornavn
>db.vann.find().sort({"fornavn":1}).pretty(); 
SELECT P.provenr, P.dato, V.vnavn, P.ph, P.temp, E.fornavn FROM (prove AS P JOIN elev AS E ON P.enr=E.enr) 
          JOIN vann AS V  ON P.vid = V.vid ORDER BY E.fornavn;
Finn antall registreringer 
>db.vann.find().count();
SELECT COUNT(*) FROM prove;
Skriv alle målinger foretatt av Kari 
>db.vann.find({"fornavn":"Kari"}).pretty(); 
SELECT P.provenr, P.dato, V.vnavn, P.ph, P.temp, E.fornavn FROM (prove AS P JOIN elev AS E ON P.enr=E.enr) 
          JOIN vann AS V  ON P.vid = V.vid WHERE E.fornavn='Kari';
Side 4 av 5
Skriv alle målinger foretatt den 23. august 
>db.vann.find({"dato":"23.08.2011"}).pretty(); 
SELECT P.provenr, P.dato, V.vnavn, P.ph, P.temp, E.fornavn FROM (prove AS P JOIN elev AS E ON P.enr=E.enr) 
          JOIN vann AS V  ON P.vid = V.vid WHERE P.Dato='2011-08-23';
Finn alle målinger der pH>5.7
>db.vann.find({"ph":{$gt:5.7}}).pretty();
SELECT P.provenr, P.dato, V.vnavn, P.ph, P.temp, E.fornavn FROM (prove AS P JOIN elev AS E ON P.enr=E.enr) 
          JOIN vann AS V  ON P.vid = V.vid WHERE P.ph>5.7;
Skriv ut alle elevnavnene 
>db.vann.aggregate({$project:{"_id":0,"fornavn":1}});
NB: kan ikke koble "aggregate" med "distinct" i MongoDB
>db.vann.distinct("fornavn");
SELECT fornavn FROM elev;
SELECT DISTINCT E.fornavn FROM prove AS P JOIN elev AS E ON P.enr=E.enr; (uten prøveløse elever)
Finn antall målinger hver elev har foretatt 
>db.vann.aggregate({$group:{"_id":"$dato", antall:{$sum:1}}}); (for enkelt, tar med elevere uten målinger)
> db.vann.aggregate([
                 {$match:{ph:{$gte:0}}}, (bare elever med målinger telles med)
                 {$group:{"_id":"$fornavn", antall:{$sum:1}}}
]);
SELECT E.fornavn, COUNT(P.enr) AS antall FROM prove AS P 
             RIGHT OUTER JOIN elev AS E ON P.enr=E.enr 
             GROUP BY P.enr;
Finn antall målinger foretatt i hvert vann 
>db.vann.aggregate({$group:{"_id":"$vnavn", antall:{$sum:1}}}); (tar med sjøer uten målinger)
>db.vann.aggregate([
                 {$match:{ph:{$gte:0}}}, 
                 {$group:{"_id":"$vnavn", antall:{$sum:1}}}
]); (bare vann med målinger telles med)
SELECT V.vnavn, COUNT(P.vid) AS antall FROM prove AS P 
             RIGHT OUTER JOIN vann AS V ON P.vid=V.vid 
             GROUP BY P.vid;
Finn elever som ikke har tatt prøver
>db.vann.find({vid:{$exists:false}},{_id:0, fornavn:1});
SELECT E.fornavn, E.enr FROM elev AS E where E.enr NOT IN (SELECT enr FROM prove);
Finn alle elever og alle prøver av de elevene som har tatt prøver
>db.vann.aggregate({$project:{"_id":0,"fornavn":1, "vnavn":1}});
>db.vann.find({}, {"_id":0,"fornavn":1, "vnavn":1});
SELECT E.fornavn, 'har målt pH i', V.vnavn FROM (elev E JOIN prove P 
           ON E.enr = P.enr) RIGHT JOIN Vann V ON V.vid = P.vid;
DELIMITER //
CREATE PROCEDURE SettInn(
      IN provenr INT,  IN enr INT,  IN fornavn VARCHAR(45),  IN dato DATE,  
      IN vid INT, IN vnavn VARCHAR(45) , IN ph DECIMAL(4,2) , IN temp DECIMAL(5,2)
)
BEGIN
         START TRANSACTION;
                 INSERT INTO elev VALUES (enr, fornavn);
                 INSERT INTO vann VALUES (vid, vnavn);
                 INSERT INTO prove VALUES  (provenr, dato, ph, temp, enr, vid);
          COMMIT;
END //
DELIMITER ;

CALL SettInn(91, 88, 'Khalid', '2011.08.23', 8, 'Harasjøen', 5.9, 16.7);
             
             