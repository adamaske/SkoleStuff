create database Hobbyhuset;

CREATE DATABASE IF NOT EXISTS Oblig1; 
use Hobbyhuset;
drop table Vare;
CREATE TABLE IF NOT EXISTS Vare( 
	VNr INT, 
    Betegnelse VARCHAR(50), 
    Pris Int, 
    Kategori VARCHAR(50) NOT NULL, 
    Antall INT,  
    Hylle VARCHAR(20), 
CONSTRAINT PKVare PRIMARY KEY(VNr)
) Engine = INNODB;

INSERT INTO Vare Values 
(90693, 'Marsipantang', 57, "Konfekt og marsipan", 0, "B17"), 
(44939, "Hobbymaling, 6 farger", 115, "Hobbymaling", 2, "B02"),
(10830, "Nisseskjegg, 30cm", 57.50, "Dukker og nisser", 42, NULL),
(33044, "Blandet blomsterfrø", 14.40, "Blomsterfrø", 1080, "E05"),
(15217, "Kram tørrfluekorker, 5stk", 32.00, "Fiske", 213, "B42"),
(90164, "Lakrisekstrakt, 100g", 75.50, "Konfekt og marsipan", 104, "B06"),
(15207, "Antron garn, hvit", 24.50, "Fisek", 21, "B41"),
(13001, "Glasskuler, 100gr", 38.00, "Dukker og nisser", 240, "B32"),
(21032, "Furuspon, 3 cm", 57.50, "Dekorasjoner", 0, "E11"),
(33045, "Blomkarse", 17.50, "Blomsterfrø", 1206, "E05"),
(55130, "Moro med marsipan", 298.50, "Bøker", 140, "C20"),
(15211, "Tubeflue verktøy", 209.00, "Fiske", 39, "B42"),
(42615, "Gispform marihøner", 106.00, "Keramikk", 125, "B03"),
(64551, "Hengebegonia, 10stk", 118.00, "Blomserløker", 206, NULL),
(65247, "Liten plantespade", 75, "Hageutstyr", 76, "A25");

Select * FROM Vare;
Select * From Vare Where Kategori = "Fiske";
Select * From Vare Where Pris>50;
Select COUNT(*) From Vare WHERE Pris>50;
Select * From Vare WHERE Hylle is NOT NULL;
SELECT * FROM Vare WHERE Antall%2=1;
SELECT * FROM Vare WHERE LENGTH(Betegnelse)<15;
SELECT * FROM Vare WHERE LENGTH(Betegnelse)=LENGTH(Kategori);
SELECT * FROM Vare ORDER BY Antall DESC;
SELECT VNr,Betegnelse,Hylle FROM Vare ORDER BY Hylle DESC;
SELECT AVG(Pris) FROM Vare;
SELECT * FROM Vare WHERE Pris<(SELECT AVG(Pris) FROM Vare);