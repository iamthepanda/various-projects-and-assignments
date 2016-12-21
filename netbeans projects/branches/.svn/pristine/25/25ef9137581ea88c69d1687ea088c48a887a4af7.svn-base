<?php

class Login extends Controller {

    function __construct() {
        parent::__construct();
        $this->view->render('login/index');
    }
    
    public function index () {
        require_once 'models/login_model.php';
        $model = new Login_Model();
        
        //$this->view->username = $model->getUsername();
        $this->view->render('login/index');
    }
    
    public function login () {
        
    }
    
    public function run () {
        $this->model->run();
    }
    
    public function getUsername() {
        return null;
    }

}