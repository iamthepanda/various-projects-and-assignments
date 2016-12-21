<?php

class Logout_Model extends Model {
    
    public function __construct() {
        parent::__construct();
    }
    
    public function removeSession($session_id) {
        $query = $this->db->prepare("DELETE FROM Signin_session
                WHERE session_id = ?");
        $query->bindParam(1, $session_id);
        $query->execute();
    }
}