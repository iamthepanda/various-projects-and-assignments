<?php

class Image_Model extends Model {
    
    public function __construct() {
        parent::__construct();
    }
    
    public function get($image_id) {
        $query = $this->db->prepare("SELECT image FROM Images WHERE img_id = ?");
        $query->bindParam(1, $image_id);
        $query->execute();
        
        $data = $query->fetchAll();
        
        return $data[0]["image"];
    }
    
    public function getrt($rt_id) {
        $query = $this->db->prepare("SELECT img_id FROM Rt_Image WHERE rt_id = ?");
        $query->bindParam(1, $rt_id);
        $query->execute();
        
        $data = $query->fetchAll();
        
        $query = $this->db->prepare("SELECT image FROM Images WHERE img_id = ?");
        $query->bindParam(1, $data[0]["img_id"]);
        $query->execute();
        
        $data = $query->fetchAll();
        
        return $data[0]["image"];
    }
}
