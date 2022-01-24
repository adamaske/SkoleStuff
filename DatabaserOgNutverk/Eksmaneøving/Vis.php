<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />

<link rel="stylesheet" href="stil.css" type="text/css" />

</head>

<body>
<?php
    if (!session_id()) session_start();
		
	$Vert = $_SESSION['Vert'];
	$Bruker = $_SESSION['Bruker'];
	$Passord = $_SESSION['Passord'];
	$Database = $_SESSION['Database'];
	

	$fornavn = $_POST['fornavn']; 	
	$_SESSION['fornavn'] = $fornavn;
	//echo '<p>fornavn er '.$fornavn;
    $mysqli = new mysqli($Vert, $Bruker, $Passord, $Database);
//  Sjekk forbindelse
    if (mysqli_connect_errno()) {
        printf( "Ingen forbindelse : %s", mysqli_connect_error() );
        exit();
    }
	$mysqli->set_charset('utf8');

	$setning = "SELECT P.provenr, P.dato, V.vnavn, P.ph, P.temp, E.fornavn 
				FROM (prove AS P JOIN elev AS E ON P.enr=E.enr) 
				JOIN vann AS V  ON P.vid = V.vid WHERE E.fornavn='$fornavn'";
	//echo $setning;
	echo '<p>';
    $resultat = $mysqli->query($setning);
	echo '<table>';
		//echo '<caption><h2>Vannprøve nummer '.$rad[0].' fra Hobbyhuset</h2></caption>';
		echo '<caption><h2>Vannprøver i 2011</h2></caption>';
		echo '<tr><th>PrøveNr</th><th>Tatt dato</th><th>Sted</th><th>pH</th><th>Temperatur</th><th>Elev</th></tr>';
		while ($rad = $resultat->fetch_row()) {
			echo '<tr><td>'.$rad[0].'</td>';
			echo '<td>'.$rad[1].'</td>';
			echo '<td>'.$rad[2].'</td>';
			echo '<td>'.$rad[3].'</td>';
			echo '<td>'.$rad[4].'</td>';
			echo '<td>'.$rad[5].'</td></tr>';
		}
	echo '</table>';

//Lukk forbindelse
    $mysqli->close();
?>

</body>
</html>