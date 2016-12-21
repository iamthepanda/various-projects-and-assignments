<!DOCTYPE html>
<html><head><title>uploading...</title></head><body>
        <?php
        $fileReg = strtolower($_POST["fileName"]);
        $destinationReg = "images/" . $fileReg;
        $imageNameType = strtolower(pathinfo($destinationReg, PATHINFO_EXTENSION));


        $fileType = strtolower(pathinfo($_FILES["imageUpload"]["name"], PATHINFO_EXTENSION));
        $fileName = strtolower(pathinfo($_POST["fileName"], PATHINFO_FILENAME));


        $destinationMed = "images/" . $fileName . "Med." . $fileType;
        $destinationSm = "images/" . $fileName . "Sm." . $fileType;
        $fileMed = $fileName . "Med." . $fileType;
        $fileSm = $fileName . "Sm." . $fileType;




        echo "<pre>";
        var_dump($destinationMed);
        echo "<pre>";
        var_dump($destinationSm);
        echo "<pre>";
        var_dump($_FILES["imageUpload"]["name"]);

        if ($imageNameType !== $fileType) {
            die("Image extension types do not match<br/></body></html>");
        }

        if ($fileType != "jpg" && $fileType != "jpeg" && $fileType != "gif" && $fileType != "png") {
            die("Unsupported file type<br/></body></html>");
        }


//----------make sure it's an image----------
        if (!getimagesize($_FILES["imageUpload"]["tmp_name"])) {
            die("File is not an image<br/></body></html>");
        }


//----------check if file exists----------
        if (file_exists($destinationReg)) {
            die("Filename already exists<br/></body></html>");
        }


//----------limit the file size----------
        if ($_FILES["imageUpload"]["size"] > 50000000) {
            die("File is too large (50mb max)<br/></body></html>");
        }


//----------upload the file---------
        if (!move_uploaded_file($_FILES["imageUpload"]["tmp_name"], $destinationReg)) {
            die("Error uploading file<br/></body></html>");
        }


//----------resize file----------
        list($width, $height) = getimagesize($destinationReg);
        $widthMed = $width / 2;
        $heightMed = $height / 2;
        $widthSm = $width / 3;
        $heightSm = $height / 3;

        $imgMed = imagecreatetruecolor($widthMed, $heightMed);
        $imgSm = imagecreatetruecolor($widthSm, $heightSm);

        if ($fileType == "jpeg" || $fileType == "jpg") {
            $img = imagecreatefromjpeg($destinationReg);
        } else if ($fileType == "png") {
            $img = imagecreatefrompng($destinationReg);
        } else {
            $img = imagecreatefromgif($destinationReg);
        }

        imagecopyresampled($imgMed, $img, 0, 0, 0, 0, $widthMed, $heightMed, $width, $height);
        imagecopyresampled($imgSm, $img, 0, 0, 0, 0, $widthSm, $heightSm, $width, $height);

        if ($fileType == "jpeg" || $fileType == "jpg") {
            imagejpeg($imgMed, $destinationMed);
            imagejpeg($imgSm, $destinationSm);
        } else if ($fileType == "png") {
            imagepng($imgMed, $destinationMed);
            imagepng($imgSm, $destinationSm);
        } else {
            imagegif($imgMed, $destinationMed);
            imagegif($imgSm, $destinationSm);
        }


//----------db stuff----------
        $db = new mysqli("localhost", "darinv", "megamanx3");

        if ($db->connect_error || !$db->select_db("student_darinv")) {
            die("Failed db connect: " . mysqli_error($db) . "<br/></body></html>");
        }

        if (strlen($_POST["fileName"]) > 62) {
            die("File name too long (62 char max)<br/></body></html>");
        }

        if (strlen($_POST["description"]) > 256) {
            die("Description too long (256 char max)</br></body></html>");
        }


        $statement = $db->prepare("INSERT INTO image (regular, medium, small, description) "
                . "VALUES (?, ?, ?, ?)");
        var_dump($statement);
        $statement->bind_param("ssss", $destinationReg, $destinationMed, $destinationSm, $_POST["description"]);

        if (!$statement->execute()) {
            unlink($destinationReg);
            unlink($destinationMed);
            unlink($destinationSm);
            die("Db query failed: " . mysqli_error($db) . "<br/>");
        }

        /* $sql = "INSERT INTO images (filename, filenameSm, filenameMed, description) "
          . "VALUES ('" . $fileReg . "', "
          . "'" . $fileName
          . "Sm" . "." . $fileType . "', "
          . "'" . $fileName
          . "Med" . "." . $fileType . "', "
          . "'" . $_POST["description"] . "')";

          if (!mysqli_query($db, $sql))
          {
          unlink($destinationReg);
          unlink($destinationMed);
          unlink($destinationSm);
          die("Db query failed: " . mysqli_error($db) . "<br/>");
          } */

        echo "File uploaded! Redirecting...<br/>";
        echo "<script type=\"text/javascript\">"
        . "setTimeout(function(){"
        . "window.location.href='imageResize.php?i="
        . $fileReg . "';"
        . "}, 3000);"
        . "</script>";
        die("</body></html>");
        ?>