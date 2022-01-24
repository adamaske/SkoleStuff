<!DOCTYPE html>
<html>
<title>
Vannprøve
</title>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />

<link rel="stylesheet" href="stil.css" type="text/css" />

</head>

<body>

<?php 
    if (!session_id()) session_start();

	$Vert="localhost";
	$Bruker="opim21";
	$Passord="opim";
	$Database="vannprove";
	
	$_SESSION['Vert'] = $Vert;
	$_SESSION['Bruker'] = $Bruker;
	$_SESSION['Passord'] = $Passord;
	$_SESSION['Database'] = $Database;
	
	$mysqli = new mysqli($Vert, $Bruker, $Passord, $Database);
    if (mysqli_connect_errno()) {
        printf( "Ingen forbindelse : %s", mysqli_connect_error() );
        exit();
    }
	$mysqli->set_charset('utf8');
	$setning = "SELECT fornavn FROM elev ORDER BY fornavn";
	//echo $setning;
    $resultat = $mysqli->query($setning);
    $rad = $resultat->fetch_row();
	if ($rad == null)
		echo 'NULL';//'<META HTTP-EQUIV="refresh" content="0;URL=index.php">';
   
    echo "<h2>Elever som deltar </h2><br><br>";

echo '<table>';
echo '<tr>';
echo '<form method="POST" action="Vis.php">';
    echo '<td>Elev</td>';
    echo '</tr>';
    echo '<tr>';
	
	echo '<td><select name=fornavn>';
    do {
		echo '<option value='.$rad[0].'>'.$rad[0].'</option>'; 
	} while ($rad = $resultat->fetch_row());
 	echo '</select></td>';
		echo '<td><input type="submit" value="Vis prøver"></td>';
	echo '</form>';
	echo '</tr>';

echo '</table>';
$mysqli->close();
?>

</body>
</html>
