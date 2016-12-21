<?php

class Logout extends Controller {

    function __construct() {
        parent::__construct();
    }
    
    //log out
    public function index () {
        require_once 'models/logout_model.php';
        $model = new Logout_Model();
        
        if ($this->signedIn) {
            $model->removeSession($this->userSessionId);
            setcookie("bl", "", time() - 86400, DIRECTORY, 'sfsuswe.com');
            $this->view->render('logout/success', true);
        } else {
            $this->view->render('logout/fail');
        }
    }
}