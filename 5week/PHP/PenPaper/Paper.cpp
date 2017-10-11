#include <iostream>
#include "Paper.h"

Paper::Paper(int maxSymbols) { 
    this->maxSymbols = maxSymbols;
    this->symbols = 0;
    this->content = "";
}

Paper::~Paper() {}

int Paper::getMaxSymbols() const {
    return this->maxSymbols;
}

int Paper::getSymbols() const {
    return this->symbols;
}

void Paper::addContent(const std::string& message) {
    if (this->symbols == this->maxSymbols) {
        throw OutOfSpace ();
    } else if ((this->maxSymbols) - (this->symbols) < message.size()) {
        size_t lengthMessage = (this->maxSymbols) - (this->symbols);
        this->content += message.substr(0, lengthMessage);
        this->symbols += lengthMessage;
    } else {
        this->content += message;
        this->symbols += message.size();
    }
}

void Paper::show() const {
    std::cout << this->content << std::endl;
}

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