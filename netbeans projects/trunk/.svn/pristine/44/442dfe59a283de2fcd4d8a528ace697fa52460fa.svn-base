<?php

class Index extends Controller {
 
    function __construct() {
        parent::__construct();
    }
    
    public function index () {
        
        $this->view->indexPageMessage = "Welcome to BiteLine!";
        
        
        // render needs to be the last thing to execute
        $this->view->render('index/index');
    }
    
    public function test ($param = null) {
        //echo "in test with parmater: $param<br />"; die;
    }

}