USE Oblig1;

CREATE TABLE IF NOT EXISTS Faktura (
    FakturaNummer INT,
    KundeNummer INT,
    Pris FLOAT,
    PRIMARY KEY (FakturaNummer),
    FOREIGN KEY (KundeNummer)
        REFERENCES Kunde (Kundenummer)
)  ENGINE=INNODB;
