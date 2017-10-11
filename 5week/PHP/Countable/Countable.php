<?php
    class MyCountable {
        public static $globalCounter = 0;
        private $counter;
        public function __construct(){
            self::$globalCounter += 1;
            $this->counter = self::$globalCounter;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function __toString() {
            return sprintf("Countable number: %d", $this->counter);
        }
    }
?>