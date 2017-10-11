<?php
class Complex {
    private $real, $imaginary;
    private function validate($value) {
        if ( is_numeric($value) ) {
            return $value;
        }
            throw new Exception("Invalid parametrs");
    }
    
    public function __construct($real=0, $imaginary=0) {
        $this->real = $this->validate($real);
        $this->imaginary = $this->validate($imaginary);
        }
    
    public function __get($name) {
        return $this->$name;
    }
    
    function sum( Complex $b) {
    $this->real = $this->real + $b->real;
    $this->imaginary = $this->imaginary + $b->imaginary;
    }

    function diff( Complex $b) {
    $this->real = $this->real - $b->real;
    $this->imaginary = $this->imaginary - $b->imaginary;
    }

    function mult( Complex $b) {
    $this->real = $this->real * $b->real;
    $this->imaginary = $this->imaginary * $b->imaginary;
    }

    public function __toString() {
    if ( $this->imaginary > 0) {
        return sprintf("(%g, +%g)", $this->real, $this->imaginary);
    }
        return sprintf("(%g, %g)", $this->real, $this->imaginary);
    }
}

    function compare($x, $y) {
        if ( $x == $y ) {
            echo $x . " is equal to " . $y . PHP_EOL;
        } else {
            echo $x . " is not equal to " . $y . PHP_EOL;
        }
    }
?>