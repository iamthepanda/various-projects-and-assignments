<?php

class ImageUploader {
  public static function upload($file, $fileName) {
    $uploads_dir = "uploaded";
    $imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);
    ImageUploader::saveAsJPEG($file, "{$uploads_dir}/{$fileName}_lrg.jpg", 1024 , 70);
    ImageUploader::saveAsJPEG($file, "{$uploads_dir}/{$fileName}_mid.jpg", 800 , 70);
    ImageUploader::saveAsJPEG($file, "{$uploads_dir}/{$fileName}_little.jpg", 640 , 70);
  }
  function fileName($name){
    return str_replace(' ', '_', strtolower($name));
  }
  private static function saveAsJPEG($file, $outputPath, $scaledWidth ) {
      //get the extension
      $exploded = explode('.',$file["name"]);
      $ext = $exploded[count($exploded) - 1];

      //get the original dimensions
      list($originalWidth, $originalHeight) = getimagesize($file["tmp_name"]);
      $scaleRatio = $scaledWidth / $originalWidth;
      $scaledHeight = $originalHeight * $scaleRatio;

      //convert the file to jpg
      if (preg_match('/jpg|jpeg/i',$ext)){
      $originalImg = imagecreatefromjpeg($file["tmp_name"]);}
      else if (preg_match('/png/i',$ext)){
      $originalImg = imagecreatefrompng($file["tmp_name"]);}
      else if (preg_match('/gif/i',$ext)){
      $originalImg = imagecreatefromgif($file["tmp_name"]);}
      else if (preg_match('/bmp/i',$ext)){
      $originalImg = imagecreatefrombmp($file["tmp_name"]);}
      else{
      return 0;}


      //create a new image with tne new dimensions
      $image_resized = imagecreatetruecolor($scaledWidth, $scaledHeight);

      imagecopyresampled($image_resized, $originalImg, 0, 0, 0, 0, $scaledWidth, $scaledHeight, $originalWidth, $originalHeight);
      imagejpeg($image_resized, $outputPath, 100);
      return 1;
  }
  
}

?>