<?php
if (isset($_POST["fname"]) && isset($_POST["name"]) && isset($_POST["email"])) {
    $nom = $_POST["fname"];
    $prenom = $_POST["name"];
    $email = $_POST["email"];
}

$file = "./carnet.sqlite";
$bd = new PDO("sqlite:$file");

// Create table if it doesn't exist
$bd->exec("
    CREATE TABLE IF NOT EXISTS carnet(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nom TEXT, 
    prenom TEXT, 
    email TEXT
    )
");

// Insert new record
$bd->exec("INSERT INTO carnet (nom, prenom, email) VALUES ('$nom', '$prenom', '$email')");
?>
