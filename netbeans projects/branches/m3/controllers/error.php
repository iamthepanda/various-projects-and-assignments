<?php

class Error extends Controller {

    const DEFAULT_MESSAGE = "Unknown Error";
    
    function __construct() { 
        parent::__construct();
    }
    
    public function index () {
        $this->view->errorMsg = "test message";
        $this->view->render('error/index');
    }
    
    public function message ($message = self::DEFAULT_MESSAGE) {
        //echo "HERE IN MESSAGE"; die;
       
    }
    
    public function test2 ($one = "one", $two = "two") {
        $this->view->one = $one;
        $this->view->two = $two;
        $this->view->render("error/test2");
    }
    

}

