USE Oblig1;

CREATE TABLE IF NOT EXISTS Film(
	FNr INT,
    Title VARCHAR(20) NOT NULL,
    År Int,
    Land VARCHAR(50) NOT NULL,
    Sjanger VARCHAR(20) NOT NULL, 
    Alder INT,
    Tid INT,
    Pris FLOAT,
    CONSTRAINT PKFilm PRIMARY KEY(FNr) 
)Engine = InnoDB;

INSERT INTO Film Values
(1, 'Casablanca', 1942, 'USA','Drama', 15, 102, 149.00),
(2, 'Fort Apechea', 1948, 'USA','Drama', 15, 102, 149.00),
(3, 'Apocolypse Now', 1979, 'USA', 'Action', 18, 155, 123.00),
(4, 'Streets of Fire', 1984, 'USA', 'Action', 15, 93, NULL),
(5, 'High Noon', 1952, 'USA', 'Western', 15, 85, 123.00),
(6, 'Cinema Paradiso', 1988,'Italy', 'Comedy', 11, 123, NULL),
(7, 'Asterix hos britene', 1988, 'France', 'Animation', 7, 78, 149.00),
(8, 'veiviseren', 1987, 'Norway', 'Action', 15, 96, 87.00),
(9, 'Salmer Fra Kjøkkenet', 2002, 'Norway', 'Comedy', 7, 80, 149.00),
(10, 'Anastasia', 1997, 'USA', 'Animation', 7, 94, 123.00),
(11, 'LA Grande bouffe', 1973, 'France', 'Drama', 15, 129, 87.00),
(12, 'Blues Brothers 2000', 1998, 'USA', 'Comedy', 11, 124, 135.00),
(13, 'Beatles: Help', 1965, 'Great Britain', 'Music', 11, 144, NULL);


