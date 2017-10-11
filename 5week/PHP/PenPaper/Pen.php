<?php
    include_once "Paper.php";

    class Pen {
        private $inkAmount;
        private $inkCapacity;
        public function __construct($inkCapacity=4096) {
            $this->inkCapacity = $inkCapacity;
            $this->inkAmount = $inkCapacity;
            $this->refill();
        }
        
        public function __get($name) {
             if ( property_exists($this, $name) ) {
                 return $this->$name;
             }
             throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function write( Paper &$paper, $message ){
            $inkNeeded = intval(strlen($message));
    
            if( $this->inkAmount < $inkNeeded ) {
                $symbols = $this->inkAmount;
                $subStr = substr ($message, 0, $symbols);
         
                try {
                    $paper->addContent($subStr);
                } catch ( Exception  $e ) {
                    throw $e;
                }
                $this->inkAmount = 0;
                throw new Exception("Error: Out Of Ink");
            }
    
            try {
                $paper->addContent($message);
            } catch ( Exception  $e ) {
                throw $e;
            }
            $this->inkAmount -= $inkNeeded; 
        }        
        
        public function refill() {
            $this->inkAmount = $this->inkCapacity;
        }
    }
?>