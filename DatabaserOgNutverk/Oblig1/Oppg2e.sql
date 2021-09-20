USe oblig1;

SELECT 
    F.Fakturanummer, F.Kundenummer, Pris, K.Fornavn, K.Etternavn
FROM
    Faktura AS F,
    Kunde AS K
WHERE
    F.Kundenummer = K.Kundenummer;