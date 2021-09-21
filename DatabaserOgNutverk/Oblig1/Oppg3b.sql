USE Company;

CREATE TABLE IF NOT EXISTS Ansatte(
	Navn VARCHAR(50),
    Adresse VARCHAR(50)
    


)Engine = InnoDB;


INSERT INTO Ansatte VALUES
("Elisabeth", "1312 Krokveien"),
("Andrew", "1789 Dataspill");


SELECT SUBSTRING_INDEX(Adresse, ' ', 1) AS Postnnummer from Ansatte;