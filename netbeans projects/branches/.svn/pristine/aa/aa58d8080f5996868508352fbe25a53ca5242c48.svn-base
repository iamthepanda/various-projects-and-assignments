
<!DOCTYPE html>
<html><head><title>image</title></head><body>
<?php
$db = new mysqli("localhost", "alnamlah", "alnamlahabdo");

if ($db->connect_error || !$db->select_db("student_alnamlah"))
{
    die("Failed db connect: " . mysqli_error($db) . "<br/>");
}

$sql = "SELECT * FROM images WHERE filename='" . $_GET['i'] . "'";

$result = mysqli_query($db, $sql);
if (!$result)
{
    die("Db query failed</body></html>");
}

$data = mysqli_fetch_assoc($result);

echo "<h1>regular image:<br/><img src=\"images/" . $data["filename"] . "\"/><br/><hr/>";
echo "medium image:<br/><img src=\"images/" . $data["filename_m"] . "\"/><br/><hr/>";
echo "small image:<br/><img src=\"images/" . $data["filename_s"] . "\"/><br/><hr/>";
echo "description:<br/></h1>" . $data["description"];
?>

</body></html>

