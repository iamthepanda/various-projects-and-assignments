<?php
        require('Execute.php');
	require('Upload.php');
	
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
		$error = validate();
    if($error != ""){
    	header("Location: new.php?error=".$error."&name=".$_POST["name"]."&descr=".$_POST["descr"]);
    } else {
    	
            ImageUploader::upload($_FILES["image"],$_POST["name"]);

	    
			$image = new ImageHandler($_POST["name"], $_POST["descr"], fileName($_POST["name"]."_little.jpg"), 
                                fileName($_POST["name"]."_mid.jpg"), fileName($_POST["name"]."_lrg.jpg"));
			$id = Execute::save($image);
                        
	    
			header("Location: Meta.php?id=".$id);
    }
	}
	function fileName($name){
		return str_replace(' ', '_', strtolower($name));
	}
	function validate(){
    return ($_FILES["image"]["size"] >= 2000000) || ($_FILES["image"]["size"] == 0);
  }

?>
