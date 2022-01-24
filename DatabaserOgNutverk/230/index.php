<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
</head>
<body>

<?php
      $Vert="localhost";
      $Bruker="root"; 
      $Passord="";  
      $Database="Eksamen2021";  
      $mysqli = new mysqli($Vert, $Bruker, $Passord, $Database);
      if (mysqli_connect_errno()) {
           printf( "Ingen forbindelse : %s", mysqli_connect_error() );
           exit();
       }
       $setning = "SELECT * FROM Kunde";
    //echo $setning;
    $resultat = $mysqli->query($setning);
    $rad = $resultat->fetch_row();
    if ($rad == null)
    echo '<meta http-equiv="refresh" content="0;URL=index.php">';
    echo '<table>';
    echo '<caption><h3>Kunder i Eksamen2021</h3></caption>';
    echo '<tr><th>KundeNr</th><th>Fornavn</th><th>Etternavn</th><th>Adresse</th></tr>';
          do {
                echo '<tr><td>'.$rad[0].'</td>';  //KundeNr
                echo '<td>'.$rad[1].'</td>';         //Fornavn
                echo '<td>'.$rad[2].'</td>';         //Etternavn
                echo '<td>'.$rad[3].'</td></tr>';//Adresse
           }  while ($rad = $resultat->fetch_row());//tilordning, tester om $rad==0
    echo '</table>';
    $mysqli->close();
?>
</body>
</html>