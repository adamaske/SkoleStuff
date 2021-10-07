SELECT * FROM
    Vare AS V,
    Kategori AS K
WHERE
    V.KatNr = K.KatNr
ORDER BY K.Navn;

SELECT * FROM
    Vare AS V
        JOIN
    Kategori AS K ON V.KatNr = K.KatNr
ORDER BY K.Navn;

CREATE VIEW VKunde AS
    SELECT 
        K.Fornavn, P.Poststed
    FROM
        Kunde AS K,
        Poststed AS P
    WHERE
        K.PostNr = P.PostNr;
        
        CREATE VIEW VKunde AS
    SELECT 
        K.Fornavn, P.Poststed
    FROM
        Kunde AS K
            JOIN
        Poststed AS P ON K.PostNr = P.PostNr;
        
SELECT K.Fornavn, COUNT(K.KNr) AS AntallOrdrer         
	FROM Ordre AS O, Kunde AS K
    WHERE O.KNr=K.KNr GROUP BY K.KNr;
    
SELECT K.Fornavn, COUNT(K.KNr) AS AntallOrdrer       
		FROM Ordre AS O JOIN Kunde AS K
        ON O.KNr=K.KNr GROUP BY K.KNr;
        
SELECT Kunde.fornavn, ordre.ordredato, GROUP_CONCAT(vare.Betegnelse SEPARATOR ',')                         
	AS varebetegnelser,
    SUM(ordrelinje.PrisPrEnhet * ordrelinje.Antall) AS Totalpris  FROM Kunde,
    Ordre,
    Ordrelinje,
    Vare          
    WHERE ordre.KNr = Kunde.Knr AND ordrelinje.OrdreNr = Ordre.OrdreNr
    AND vare.VNr = ordrelinje.VNr
    GROUP BY (ordrelinje.Ordrenr);
    
SELECT A.Fornavn, A.Etternavn, A.Adresse, A.PostNr, P.Poststed        
FROM Ansatt AS A, Poststed AS P       
WHERE A.PostNr=P.PostNr AND A.Kjønn='K';

SELECT COUNT(*) FROM Kunde AS K, Ansatt AS A
        WHERE K.Fornavn=A.Fornavn AND K.Etternavn=A.Etternavn AND K.PostNr=A.PostNr;
        
SELECT 
    A.Fornavn, A.Etternavn, A.Adresse, A.PostNr, P.Poststed
FROM
    Kunde AS K,
    Ansatt AS A,
    Poststed AS P
WHERE
    K.Fornavn = A.Fornavn
        AND K.Etternavn = A.Etternavn
        AND K.PostNr = A.PostNr
        AND A.PostNr = P.PostNr;
        
SELECT 
    V.Betegnelse
FROM
    Vare AS V,
    Prishistorikk AS PH
WHERE
    V.VNr = PH.VNr;
    
SELECT V.Betegnelse FROM Vare AS V, Prishistorikk AS PH
			WHERE V.VNr=PH.VNr;
        
        
SELECT 
    V.Betegnelse,
    ((V.Pris - PH.Gammelpris) / PH.Gammelpris) * 100
FROM
    Vare AS V,
    Prishistorikk AS PH
WHERE
    V.VNr = PH.VNr; 
    
SELECT DISTINCT K.Navn FROM Kategori AS K, Vare AS V, Prishistorikk AS PH
         WHERE K.KatNr=V.KatNr AND V.VNr=PH.VNr;
         
SELECT K.Navn, COUNT(K.Navn) FROM Kategori AS K, Vare AS V, Prishistorikk AS PH
         WHERE K.KatNr=V.KatNr AND PH.VNr=V.VNr GROUP BY K.Navn;
         
SELECT V.Betegnelse FROM Vare AS V
         WHERE V.VNr NOT IN (SELECT OL.VNr FROM Ordrelinje AS OL);
         
SELECT P.Poststed FROM Poststed AS P
        WHERE P.PostNr NOT IN (SELECT A.PostNr FROM Ansatt AS A);