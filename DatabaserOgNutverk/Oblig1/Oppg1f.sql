SELECT
	Sjanger,
    count(sjanger),
    Sum(Pris)
    FROM Film
    Group by Sjanger