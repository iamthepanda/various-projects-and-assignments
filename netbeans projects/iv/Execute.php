<?php
	require('ImgHandler.php'); 
        
  class Execute {
  	private static function getDBH(){
			try {
    		$dbh = new PDO('mysql:host=sfsuswe.com;dbname=student_ivang', "ivang", "group16db");
    		$dbh -> setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_WARNING );
    		return $dbh;
    	}
    	catch (PDOException $e) {
			   print "Error!: " . $e->getMessage() . "<br/>";
			   die();
			}
  	}

    public static function save($image) {
    	$dbh = Execute::getDBH();
  		$stmt = $dbh->prepare("INSERT INTO m0Img(name, descr, little, mid, lrg) VALUES (:name, :descr, :little, :mid, :lrg)");
                        $stmt->bindParam(':name', $image->name);
			$stmt->bindParam(':descr', $image->descr);
			$stmt->bindParam(':little', $image->little);
			$stmt->bindParam(':mid', $image->mid);
			$stmt->bindParam(':lrg', $image->lrg);
			$stmt->execute();           
			return $dbh->lastInsertId();
    }

    //returns a img
    public static function get($id) {
  		$dbh = Execute::getDBH();
			$stmt = $dbh->prepare('SELECT name, descr, little, mid, lrg FROM m0Img WHERE id=:id');
			$stmt->bindParam(':id', $id);
			$stmt->execute();
			$results = $stmt->fetchAll(\PDO::FETCH_ASSOC);
			$row = $results[0];
			return new ImageHandler($row["name"], $row["descr"], $row["little"], $row["mid"], $row["lrg"]);
    }



  }
  ?>