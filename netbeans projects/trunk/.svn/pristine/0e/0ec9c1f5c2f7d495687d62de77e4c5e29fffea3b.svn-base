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
    
        /** Search algorithm : search by restaurant name / neighborhood name / both. */
    public function getRtsByNameOrNbh($searchq) {
        try {
            $str=explode(" ", $searchq);    // Divide search string separated by spaces into keywords.
            $items = array();               // Database items matches the keywords.
            foreach($str as $key) {         // Found database items matches each keyword.
                $query="(SELECT *
                         FROM Restaurants, Neighborhoods, Rt_Nbh
                         WHERE (name LIKE ?)
                               AND (Rt_Nbh.rt_id = Restaurants.rt_id AND Rt_Nbh.nbh_id = Neighborhoods.nbh_id))
                         UNION
                         (SELECT *
                         FROM Restaurants, Neighborhoods, Rt_Nbh
                         WHERE (nbh_name LIKE ?)
                               AND (Rt_Nbh.rt_id = Restaurants.rt_id AND Rt_Nbh.nbh_id = Neighborhoods.nbh_id))";
                $params = array("%$key%", "%$key%");
                $stmt = $this->db->prepare($query);
                $stmt->execute($params);
                $data=$stmt->fetchAll(PDO::FETCH_ASSOC);  
                foreach($data as $row) {           // Check if a database item already existed.
                    if (!in_array($row, $items)) {    // If not existed, put it into the collection.
                        array_push($items, $row);
                    }
                }
            }
            
            // Debug purpose: display items found.
            /*
            if (empty($items)) {
                echo "0 result is found! Try search again!<br />";
            }else{ 
                echo "Search for: $searchq<br />";
                foreach($items as $item) {
                    // echo "<br />Restaurant Name: ".$item['name']."<br />Neighborhood: ".$item['nbh_name']."<br />";
                    // print_r($item);
                }    
            } 
            */
            
            return $items;
        } catch (PDOException $ex) {
            die($ex->getMessage());
        }
    }
}