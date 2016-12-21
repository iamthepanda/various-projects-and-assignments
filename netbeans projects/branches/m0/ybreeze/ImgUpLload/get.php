<?php
    // connect to my database
    $server="localhost";
    $username="ybreeze";
    $password="Breeze88PuPudb";
    $dbname="student_ybreeze";
    mysql_connect($server, $username, $password) or die (mysql_error());
    mysql_select_db ($dbname) or die (mysql_error());
    
    $id = addslashes($_REQUEST['id']);
    $image = mysql_query("SELECT * FROM store WHERE id=$id");
    $image = mysql_fetch_assoc($image);
    $image = $image['image'];
    header ("Content-type: image/jpeg");
    echo $image;  
?>

