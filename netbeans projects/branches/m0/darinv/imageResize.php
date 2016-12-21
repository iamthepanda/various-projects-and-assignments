<!DOCTYPE html>
<html><head><title>image</title></head><body>
        <?php
        $db = new mysqli("localhost", "darinv", "megamanx3");

        if ($db->connect_error || !$db->select_db("student_darinv")) {
            die("Failed db connect: " . mysqli_error($db) . "<br/>");
        }


        $sql = "SELECT * FROM `image` LIMIT 0, 30 ";


        $result = mysqli_query($db, $sql);
if (!$result)
{
    die("Db query failed</body></html>");
}
     

        $data = mysqli_fetch_assoc($result);


        
        echo "<h1>regular image:<br/><img src=\"" . $data["regular"] . "\"/><br/><hr/>";
        echo "medium image:<br/><img src=\"" . $data["medium"] . "\"/><br/><hr/>";
        echo "small image:<br/><img src=\"" . $data["small"] . "\"/><br/><hr/>";
        echo "description:<br/></h1>" . $data["description"];
        ?>

    </body></html>