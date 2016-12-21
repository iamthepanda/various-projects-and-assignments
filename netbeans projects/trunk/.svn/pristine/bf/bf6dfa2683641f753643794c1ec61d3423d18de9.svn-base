<?php

// Base Controller
class Controller {

    protected $signedIn = false;
    protected $userAccountId = null;
    protected $userAccountName = null;
    protected $userSessionId = null;
    
    function __construct() {
        $this->view = new View(); 
       
    }
    
    public function loadModel($name) {
        $path = 'models/' .$name. '_model.php';
        
        if (file_exists($path)) {
            require 'models/' .$name. '_model.php';
            
            $modelName = $name . '_Model';
            $this->model = new $modelName();
        }
    }

    //checks if a valid session exists and sets session variables appropriately
    public function handleSession() {
        $model = new Model();
        if (isset($_COOKIE['bl'])) {
            $data = $model->getAccountFromSession($_COOKIE['bl']);
            
            if ($data != null) {
                $this->signedIn = true;
                $this->userAccountId = $data[0]['ac_id'];
                $this->userAccountName = $data[0]['realname'];
                $this->userSessionId = $_COOKIE['bl'];
            } else {
                //session id not valid, expire cookie
                setcookie("bl", "", time() - 86400, DIRECTORY, 'sfsuswe.com');
            }
        }
        
        $this->view->signedIn = $this->signedIn;
        $this->view->userAccountName = $this->userAccountName;
    }
}