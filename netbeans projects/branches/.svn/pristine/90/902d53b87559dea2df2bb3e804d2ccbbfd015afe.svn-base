<?php

class Signup extends Controller {

    function __construct() {
        parent::__construct();
    }

    //sign up
    public function index () {
        $this->view->render('signup/index');
    }

    //process form data
    public function run () {
        require_once 'models/signup_model.php';
        $model = new Signup_Model();
        $this->view->error = true;
        
        $name = filter_input(INPUT_POST, 'name');
        $email = filter_input(INPUT_POST, 'email', FILTER_VALIDATE_EMAIL);
        $password = filter_input(INPUT_POST, 'password');
        $password_confirm = filter_input(INPUT_POST, 'password_confirm');
        
        //check if all data is there
        if (!isset($name) 
                || !isset($email) 
                || !isset($password) 
                || !isset($password_confirm)) {
            $this->view->errorMsg = "Incomplete data";
            $this->view->render('signup/run');
            return;
        }
        
        //check that they entered a name
        if (!strlen($name)) {
            $this->view->errorMsg = "Please enter a name";
            $this->view->render('signup/run');
            return;
        }
        
        //check that passwords match
        if (strcmp($password, $password_confirm)) {
            $this->view->errorMsg = "Passwords do not match";
            $this->view->render('signup/run');
            return;
        }
        
        //check password length
        if (strlen($password) < 10) {
            $this->view->errorMsg = "Password must be at least 10 characters";
            $this->view->render('signup/run');
            return;
        }
        
        //check if email is valid
        if (!$email) {
            $this->view->errorMsg = "Invalid email";
            $this->view->render('signup/run');
            return;
        }
        
        //check if email already registered
        if (!$model->checkEmail($email)) {
            $this->view->errorMsg = "Email already exists";
            $this->view->render('signup/index');
            return;
        }
        
        $model->makeAccount($name, $email, $password);
        
        $this->view->error = false;
        $this->view->render('signup/run');
    }
}

