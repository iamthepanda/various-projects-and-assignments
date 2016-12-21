<?php

class View {

    /*
     *  This is a dynamic global array to be used for sending variables from a
     *  controller into a view. Uses the __set() and __get() Magic Methods.
     * 
     *  Example code:
     *      within a controller, before caling render():
     *          $this->view->message = 'Welcome to your homepage';
     *      within a view:
     *          echo $this->message;
     * 
     */
    private $variables = array();
    
    //public $view;
    
    function __construct() { 
        //$this->view = $this;
    }
    
    public function render($name, $noInclude = false) {     
        if ($noInclude == true) {
            require_once 'views/' . $name . '.php';
        } else {
            require_once 'views/master.php';
            require_once 'views/' . $name . '.php';
        }
        $this->$name = $name;
        //$this->test = "test from View()";
    }
    
    /*
     *  sets key/value pair dynamically for $variables
     */
    public function __set($property, $value) {
        $this->variables[ $property ] = $value;
    }
    
    /*
     *  returns the value of specified key
     */
    public function __get( $property ) {
        return $this->variables[ $property ];
    } 
 
    public function setVar($property, $value) {
        $this->variables[ $property ] = $value;     
    }
    
    public function getVar( $property ) {
        return $this->variables[ $property ];
    } 
    

}
