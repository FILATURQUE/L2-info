<?php
echo "Exercice 3 <br>";
$file = "./departements.sqlite";

try {
    if (!file_exists($file)) {
        throw new Exception("Fichier de base de données non trouvé : $file");
    }

    $bd = new PDO("sqlite:$file");
    $requeteSQLITE = "SELECT * FROM departements";
    $requete = $bd->query($requeteSQLITE);

    if (!$requete) {
        throw new Exception("Échec de l'exécution de la requête : " . implode(", ", $bd->errorInfo()));
    }

    echo "<table border=1px>
    <tr>
        <th>No</th>
        <th>Nom</th>
    </tr>
    ";

    foreach ($requete as $row) {
        echo "
        <tr>
            <td>$row[no]</td>
            <td>$row[nom]</td>
        </tr>
        ";
    }
    echo "</table>";
} catch (PDOException $e) {
    exit("PDOException : Non connecté à la BD : " . $e->getMessage());
} catch (Exception $e) {
    exit("Exception : " . $e->getMessage());
}


echo "<br><a href=\"http://127.0.0.1:8080/index.html\">rentre a la maison</a>";
?>