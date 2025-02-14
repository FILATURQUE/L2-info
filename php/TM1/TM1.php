
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>TM1</title>

    <style>
    table, th, td {
    border:1px solid black;
    text-align : center;
    }
    </style>
    
</head>
<body>

<?php
// Exercice 1
/*
echo "Exercice 1 <br><br>";

$prenom = 'YANG Jackie';

echo "Je m'appelle " . $prenom . " et je suis un etudiant a l" . '<a href="https://www.u-pec.fr">UPEC</a>';
echo "<br>200 means no problem / 404 means page nout found / 302 means redirection link <br> <br>";

// Exercice 2 
echo "Exercice 2 <br><br>";
echo '<table>';
$nbArray = array();
echo '<tr>';
echo '<th>Nombre</th>';
echo '<th>Au Carre</th>';
echo '<th>Au Cube</th>';
echo '</tr>';
for ($x = 0; $x < 21; $x++){
    $nbArray[] = $x;
    echo '<tr>';
    for ($j=0; $j < 3; $j++) { 
        $temp = pow($nbArray[$x], $j + 1); 
        echo "<td>$temp</td> \n";
    }
    echo '</td>';
}
echo '</table>';

echo "<br><br>";

echo 'Exercice 3<br><br>';
$days = [
    ['Lundi','Monday'],
    ['Mardi','Tuesday'],
    ['Mercredi','Wenesday'],
    ['Jeudi','Thursday'],
    ['Vendredi','Friday'],
    ['Samedi','Saturday'],
    ['Dimanche','Sunday']
];

echo '<table>';
echo '<tr>';

echo '<th>Fr</th>';
echo '<th>En</th>';

echo '</tr>';

for ($i=0; $i < 7; $i++) { 
    echo '<tr>';
    for ($j=0; $j < 2; $j++) { 
        echo "<td>" . $days[$i][$j] . "</td>\n";
    }
    echo'</tr>';
}
echo '</table> <br><br>';


echo'Exerciece 4 <br><br>';

$jour = readline("Entre un jour de la semaine:\n");
$id = -1;



for ($i=0; $i < 7; $i++) { 
    if (strcmp($jour, $days[$i][0]) == 0) {
        $id = $i;
    }
}

try {
    if ($id == -1) {
        throw new Exception("Le jour que tu as rentre est invalide.", 1);
    } else {
        echo 'Tu as entre ' . $jour . '<br>';
        echo "Today is " . $days[$id][1] . '<br><br>';
    }
} catch (Exception $e) {
    exit($e -> getMessage());
}
    */


echo 'Exercice 5 <br><br>';

class Monster{
    private $nom;
    private $catchPhrase;
    
    public function __construct($nom, $catchPhrase){
        $this->nom = $nom;
        $this->catchPhrase = $catchPhrase;
    }
    
    public function getName(){
        return $this->nom;
    }
    
    public function getPhrase(){
        return $this->catchPhrase;
    }
}

$dracula = new Monster("Dracula","je vais vous mordre");
$nom =$dracula->getName(); 
$msg = $dracula->getPhrase();
echo "Je suis $nom, $msg"

?>

    
</body>
</html>