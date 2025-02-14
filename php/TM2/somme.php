<?php

if (isset($_POST["n1"])&&isset($_POST["nb2"])){
    $nombre1 = $_POST["n1"];
    $nombre2 = $_POST["nb2"];

    if (is_numeric($nombre1) && is_numeric($nombre2)) {
        echo $nombre1 * $nombre2; 
        echo "<br>";
        echo $nombre1 + $nombre2;
    } else {
    echo " <a href=\"http://127.0.0.1:8080/index.html\">rentre</a> un nombre fdp";
    }
    
    
}

?> 