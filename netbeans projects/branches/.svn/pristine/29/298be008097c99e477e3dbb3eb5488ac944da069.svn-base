<!DOCTYPE html>
<html><head><title>uploading...</title></head><body>
        <?php
        $file = strtolower($_POST["fileName"]);
        $destination = "uploads/" . $file;

//----------check image type----------
        $imageNameType = strtolower(pathinfo($destination, PATHINFO_EXTENSION));
        $imageType = strtolower(pathinfo($_FILES["fileToUpload"]["name"], PATHINFO_EXTENSION));
        $fileName = strtolower(pathinfo($_POST["fileName"], PATHINFO_FILENAME));

        $md_destination =  "uploads/" . "md_" . $fileName . "." . $imageType;
        $sm_destination =  "uploads/" . "sm_" . $fileName . "." . $imageType;

        $md_file = "md_" . $fileName . "." . $imageType;
        $sm_file = "sm_" . $fileName . "." . $imageType;

        if ($imageNameType !== $imageType) {
            die("You must enter extension type with filename.<br/></body></html>");
        }

        if ($imageType != "jpg" && $imageType != "jpeg" && $imageType != "gif" && $imageType != "png") {
            die("Please use supported file type: jpg, jpeg, gif, png.<br/></body></html>");
        }


//----------make sure it's an image----------
        if (!getimagesize($_FILES["fileToUpload"]["tmp_name"])) {
            die("File is not an image. Choose an image.<br/></body></html>");
        }


//----------check if file exists----------
        if (file_exists($destination)) {
            die("Filename already exists. Choose different filename.<br/></body></html>");
        }


//----------limit the file size----------
        if ($_FILES["fileToUpload"]["size"] > 50000000) {
            die("File is too large (50mb max)<br/></body></html>");
        }


//----------upload the file---------
        if (!move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $destination)) {
            die("Error uploading file. Try again.<br/></body></html>");
        }

//----------resize file----------
        list($width, $height) = getimagesize($destination);
        $md_width = $width / 2;
        $md_height = $height / 2;
        $sm_width = $width / 3;
        $sm_height = $height / 3;

        $md_img = imagecreatetruecolor($md_width, $md_height);
        $sm_img = imagecreatetruecolor($sm_width, $sm_height);

        if ($imageType == "jpeg" || $imageType == "jpg") {
            $img = imagecreatefromjpeg($destination);
        } else if ($imageType == "png") {
            $img = imagecreatefrompng($destination);
        } else {
            $img = imagecreatefromgif($destination);
        }

        imagecopyresampled($md_img, $img, 0, 0, 0, 0, $md_width, $md_height, $width, $height);
        imagecopyresampled($sm_img, $img, 0, 0, 0, 0, $sm_width, $sm_height, $width, $height);

        if ($imageType == "jpeg" || $imageType == "jpg") {
            imagejpeg($md_img, $md_destination);
            imagejpeg($sm_img, $sm_destination);
        } else if ($imageType == "png") {
            imagepng($md_img, $md_destination);
            imagepng($sm_img, $sm_destination);
        } else {
            imagegif($md_img, $md_destination);
            imagegif($sm_img, $sm_destination);
        }


//----------db stuff----------
        $db = new mysqli("localhost", "jone", "g");

        if ($db->connect_error || !$db->select_db("student_jone")) {
            die("Failed to connect to Database: " . mysqli_error($db) . "<br/></body></html>");
        }

        if (strlen($_POST["fileName"]) > 62) {
            die("The file name is too long (255 char max)<br/></body></html>");
        }

        if (strlen($_POST["fileDescription"]) > 256) {
            die("The description is too long (255 char max)</br></body></html>");
        }

        $statement = $db->prepare("INSERT INTO uploads (filename, sm_filename, md_filename, description) "
                . "VALUES (?, ?, ?, ?)");
        $statement->bind_param("ssss", $file, $sm_file, $md_file, $_POST["fileDescription"]);

        if (!$statement->execute()) {
            unlink($destination);
            unlink($md_destination);
            unlink($sm_destination);
            die("Database query failed: " . mysqli_error($db) . "<br/>");
        }

        echo "Your image has been uploaded! Loading...<br/>";
        echo "<script type=\"text/javascript\">"
        . "setTimeout(function(){"
        . "window.location.href='program.php?i="
        . $file . "';"
        . "}, 3000);"
        . "</script>";
        die("</body></html>");
        ?>