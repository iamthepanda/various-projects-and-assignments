<?php

$uploadDirectory = "uploads/";
$fileName = basename($_FILES["fileToUpload"]["name"]);
$fileWithPath = $uploadDirectory . basename($_FILES["fileToUpload"]["name"]);
$uploadOk = 1;
$imageFileType = strtolower(pathinfo($fileWithPath, PATHINFO_EXTENSION));

$fileExtensionPosition = strrpos($fileName, '.');
$fileExtensionPositionWithPath = strrpos($fileWithPath, '.');
$fileExtension = substr($fileWithPath, $fileExtensionPositionWithPath, strlen($fileWithPath) - 1);

$fileNameMedium = substr_replace($fileName, "Medium", $fileExtensionPosition, 0);
$fileNameSmall = substr_replace($fileName, "Small", $fileExtensionPosition, 0);

$destinationForMedium = substr_replace($fileWithPath, "Medium", $fileExtensionPositionWithPath, 0);
$destinationForSmall = substr_replace($fileWithPath, "Small", $fileExtensionPositionWithPath, 0);

// Check if image file is a actual image or fake image
if (isset($_POST["submit"])) {
    $check = getimagesize($_FILES["fileToUpload"]["tmp_name"]);
    if ($check !== false) {
        echo "File is an image - " . $check["mime"] . ".\r\n";
        $uploadOk = 1;
    } else {
        echo "File is not an image.\r\n";
        $uploadOk = 0;
    }
    //echo "<pre>"; var_dump($_FILES); die;
}

if (file_exists($fileWithPath)) {
    echo "Sorry, file already exists.\r\n";
    $uploadOk = 0;
}

if ($uploadOk == 0) {
    echo "Sorry, your file was not uploaded.\r\n";
} else {
    if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $fileWithPath)) {
        echo "The file " . basename($_FILES["fileToUpload"]["name"]) . " has been uploaded.\r\n";
    } else {
        echo "Sorry, there was an error uploading your file.\r\n";
    }
}

//----------resize file----------
list($width, $height) = getimagesize($fileWithPath);
$widthMedium = $width / 2;
$heightMedium = $height / 2;
$widthSmall = $width / 3;
$heightSmall = $height / 3;

$imageMedium = imagecreatetruecolor($widthMedium, $heightMedium);
$imageSmall = imagecreatetruecolor($widthSmall, $heightSmall);

if ($imageFileType == "jpeg" || $imageFileType == "jpg") {
    $image = imagecreatefromjpeg($fileWithPath);
} else if ($imageFileType == "png") {
    $image = imagecreatefrompng($fileWithPath);
} else {
    $image = imagecreatefromgif($fileWithPath);
}

imagecopyresampled($imageMedium, $image, 0, 0, 0, 0, $widthMedium, $heightMedium, $width, $height);
imagecopyresampled($imageSmall, $image, 0, 0, 0, 0, $widthSmall, $heightSmall, $width, $height);

if ($imageFileType == "jpeg" || $imageFileType == "jpg") {
    imagejpeg($imageMedium, $destinationForMedium);
    imagejpeg($imageSmall, $destinationForSmall);
} else if ($imageFileType == "png") {
    imagepng($imageMedium, $destinationForMedium);
    imagepng($imageSmall, $destinationForSmall);
} else {
    imagegif($imageMedium, $destinationForMedium);
    imagegif($imageSmall, $destinationForSmall);
}

//----------db stuff----------
$db = new mysqli("localhost", "pedersen", "steve85");

if ($db->connect_error || !$db->select_db("student_pedersen")) {
    die("Failed db connect: " . mysqli_error($db) . "<br/></body></html>");
}

$statement = $db->prepare("INSERT INTO uploads (filename, filename_s, filename_m, description) "
        . "VALUES (?, ?, ?, ?)");
$statement->bind_param("ssss", $fileName, $fileNameSmall, $fileNameMedium, $_POST["fileDescription"]);

if (!$statement->execute()) {
    unlink($fileWithPath);
    unlink($destinationForMedium);
    unlink($destinationForSmall);
    die("Db query failed: " . mysqli_error($db) . "<br/>");
}

echo "File uploaded! Redirecting...<br/>";
echo "<script type=\"text/javascript\">"
 . "setTimeout(function(){"
 . "window.location.href='image.php?i="
 . $fileName . "';"
 . "}, 3000);"
 . "</script>";
die("</body></html>");

?>