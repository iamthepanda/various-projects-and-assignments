<!DOCTYPE html>
<html>
    <head>
        <title> Upload your image. </title>
    </head>
    <body>
    <form action="index.php" method="post" enctype="multipart/form-data">
        Image upload:
        <br /><input type="file" name="image">
        <br />File Name: <input type="text" name="fn">
        <br />Description: <input type="text" name="dp">
        <br /><input type="submit" value="upload">
    </form>
        <?php
            // connect to my database
            $server="localhost";
            $username="ybreeze";
            $password="Breeze88PuPudb";
            $dbname="student_ybreeze";
            mysql_connect($server, $username, $password) or die (mysql_error());
            mysql_select_db ($dbname) or die (mysql_error());
            
            // file properites
            $file = $_FILES['image']['tmp_name'];
            
            // no file selected.
            if (!isset($file)) {
                echo "Please upload an image.";
            }
            else {
                $image=addslashes(file_get_contents($_FILES['image']['tmp_name']));
                $image_name=addslashes($_FILES['image']['name']);
                $image_size=  getimagesize($_FILES['image']['tmp_name']);
                
                if ($image_size==FALSE) {
                    echo "Only image is allowed.";
                }
                else {
                    list($width, $height)=  getimagesize($_FILES['image']['tmp_name']);
                    $thumb = imagecreatetruecolor (($width)/2, ($height)/2);
                    // insert failed 
                    if (!$insert=mysql_query("INSERT INTO store VALUES ('', '$image_name', '$image')")) {
                        echo "Problem uploading image.";
                    }
                    // insert succeeded, file in my database.
                    else {
                        $insert=mysql_query("INSERT INTO store VALUES ('', '$image_name', '$thumb')");
                        $lastid = mysql_insert_id();
                        echo "Image uploaded.<p />Your image:<p /><img src=get.php?id=$lastid>";
                    }
                }
            }  
        ?>
    </body>
</html>
