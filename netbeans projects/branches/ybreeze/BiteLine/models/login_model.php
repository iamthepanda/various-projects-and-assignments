<?php

class Login_Model extends Model {
    
    public function __construct() {
        parent::__construct();
    }
    
    public function run() {
        
        
        //need to be sanitized
        $username = $_POST['username'];
        $password = $_POST['password'];
        
        $query = $this->db->prepare("SELECT id "
                . "FROM Accounts "
                . "WHERE username = :username AND password = :password");
        $query->execute(array(
            ':username' => $username,
            ':password' => $password
        ));
        
        $data = $query->fetchAll();
        echo "<pre>"; var_dump($data); die;
    }
    
}
