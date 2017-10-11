<?php
class Identifiable {
    public static $id = 100;
    private $localId;
    
    public function __construct() {
        $this->localId = self::$id;
        self::$id += 1;
    }
    
    public function __get($name) {
        if ( property_exists($this, $name) ) {
            return $this->$name;
        }
       throw new Exception("Attribute error: attribute $name not found");
    }
    
    public function __toString() {
        return sprintf("ID number: %d", $this->localId);
       }
    }
?>