<?php
  $error = isset($_GET['error']) ? $_GET['error'] : '';
  $name = isset($_GET['name']) ? $_GET['name'] : '';
  $descr = isset($_GET['descr']) ? $_GET['descr'] : '';
?>
<!DOCTYPE html>
<html>
  <head>
    <title>Upload An Image</title>
    
  </head>
  <body>
  
    <main>
      <div>
        <h2>Upload an Image</h2>
        <form action="uploader.php" method="post" enctype="multipart/form-data">
          <input name="name" maxlength="100" type="text" value="<?php print $name; ?>" placeholder="IMAGE NAME" required></input>
          <textarea name="descr" maxlength="500" type="text" placeholder="IMAGE DESCRIPTION" required><?php print $descr; ?></textarea>
          <input type="file" name="image" required></input>
          <input type="submit"/>
        </form>
      </div>
    </main>
    <?php
      if($error == 1){
        print "<script>window.alert('file is too large or not an image');</script>";
      }
    ?>
  </body>
</html>