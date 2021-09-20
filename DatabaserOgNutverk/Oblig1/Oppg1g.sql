USE Oblig1;

ALTER TABLE Film ADD Score INT(1);

UPDATE Film SET Score = 6 WHERE FNr = 1;
UPDATE Film SET Score = 3 WHERE FNr = 2;
UPDATE Film SET Score = 2 WHERE FNr = 3;
UPDATE Film SET Score = 8 WHERE FNr = 4;
UPDATE Film SET Score = 1 WHERE FNr = 5;
UPDATE Film SET Score = 2 WHERE FNr = 6;
UPDATE Film SET Score = 9 WHERE FNr = 7;
UPDATE Film SET Score = 8 WHERE FNr = 8;
UPDATE Film SET Score = 1 WHERE FNr = 9;
UPDATE Film SET Score = 4 WHERE FNr = 10;
UPDATE Film SET Score = 7 WHERE FNr = 11;
UPDATE Film SET Score = 9 WHERE FNr = 12;
UPDATE Film SET Score = 6 WHERE FNr = 13;
