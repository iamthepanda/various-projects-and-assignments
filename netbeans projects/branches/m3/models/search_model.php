<?php

class Search_Model extends Model {
    
    function __construct() {
        parent::__construct();
    }
    
    public function search ($input = null) {
        try {
            $statement = $this->db->prepare("SELECT * "
                . "FROM Restaurants "
                . "WHERE name LIKE '%$input%'");        
            $statement->execute();

            $data = $statement->fetchAll();
            
            return $data;
        } catch (PDOException $ex) {
            die($ex->getMessage());
        }
    }
    
    public function getAll () {
        try {
            $statement = $this->db->prepare("SELECT * "
                .   "FROM Restaurants ");
            $statement->execute();
            
            $data = $statement->fetchAll();
            
            return $data;
        } catch (PDOException $ex) {
            die($ex->getMessage());
        }
    }
}