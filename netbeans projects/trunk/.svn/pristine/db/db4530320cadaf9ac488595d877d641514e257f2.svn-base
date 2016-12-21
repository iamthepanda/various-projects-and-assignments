<?php

class Bootstrap {

    public $query;

    function __construct() {
        //echo "<pre>"; var_dump($_GET['query']); die;

        $url = isset($_GET['url']) ? $_GET['url'] : null;
        $url = rtrim($url, '/');
        $url = explode('/', $url);

        //echo "<pre>"; var_dump($url); echo "</pre>";
        // allows for index to be called, with or without specifying /index.php
        if (isset($url[0]) && $url[0] == null) {
            require_once 'controllers/index.php';
            $controller = new Index();
            $controller->handleSession();
            $controller->index();
            return false;
        }

        // look into not having 'controllers/' be hard coded.
        // should be an option in a config.ini file
        $file = 'controllers/' . $url[0] . '.php';
        if (file_exists($file)) {
            require $file;
        } else {
            require 'controllers/error.php';
            $controller = new Error();
            return false;
        }

        $controller = new $url[0];
        $controller->loadModel($url[0]);
        $controller->handleSession();


        switch (count($url)) {
            case 5:
                $controller->{$url[1]}($url[2], $url[3], $url[4]);
                break;
            case 4:
                $controller->{$url[1]}($url[2], $url[3]);
                break;
            case 3:
                $controller->{$url[1]}($url[2]);
                break;
            case 2:
                $controller->{$url[1]}();
                break;
            default:
                $controller->index();
                break;
        }
    }

}
