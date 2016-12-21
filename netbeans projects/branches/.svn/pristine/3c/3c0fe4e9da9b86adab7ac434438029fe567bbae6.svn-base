<?php

class Login extends Controller {

    function __construct() {
        parent::__construct();
    }
    
    //log in
    public function index () {
        $this->view->render('login/index');
    }
    
    //process form data
    public function run () {
        require_once 'models/login_model.php';
        $model = new Login_Model();
        
        $email = filter_input(INPUT_POST, 'email');
        $password = filter_input(INPUT_POST, 'password');
        
        $data = $model->run($email, $password);
        
        if (!count($data)) {
            $this->view->noMatch = true;
        } else {
            $this->view->noMatch = false;
            $this->view->name = $data[0]['realname'];
            $session_id = uniqid();
            setcookie("bl", $session_id, time() + (86400 * 30));
            $model->addSession($data[0]['ac_id'], $session_id);
        }
        
        $this->view->render('login/run');
    }
}