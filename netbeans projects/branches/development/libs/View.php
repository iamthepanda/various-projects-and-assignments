<?php

class View {

    function __construct() {
        echo "In the Base View<br />";
    }
    
    public function render($name) {
        require 'views/' . $name . '.php';
    }

}
