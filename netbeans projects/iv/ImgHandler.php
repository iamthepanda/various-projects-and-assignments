<?php
	class ImageHandler{
		public $id;
		public $name;
		public $descr;
		public $little;
		public $mid;
		public $lrg;
		public function __construct($name, $descr, $little, $mid, $lrg) {
			$this->name = $name;
			$this->descr = $descr;
			$this->little = $little;
			$this->mid = $mid;
			$this->lrg = $lrg;
		}
	}
?>