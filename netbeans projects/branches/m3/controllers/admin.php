<?php

/*
 *  Handles approving restaurants by sending all restaurants to the view.
 *  Filtering restaurants can be done in the view as follows:
 *      foreach ($this->restaurants as $restaurant) {
 *          if ($restaurant['approve_status']) {
 *              // display approved restaurants, etc.
 *          }
 *      }
 */
class Admin extends Controller {
    
    function __construct() {
        require_once 'models/search_model.php';
        parent::__construct();
    }
    
    public function index () { 
        
        $this->view->render('admin/index');
    }
    
    public function approved () {
        $rest_mod = new Search_Model();
        $this->view->restaurants = $rest_mod->getAll();
        
        $this->view->render('admin/approved_restaurants');
    }
    
    public function pending () {
        $rest_mod = new Search_Model();
        $this->view->restaurants = $rest_mod->getAll();
        
        $this->view->render('admin/pending_restaurants');
    }
    
    // used to edit a restaurant
    public function restaurant ($id) {
        $rest_mod = new Search_Model();
        $this->view->restaurant = $rest_mod->search($id);
        
        $this->view->render('admin/restaurant');
    }
    
    // used to approve a pending restaurant
    public function approve ($id) {
        $rest_mod = new Search_Model();
        $this->view->restaurant = $rest_mod->search($id);
        
        $this->view->render('admin/restaurant');
    }
    
}