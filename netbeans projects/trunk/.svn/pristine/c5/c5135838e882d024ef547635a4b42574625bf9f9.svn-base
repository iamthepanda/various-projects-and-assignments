<?php

class Search extends Controller {
    
    public function __construct() {
        parent::__construct();
    }
    
    public function index () {
        if (isset($_GET['query'])) {
            $query = $_GET['query'];
        }
        
        /* Debug sec start */
        if ($query != null) {
            echo "<br><strong>Search for: <i>$query</i></strong><br />";
            echo "<br />";
        }
        else {
            echo "<br><strong>Please enter search keywords.</strong><br />";
            echo "<br />";
        }
        /* Debug sec end */
        
        //echo "<pre>"; var_dump($query); die;
        require_once 'models/search_model.php';
        $model = new Search_Model();
        
        //$results = $model->search($query);
        $results=$model->getRtsByNameOrNbh($query);
        //echo "<pre>"; var_dump($results[0]); die;
        
        /* Debug sec start */
        if (empty($results)) {
            echo "<strong>0 result found ! Try again !</strong><br />";
            echo "<br />";  
        }
        /* Debug sec start */
        
        $this->view->searchResults = $results;
        
        $this->view->render('search/index');
    }
    
    public function search ($query = null) {
        
    }
}

