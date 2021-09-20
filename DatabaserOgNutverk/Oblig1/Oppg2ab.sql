USE Oblig1;

CREATE TABLE IF NOT EXISTS Kunde(
	Kundenummer INT(20) PRIMARY KEY,
    Fornavn VARCHAR(20),
    Etternavn VARCHAR(20),
    Adresse VARCHAR(50),
    Postnummer INT
)Engine = InnoDB;

INSERT INTO Kunde VALUES
(1, 'Jonas', 'Ghar Støre', 'Statsministerveien 1', 1312),
(2, 'Erna', 'Solberg', 'Tapergata 13', 4312),
(3, 'Kari', 'Mo', 'Gateveien 79', 1234);
