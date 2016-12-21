<?php

class Model {

    function __construct() {
        //echo "In the Base Model<br />";
        $this->db = new Database(); 
    }

    //returns data with account info if session_id matches an account, else returns null
    public function getAccountFromSession($session_id) {
        $query = $this->db->prepare("SELECT * FROM Signin_session NATURAL JOIN Accounts WHERE session_id = ?");
        $query->bindParam(1, $session_id);
        $query->execute();
        
        $data = $query->fetchAll();
        
        return (count($data) > 0) ? $data : null;
    }
}