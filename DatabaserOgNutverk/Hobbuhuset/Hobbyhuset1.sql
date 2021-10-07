Create database if not exists Hobbyhuset;
use Hobbyhuset;

DROP TABLE IF EXISTS Ordrelinje;
DROP TABLE IF EXISTS Ordre;
DROP TABLE IF EXISTS Prishistorikk;
DROP TABLE IF EXISTS Vare;
DROP TABLE IF EXISTS Kategori;
DROP TABLE IF EXISTS Kunde;
DROP TABLE IF EXISTS Ansatt;
DROP TABLE IF EXISTS Poststed;

CREATE TABLE Poststed(    
PostNr INT,
Poststed VARCHAR(20) NOT NULL,
CONSTRAINT PostNr_PK PRIMARY KEY (PostNr),
CONSTRAINT lovligePostnr CHECK (PostNr>=0001 AND PostNr<10000)) Engine=InnoDB;

CREATE TABLE Ansatt(    
AnsNr INT,
Fornavn VARCHAR(20) NOT NULL,
Etternavn VARCHAR(20) NOT NULL,
Adresse VARCHAR(20),
PostNr INT,
Fødselsdato DATE,
Kjønn CHAR(1),
Stilling VARCHAR(20),
Årslønn INT,
CONSTRAINT AnsNr_PK PRIMARY KEY (AnsNr),
CONSTRAINT PostNrAnsatt_FK FOREIGN KEY(PostNr) REFERENCES Poststed(PostNr)) Engine=InnoDB;

CREATE TABLE Kunde(    
KNr INT,
Fornavn VARCHAR(20) NOT NULL,
Etternavn VARCHAR(20) NOT NULL,
Adresse VARCHAR(20),
PostNr INT,
CONSTRAINT KNr_PK PRIMARY KEY (KNr),
CONSTRAINT PostNrKunde_FK FOREIGN KEY(PostNr) REFERENCES Poststed(PostNr)) Engine=InnoDB;

CREATE TABLE Kategori(    
KatNr CHAR(5),
Navn VARCHAR(40),
CONSTRAINT KatNrVare_PK PRIMARY KEY (KatNr)) Engine=InnoDB;

CREATE TABLE Vare(    
VNr CHAR(5),
Betegnelse VARCHAR(40),
Pris NUMERIC(8,2),
KatNr CHAR(5),
Antall INT,
Hylle VARCHAR(3),
CONSTRAINT VNrVare_PK PRIMARY KEY (VNr),
CONSTRAINT KatNrVare_FK FOREIGN KEY(KatNr) REFERENCES Kategori(KatNr)) Engine=InnoDB;

CREATE TABLE Prishistorikk(    
VNr CHAR(5),Dato DATE,
Gammelpris NUMERIC(8,2),
CONSTRAINT VNrDato_PK PRIMARY KEY (VNr, Dato),
CONSTRAINT VNr_FK FOREIGN KEY(VNr) REFERENCES Vare(VNr)) Engine=InnoDB;

CREATE TABLE Ordre(    
OrdreNr INT,    
OrdreDato DATE,
KNr INT,
SendtDato DATE,
BetaltDato DATE,
CONSTRAINT Ordre_PK PRIMARY KEY (OrdreNr),
CONSTRAINT KNrOrdre_FK FOREIGN KEY(KNr) REFERENCES Kunde(KNr)) Engine=InnoDB;

