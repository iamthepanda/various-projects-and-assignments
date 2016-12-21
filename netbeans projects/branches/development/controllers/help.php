<?php

class Help extends Controller {

    function __construct() {
        parent::__construct();
        echo "We are inside Help controller<br />";
        
        $this->view->render('help/index');
    }
    
    public function other ($arg = false){
        echo "We are inside Other<br />";
        echo "Optional: " . $arg . "<br />";
        
        require 'models/help_model.php';
        $model = new Help_Model();
    }

}