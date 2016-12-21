<!DOCTYPE html>
<html>
    <head>
        <title>image</title>
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css">
    </head>
<body>  
<?php
$db = new mysqli("localhost", "pedersen", "steve85");

if ($db->connect_error || !$db->select_db("student_pedersen"))
{
    die("Failed db connect: " . mysqli_error($db) . "<br/>");
}

$sql = "SELECT * FROM uploads WHERE filename='" . $_GET['i'] . "'";

$result = mysqli_query($db, $sql);
if (!$result)
{
    die("Db query failed</body></html>");
}

$data = mysqli_fetch_assoc($result);

echo "<h1>regular image:<br/><img src=\"uploads/" . $data["filename"] . "\"/><br/><hr/>";
echo "medium image:<br/><img src=\"uploads/" . $data["filename_m"] . "\"/><br/><hr/>";
echo "small image:<br/><img src=\"uploads/" . $data["filename_s"] . "\"/><br/><hr/>";
echo "description:<br/></h1>" . $data["description"];
?>

</body>
</html>