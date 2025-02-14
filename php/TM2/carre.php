<style>
    table, th, td {
    border:1px solid black;
    text-align : center;
    }
</style>
<?php

try {
    if (isset($_GET["n1"])) {
        $n1 = $_GET["n1"];
        if (empty($n1)) {
            throw new Exception("<a href=\"http://127.0.0.1:8080/index.html\">rentre</a> un nombre fdp", 1);
        }
    } else {
        throw new Exception("Le nombre est trop grand.", 1);
    }
    if ($n1 > 100 ) {
        throw new Exception("Le nombre est trop grand.", 1);
    } else {
        echo '<table>';
        $nbArray = array();
        echo '<tr>';
        echo '<th>Nombre</th>';
        echo '<th>Au Carre</th>';
        echo '<th>Au Cube</th>';
        echo '</tr>';
        for ($x = 0; $x < $n1 + 1; $x++){
        $nbArray[] = $x;
        echo '<tr>';
        for ($j=0; $j < 3; $j++) { 
            $temp = pow($nbArray[$x], $j + 1); 
            echo "<td>$temp</td> \n";
        }
        echo '</td>';
        }
        echo '</table>';

    }
    
} catch (Exception $e) {
    exit($e -> getMessage());
}
?>