CREATE TABLE Ordrelinje(
    OrdreNr INT,    
    VNr CHAR(5),
    PrisPrEnhet NUMERIC(10,2),
    Antall INT,
    CONSTRAINT Ordrelinje_PK PRIMARY KEY (OrdreNr, VNr),
    CONSTRAINT OrdreNrOrdrelinje_FK FOREIGN KEY(OrdreNr) REFERENCES Ordre(OrdreNr),
    CONSTRAINT VNrOrdrelinje_FK FOREIGN KEY(VNr) REFERENCES Vare(VNr)) Engine=InnoDB;
    
    INSERT INTO Poststed (PostNr,Poststed) VALUES (2013,'Skjetten');
    INSERT INTO Poststed (PostNr,Poststed) VALUES (2300,'Hamar');
    INSERT INTO Poststed (PostNr,Poststed) VALUES (2318,'Hamar');
    INSERT INTO Poststed (PostNr,Poststed) VALUES (2321,'Hamar');
    INSERT INTO Poststed (PostNr,Poststed) VALUES (3052,'Krokskogen');
    INSERT INTO Poststed (PostNr,Poststed) VALUES (2310,'Stange');
    INSERT INTO Poststed (PostNr,Poststed) VALUES (2330,'Vallset');
    INSERT INTO Poststed (PostNr,Poststed) VALUES (2340,'Løten');
    INSERT INTO Poststed (PostNr,Poststed) VALUES (2337,'Tangen');
    INSERT INTO Poststed (PostNr,Poststed) VALUES (7050,'Trondheim');
    INSERT INTO Poststed (PostNr,Poststed) VALUES (2312,'Ottestad');
    
    INSERT INTO Ansatt (AnsNr,Fornavn,Etternavn,Adresse,PostNr,Fødselsdato,Kjønn,Stilling,Årslønn) VALUES 
    (100,'Ole','Flaten','Ådalsbrukvn',2340,'1984-06-06','M','HSkL',600000);
    INSERT INTO Ansatt VALUES (101,'Marit','Berg','NBriskebyveg',2321,'1994-11-16','K','InstLdr',700000);
    INSERT INTO Ansatt VALUES (102,'Dag','Nylund','Tangnesvegen',2340,'1987-02-23','M','HSkl',600000);
    INSERT INTO Ansatt VALUES (103,'Jan Erik','Haug','Nordbyveien',2013,'1974-10-03','M','HSkl',600000);
    
    INSERT INTO Kunde (KNr,Fornavn,Etternavn,Adresse,PostNr) VALUES (1000,'Ola','Frost','Tempe',7050);
    INSERT INTO Kunde (KNr,Fornavn,Etternavn,Adresse,PostNr) VALUES (1001,'Espen','Askeladd','Krokskogen',3052);
    INSERT INTO Kunde (KNr,Fornavn,Etternavn,Adresse,PostNr) VALUES (1003,'HA','L','Tangen',2337);
    INSERT INTO Kunde (KNr,Fornavn,Etternavn,Adresse,PostNr) VALUES (1004,'Fridtjof','Johnstad','Ottestad',2312);
    INSERT INTO Kunde (KNr,Fornavn,Etternavn,Adresse,PostNr) VALUES (1005,'Jan Erik','Haug','Skjetten',2013);
    
    INSERT INTO Ordre (OrdreNr,OrdreDato,KNr,SendtDato,BetaltDato) VALUES ('20517','2020-04-19',1000,'2020-04-25','2020-05-05');
    INSERT INTO Ordre (OrdreNr,OrdreDato,KNr,SendtDato,BetaltDato) VALUES ('20518','2020-06-03',1001,'2020-06-09','2020-07-05');
    
    INSERT INTO Kategori (KatNr,Navn) VALUES ('K1','Konfekt og marsipan');
    INSERT INTO Kategori (KatNr,Navn) VALUES ('K2','Hobbymaling');
    INSERT INTO Kategori (KatNr,Navn) VALUES ('K3','Dukker og nisser');
    INSERT INTO Kategori (KatNr,Navn) VALUES ('K4','Blomsterfrø');
    INSERT INTO Kategori (KatNr,Navn) VALUES ('K5','Fiske');
    
INSERT INTO Kategori (KatNr,Navn) VALUES ('K6','Dekorasjoner');
INSERT INTO Kategori (KatNr,Navn) VALUES ('K7','Blomsterfrø');
INSERT INTO Kategori (KatNr,Navn) VALUES ('K8','Bøker');
INSERT INTO Kategori (KatNr,Navn) VALUES ('K9','Keramikk');
INSERT INTO Kategori (KatNr,Navn) VALUES ('K10','Blomsterløker');
INSERT INTO Kategori (KatNr,Navn) VALUES ('K11','Hageutstyr');

