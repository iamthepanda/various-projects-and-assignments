<?php

class Signup_Model extends Model {
    
    public function __construct() {
        parent::__construct();
    }
    
    //returns false if email exists, else true
    public function checkEmail($email) {
        $query = $this->db->prepare("SELECT * FROM Accounts WHERE email = ?");
        $query->bindParam(1, $email);
        $query->execute();
        
        $data = $query->fetchAll();
        
        return (count($data) > 0) ? false : true;
    }
    
    //adds the account to the db
    public function makeAccount($name, $email, $password) {
        $query = $this->db->prepare("INSERT INTO Accounts (realname, email, password) "
                                    . "VALUES (:name, :email, :password)");
        $query->bindParam(':name', $name);
        $query->bindParam(':email', $email);
        $query->bindParam(':password', $password);
        $query->execute();
    }
}