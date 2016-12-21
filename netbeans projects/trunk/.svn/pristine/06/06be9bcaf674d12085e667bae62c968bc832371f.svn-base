<?php

class Search extends Controller {
    
    public function __construct() {
        parent::__construct();
    }
    
    public function index () {
        if (isset($_GET['query'])) {
            $query = $_GET['query'];
        }
        
        //echo "<pre>"; var_dump($query); die;
        require_once 'models/search_model.php';
        $model = new Search_Model();
        
        $results = $model->search($query);
        //echo "<pre>"; var_dump($results[0]); die;
        $this->view->searchResultsName = $results[0]["name"];
        $this->view->searchResultsDesc = $results[0]["description"];
        $this->view->render('search/index');
    }
    
    public function search ($query = null) {
        
    }
}

