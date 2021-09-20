USE Oblig1;

Select
	Sjanger,
    count(Sjanger),
    Sum(Pris),
    Alder,
    Pris
    FROM Film
    group by Sjanger;