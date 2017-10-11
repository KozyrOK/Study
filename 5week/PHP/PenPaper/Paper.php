<?php
   class Paper {
       private $maxSymbols;
       private $symbols;
       private $content = "";
        
       public function __construct($maxSymbols = 4096) {
            $this->maxSymbols = $maxSymbols;
            $this->symbols = 0;
        }
       
       public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
       }
       
       public function addContent($message) {
            $freeCapacity = $this->maxSymbols - $this->symbols;
            if ( $freeCapacity >= strlen($message) ) {
                $this->symbols += strlen($message);
                $this->content = $this->content . $message;
            } else {
                $this->content = $this->content . substr($message, 0, $freeCapacity);
                $this->symbols = $this->maxSymbols;
                throw new Exception("Error: Out Of Space");
            }
        }
        public function __toString() {
            return sprintf("Text: %s", $this->content);
        }
    }
?>