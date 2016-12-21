<?php

class Reserve extends Controller {
 
    function __construct() {
        parent::__construct();
    }
    
    public function index () {
        
        $this->view->resMsg = "Your reservation has been made.";
        
        $this->view->return = "Return to homepage.";
        // render needs to be the last thing to execute
        $this->view->render('reserve/index');
    }
    

}