drop database if exists Eksamen2021;
create database Eksamen2021;
use Eksamen2021;

CREATE TABLE IF NOT exists Kunde(
	KundeNr INT,
    Fornavn VARCHAR(20),
    Etternavn varchar(20),
    Adresse varchar(40),
    constraint primary key(KundeNr)
)Engine = INNODB;


CREATE TABLE IF NOT exists Faktura(
	FakturaNr INT(11),
    FakturaBelop float(20),
    BetaltBelop float(20),
    ForfallsDato DATE,
    BetaltDato DATE,
    KundeNr INT,
CONSTRAINT Foreign Key(KundeNr) REFERENCES Kunde(KundeNr),
constraint Primary key(FakturaNr)

)Engine = INNODB;


create table if not exists Innbetaling(
	InnbetalingsNr INT,
    FakturaNr INT,
    Beløp float, 
    BetalingsMåte INT,
    constraint Primary key(InnbetalingsNr), 
    Constraint foreign key(FakturaNr) references Faktura(FakturaNr)
)Engine = INNODB;

create table if not exists BetalingsMåte(
	BetalingsMåteID INT,
    BetalingsMåteNavn Varchar(30),
    constraint primary key (BetalingsMåteID)
)Engine = INNODB;


DELIMITER $$
CREATE TRIGGER Innbetalt
    AFTER INSERT
    ON Innbetaling For Each row
BEGIN
    UPDATE Faktura F
		set betaltbelop = betaltbelop + new.beløp
        where FakturaNr = new.FakturaNr;
END$$   
DELIMITER ;

DELIMITER $$


insert into betalingsmåte values
(1, "Visa"), 
(2, "Paypal"), 
(3, "Wire"), 
(4, "Cash");

Insert into Kunde values
(1, "Kari", "Andersen", "Krokvegen 11"),
(2, "John", "Smith", "Alleredegate 42"),
(3, "Josef", "Slakk", "Videospillstien 11");
Insert into Faktura values
(1, 120, 0, curdate(), NULL, 1),
(2, 499, 0, curdate(), NULL ,3);

insert into innbetaling values
(1, 2, 499, 2),
(2, 1, 120, 3);



Select K.Fornavn, K.etternavn, F.FakturaBelop, F.Forfallsdato from kunde K Join Faktura F where f.kundenr = k.kundenr;

Select K.Fornavn, K.Etternavn, 
(select count(*) from faktura  F where f.kundenr = k.kundenr) as AntallFakturaer, F.fakturabelop as Totalbelop 
 From Kunde K, Faktura F;	
 
select F.fakturanr, K.fornavn, k.etternavn, f.betaltbelop from Kunde k, Faktura f  
where (f.fakturanr = k.kundenr AND f.betaltbelop >= f.fakturabelop);