INSERT INTO Vare (VNr,Betegnelse,Pris,KatNr,Antall,Hylle) VALUES ('90693','Marsipantang',               57.00,'K1',    0,'B17');
INSERT INTO Vare (VNr,Betegnelse,Pris,KatNr,Antall,Hylle) VALUES ('44939','Hobbymaling, 6 farger',     115.00,'K2',    2,'B02');
INSERT INTO Vare (VNr,Betegnelse,Pris,KatNr,Antall      ) VALUES ('10830','Nisseskjegg, 30 cm',         57.50,'K3',   42      );
INSERT INTO Vare (VNr,Betegnelse,Pris,KatNr,Antall,Hylle) VALUES ('33044','Blandet blomsterfrø',        14.50,'K4', 1080,'E05');
INSERT INTO Vare (VNr,Betegnelse,Pris,KatNr,Antall,Hylle) VALUES ('15217','Kram tørrfluekorker, 5 stk', 32.00,'K5',  213,'B42');
INSERT INTO Vare (VNr,Betegnelse,Pris,KatNr,Antall,Hylle) VALUES ('90164','Lakrisekstrakt, 100g',       75.50,'K1',  104,'B06');
INSERT INTO Vare (VNr,Betegnelse,Pris,KatNr,Antall,Hylle) VALUES ('15207','Antron garn, hvit',          24.50,'K5',   21,'B41');
INSERT INTO Vare (VNr,Betegnelse,Pris,KatNr,Antall,Hylle) VALUES ('13001','Glasskuler, 100g',           38.00,'K3',    0,'E11');
INSERT INTO Vare (VNr,Betegnelse,Pris,KatNr,Antall,Hylle) VALUES ('21032','Furuspon, 3 cmg',            57.50,'K6',  240,'B32');
INSERT INTO Vare (VNr,Betegnelse,Pris,KatNr,Antall,Hylle) VALUES ('33045','Blomkarse',                  17.50,'K7', 1206,'E05');
INSERT INTO Vare (VNr,Betegnelse,Pris,KatNr,Antall,Hylle) VALUES ('55130','Moro med marsipan',         298.50,'K8',  140,'C20');
INSERT INTO Vare (VNr,Betegnelse,Pris,KatNr,Antall,Hylle) VALUES ('15211','Tubeflue verktøy',          209.00,'K5',   39,'B42');
INSERT INTO Vare (VNr,Betegnelse,Pris,KatNr,Antall,Hylle) VALUES ('42615','Gipsform marihøner',        106.00,'K9',  124,'B03');
INSERT INTO Vare (VNr,Betegnelse,Pris,KatNr,Antall      ) VALUES ('64551','Hengebegonia, 10 stk.',     118.00,'K10', 206);
INSERT INTO Vare (VNr,Betegnelse,Pris,KatNr,Antall,Hylle) VALUES ('65247','Liten plantespade',          75.00,'K11',  76,'A25');

INSERT INTO Prishistorikk (VNr, Dato, Gammelpris) VALUES (44939, '2020-09-12', 125.00);
INSERT INTO Prishistorikk (VNr, Dato, Gammelpris) VALUES (33045, '2020-08-31', 21.00);
INSERT INTO Prishistorikk (VNr, Dato, Gammelpris) VALUES (64551, '2020-07-22', 110.00);
INSERT INTO Prishistorikk (VNr, Dato, Gammelpris) VALUES (33044, '2019-12-15', 12.50);

INSERT INTO Ordrelinje (OrdreNr,VNr,PrisPrEnhet,Antall) VALUES ('20517','10830', 29.90, 1);
INSERT INTO Ordrelinje (OrdreNr,VNr,PrisPrEnhet,Antall) VALUES ('20517','21032', 57.60, 3);
INSERT INTO Ordrelinje (OrdreNr,VNr,PrisPrEnhet,Antall) VALUES ('20517','64551',118.00, 2);
INSERT INTO Ordrelinje (OrdreNr,VNr,PrisPrEnhet,Antall) VALUES ('20518','10830', 29.90, 1);
INSERT INTO Ordrelinje (OrdreNr,VNr,PrisPrEnhet,Antall) VALUES ('20518','21032', 57.60, 3)