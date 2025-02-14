<?php
if (isset($_POST["fname"]) && isset($_POST["name"]) && isset($_POST["email"])) {
    $nom = $_POST["fname"];
    $prenom = $_POST["name"];
    $email = $_POST["email"];
}

$file = "./carnet.sqlite";
$bd = new PDO("sqlite:$file");

$bd -> exec("
    CREATE TABLE carnet(
    id INTERGER PRIMARY KEY,
    nom TEXT, 
    prenom TEXT, 
    email TEXT
    )
");

$bd -> exec("INSERT INTO carnet (nom, prenom, email) VALUE ($nom, $prenom, $email)");

$requete = $bd -> query("SELECT * FROM carnet");

echo "<table border = 1px> 
    <tr>
        <th>NOM</th>
        <th>PRENOM</th>
        <th>EMAIL</th>
    </tr>";

foreach ($requete as $row ) {
    echo "
        <tr>
            <td>$row[nom]</td>
            <td>$row[prenom]</td>
            <td>$row[email]</td>
        </tr>";
}

echo "</table>";
echo "<br><a href=\"http://127.0.0.1:8080/index.html\">rentre a la maison</a>";
