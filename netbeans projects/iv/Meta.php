<?php
  require('Execute.php');
  $image = Execute::get($_GET['id']);
?>
<!DOCTYPE html>
<html>
  <head>
    <title>Milestone</title>

  </head>
  <body>
    <main>
      <h2><?php print $image->name ?></h2>
      <p><?php print $image->descr?></p>
      <img src="<?php print 'uploaded/'.$image->lrg ?>"/>
      <img src="<?php print 'uploaded/'.$image->mid ?>"/>
      <img src="<?php print 'uploaded/'.$image->little ?>"/>
    </main>
  </body>
