<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
</head>
<body>

<?php
      $Vert="localhost";
      $Bruker="root"; //Du bør opprette din egen bruker
      $Passord="";  //her må du legge passord til root (eller egen bruker)
      $Database="Hobbyhuset";  //her må du bruke din egen database
      $mysqli = new mysqli($Vert, $Bruker, $Passord, $Database);
      if (mysqli_connect_errno()) {
           printf( "Ingen forbindelse : %s", mysqli_connect_error() );
           exit();
       }
       $setning = "SELECT * FROM vare ORDER BY VNr";
    //echo $setning;
    $resultat = $mysqli->query($setning);
    $rad = $resultat->fetch_row();
    if ($rad == null)
    echo '<meta http-equiv="refresh" content="0;URL=index.php">';
    echo '<table>';
    echo '<caption><h3>Varebeholdning i Hobbyhuset</h3></caption>';
    echo '<tr><th>VareNr</th><th>Betegnelse</th><th>Pris</th><th>Kategori</th>
           <th>Lagerantall</th><th>Hylle</th></tr>';
          do {
                echo '<tr><td>'.$rad[0].'</td>';  //VareNr
                echo '<td>'.$rad[1].'</td>';         //Betegnelse
                echo '<td>'.$rad[2].'</td>';         //Pris
                echo '<td>'.$rad[3].'</td>';         //Kategori
                echo '<td>'.$rad[4].'</td>';         //Lagerantall
                echo '<td>'.$rad[5].'</td></tr>';//Hylle
           }  while ($rad = $resultat->fetch_row());//tilordning, tester om $rad==0
    echo '</table>';
    $mysqli->close();
?>
</body>
</html>