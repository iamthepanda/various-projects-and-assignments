<?php

class Database extends PDO {
    
    public function __construct() {

        try {
            $dsn = 'mysql:dbname=student_f15g05;host=localhost';
            $username = 'f15g05';
            $passwd = '648team5';
            parent::__construct($dsn, $username, $passwd);
        } catch (Exception $ex) {
            die($ex->getMessage());
        }
           
    }
    
}
