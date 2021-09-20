USE Oblig1;

delimiter //
CREATE TRIGGER SjekkPris BEFORE INSERT ON Faktura FOR EACH ROW
BEGIN
 IF NEW.Pris < 0 THEN
     SET new.Pris = 0;
     END IF;
IF NEW.Pris > 1000 THEN
	SET new.Pris = 10000;
    End if;
     END;//
delimiter ;

