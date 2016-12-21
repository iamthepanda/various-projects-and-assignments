<!DOCTYPE html>
<html><head><title>uploading...</title></head><body>
<?php
$file = strtolower($_POST["fileName"]);
$destination = "images/" . $file;

//----------check image type----------
$imageNameType = strtolower(pathinfo($destination, PATHINFO_EXTENSION));
$imageType = strtolower(pathinfo($_FILES["fileToUpload"]["name"], PATHINFO_EXTENSION));
$fileName = strtolower(pathinfo($_POST["fileName"], PATHINFO_FILENAME));

$destination_m = "images/" . $fileName . "_m." . $imageType;
$destination_s = "images/" . $fileName . "_s." . $imageType;

$file_m = $fileName . "_m." . $imageType;
$file_s = $fileName . "_s." . $imageType;

if ($imageNameType !== $imageType)
{
    die("Please name your image extension sanely<br/></body></html>");
}

if ($imageType != "jpg" && $imageType != "jpeg" 
        && $imageType != "gif" && $imageType != "png")
{
    die("Please use supported file type<br/></body></html>");
}


//----------make sure it's an image----------
if (!getimagesize($_FILES["fileToUpload"]["tmp_name"]))
{
    die("File is not an image<br/></body></html>");
}


//----------check if file exists----------
if (file_exists($destination))
{
    die("Filename already exists<br/></body></html>");
}


//----------limit the file size----------
if ($_FILES["fileToUpload"]["size"] > 50000000)
{
    die("File is too large (50mb max)<br/></body></html>");
}


//----------upload the file---------
if (!move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $destination))
{
    die("Error uploading file<br/></body></html>");
}


//----------resize file----------
list($width, $height) = getimagesize($destination);
$width_m = $width/2;
$height_m = $height/2;
$width_s = $width/3;
$height_s = $height/3;

$img_m = imagecreatetruecolor($width_m, $height_m);
$img_s = imagecreatetruecolor($width_s, $height_s);

if ($imageType == "jpeg" || $imageType == "jpg")
{
    $img = imagecreatefromjpeg($destination);
}
else if ($imageType == "png")
{
    $img = imagecreatefrompng($destination);
}
else
{
    $img = imagecreatefromgif($destination);
}

imagecopyresampled($img_m, $img, 0, 0, 0, 0, $width_m, $height_m, $width, $height);
imagecopyresampled($img_s, $img, 0, 0, 0, 0, $width_s, $height_s, $width, $height);

if ($imageType == "jpeg" || $imageType == "jpg")
{
    imagejpeg($img_m, $destination_m);
    imagejpeg($img_s, $destination_s);
}
else if ($imageType == "png")
{
    imagepng($img_m, $destination_m);
    imagepng($img_s, $destination_s);
}
else
{
    imagegif($img_m, $destination_m);
    imagegif($img_s, $destination_s);
}


//----------db stuff----------
$db = new mysqli("localhost", "alnamlah", "alnamlahabdo");

if ($db->connect_error || !$db->select_db("student_alnamlah"))
{
    die("Failed db connect: " . mysqli_error($db) . "<br/></body></html>");
}

if (strlen($_POST["fileName"]) > 62)
{
    die("File name too long (62 char max)<br/></body></html>");
}

if (strlen($_POST["fileDesc"]) > 256)
{
    die("Description too long (256 char max)</br></body></html>");
}

$statement = $db->prepare("INSERT INTO images (filename, filename_s, filename_m, description) "
        . "VALUES (?, ?, ?, ?)");
$statement->bind_param("ssss", $file, $file_s, 
        $file_m, $_POST["fileDesc"]);

if (!$statement->execute())
{
    unlink($destination);
    unlink($destination_m);
    unlink($destination_s);
    die("Db query failed: " . mysqli_error($db) . "<br/>");
}

echo "File uploaded! Redirecting...<br/>";
echo "<script type=\"text/javascript\">"
. "setTimeout(function(){"
        . "window.location.href='image.php?i="
        . $file . "';"
        . "}, 3000);"
        . "</script>";
die("</body></html>");

?>