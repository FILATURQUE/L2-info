<?php
echo 'Exercice 5 <br><br>';

class Monstre { 
    private $name;
    private $msg;

    function __construct($name, $msg){
        $this->name = $name;
        $this->msg = $msg;
    }

    function get_name(){
        return $this->name;
    }

    function get_msg(){
        return $this->msg;
    }
}


$dracula = new Monstre("Dracula","je vais vous mordre");
$nom=$dracula->get_name();
$phrase=$dracula->get_msg();
echo "Je suis $nom, $phrase";