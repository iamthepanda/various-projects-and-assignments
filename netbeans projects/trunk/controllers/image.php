<?php

class Image extends Controller {

    function __construct() {
        parent::__construct();
    }
    
    public function index () {
        
    }
    
    //get from img_id
    public function get ($image_id) {
        require_once 'models/image_model.php';
        $model = new Image_Model();
        
        $image = $model->get($image_id);
        $this->view->image = $image;
        $this->view->render('image/index', true);
    }
    
    //get from rt_id
    public function getrt ($rt_id) {
        require_once 'models/image_model.php';
        $model = new Image_Model();
        
        $image = $model->getrt($rt_id);
        $this->view->image = $image;
        $this->view->render('image/index', true);
    }
}