#include <iostream>
#include "Pen.h"

Pen::Pen(int inkCapacity) {
    this->inkAmount = inkCapacity;
    this->inkCapacity = inkCapacity;
}

Pen::~Pen() { }

int Pen::getInkAmount() const {
    return this->inkAmount;
}

int Pen::getInkCapacity() const {
    return this->inkCapacity;
}

void Pen::write(Paper& paper, const std::string& message) {
    if (this->inkAmount == 0) {
        throw OutOfInk();
    } else if (message.size() > this->inkAmount) {
        std::string shotMessage = message.substr(0, this->inkAmount);
        paper.addContent(shotMessage);
        this->inkAmount = 0;
    } else {
        paper.addContent(message);
        this->inkAmount -= message.size();
    }
}

void Pen::refill() {
    this->inkAmount = this->inkCapacity;
}



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
    
    $pen = new Pen(300);
    $paper = new Paper(50);
    $pen->write($paper, "------ Hello, Programmer ------ ");
    echo $paper . PHP_EOL;
    $pen->write($paper, "Hello , world!");
    echo $paper . PHP_EOL;
    $pen->write($paper, "222Hello , world!");
    echo $paper . PHP_EOL;
 
?>