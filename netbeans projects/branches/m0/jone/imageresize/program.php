<!DOCTYPE html>
<html>
    <head>
        <title>program</title>
    </head>
    <body>
        <?php
        $db = new mysqli("localhost", "jone", "g");

        if ($db->connect_error || !$db->select_db("student_jone")) {
            die("Database failed to connect: " . mysqli_error($db) . "<br/>");
        }

        $sql = "SELECT * FROM uploads WHERE filename='" . $_GET['i'] . "'";

        $result = mysqli_query($db, $sql);
        if (!$result) {
            die("Database query failed</body></html>");
        }

        $data = mysqli_fetch_assoc($result);

        echo "<h1>Original image:<br/><img src=\"uploads/" . $data["filename"] . "\"/><br/><hr/>";
        echo "Medium sized image:<br/><img src=\"uploads/" . $data["md_filename"] . "\"/><br/><hr/>";
        echo "Small sized image:<br/><img src=\"uploads/" . $data["sm_filename"] . "\"/><br/><hr/>";
        echo "Description:<br/></h1>" . $data["description"];
        ?>

    </body>
</html>