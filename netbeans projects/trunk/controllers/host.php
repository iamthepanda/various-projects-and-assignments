<?php

/*

 */
class Host extends Controller {
    
    function __construct() {
        require_once 'models/search_model.php';
        parent::__construct();
    }
    
    public function index () { 
        
        $this->view->render('host/index');
    }
    
    public function hostItem1 () {
        $rest_mod = new Search_Model();
        $this->view->restaurants = $rest_mod->getAll();
        
        $this->view->render('host/hostDashItem1');
    }
    
    public function hostItem2 () {
        $rest_mod = new Search_Model();
        $this->view->restaurants = $rest_mod->getAll();
        
        $this->view->render('host/hostDashItem2');
    }
        
}