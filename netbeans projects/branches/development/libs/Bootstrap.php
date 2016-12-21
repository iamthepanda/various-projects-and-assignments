<?php

class Bootstrap {

    function __construct() {
        
        $url = isset($_GET['url']) ? isset($_GET['url']) : null;
        $url = rtrim($url, '/');
        $url = explode('/', $url);

        print_r($url);
        
        // allows for index to be called, with or without specifying /index.php
        if (empty($url[0])) {
            require 'controllers/index.php';
            $controller = new Index();
            return false;
        }

        // look into not having 'controllers/' be hard coded.
        // should be an option in a config.ini file
        $file = 'controllers/' . $url[0] . '.php';
        if (file_exists($file)) {
            require $file;
        } else {
            require '/controllers/error.php';
            $controller = new Error();           
            return false;
        }
        
        $controller = new $url[0];

        // controller->function(param)
        if (isset($url[2])) {
        $controller->{$url[2]}($url[2]);
        } else {
            // controller->function()
            if (isset($url[1])) {
                $controller->{$url[1]}();
            }
        }
        
    }
    
    private function callMethods($controller, $url) {
        if(isset($url[2]) && method_exists($controller, $url[1])){
            $controller->{$url[1]}($url[2]);
        } else if(isset($url[1]) && method_exists($controller, $url[1])) {
            $controller->{$url[1]}();
        } else {
            $controller->index();
        }
    }

}
