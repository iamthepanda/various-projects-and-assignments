<?php

class Login_Model extends Model {
    
    public function __construct() {
        parent::__construct();
    }
    
    public function run($email, $password) {
        $query = $this->db->prepare("SELECT realname, ac_id "
                . "FROM Accounts "
                . "WHERE email = :email AND password = :password");
        $query->execute(array(
            ':email' => $email,
            ':password' => $password
        ));
        
        $data = $query->fetchAll();
        
        return $data;
    }
    
    public function addSession($ac_id, $session_id) {
        $query = $this->db->prepare("INSERT INTO Signin_session (ac_id, session_id) "
                . "VALUES (:ac_id, :session_id)");
        $query->execute(array(
            ':ac_id' => $ac_id,
            ':session_id' => $session_id
        ));
    }
    
}
