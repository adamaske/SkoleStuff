create database if not exists Oblig1;
USE Oblig1;

CREATE TABLE IF NOT EXISTS Film(
	FNr INT(11),
    Title VARCHAR(100) NOT NULL,
    År SMALLINT(6),
    Land VARCHAR(50) NOT NULL,
    Sjanger VARCHAR(50) NOT NULL, 
    Alder SMALLINT(6),
    Tid SMALLINT(6),
    Pris DECIMAL(8,2),
    CONSTRAINT PKFilm PRIMARY KEY(FNr) 
)Engine = InnoDB;

CREATE TABLE IF NOT EXISTS Kunde(
	Kundenummer INT(20) PRIMARY KEY,
    Fornavn VARCHAR(20),
    Etternavn VARCHAR(20),
    Adresse VARCHAR(50),
    Postnummer INT
)Engine = InnoDB;

CREATE TABLE IF NOT EXISTS Faktura(
FakturaNr INT(11) NOT NULL PRIMARY KEY,
KundeNr INT(20),
Dato DATE,
FilmNr INT(11),
FOREIGN KEY(KundeNr) references Kunde(Kundenummer),
FOREIGN KEY(FilmNr) REFERENCES Film(FNr)
)ENgine = INNODB;

INSERT INTO FAKTURA VALUES
(1, 3, CURDATE(), 5), 
(2, 3, CURDATE(), 11),
(3, 3, CURDATE(), 7);

ALTER TABLE Film 
ADD COLUMN AntallSolgt INT(5) AFTER Pris;

DELIMITER $$

CREATE TRIGGER LeggTilSalg
    AFTER INSERT
    ON FAKTURA FOR EACH ROW
BEGIN
    UPDATE Film
		set antallsolgt = antallsolgt +1
        where Fnr = new.filmnr;
        
	
END$$    

DELIMITER ;