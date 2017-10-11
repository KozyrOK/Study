<?php
     
   class Passport {
       
        static private $globalNumber = 1;
        static private $globalSeries = array("A", "A");
        
        private $series = array();
        private $number;
        private $name;
        private $surname;
        private $birthDate;
        public function __construct($name = "Unknown Name", $surname = "Unknown Surname", $day = 1, $month = 1, $year = 1916) {
            $this->name = $name;
            $this->surname = $surname;
            $this->birthDate = new DateTime();
            $this->birthDate->setDate($year, $month, $day);
            $this->setSeries();
            $this->setNumber();
        }
        public function __destruct() {
            unset($this->birthDate);
        }
        public function setNumber() {
            if ( self::$globalNumber == 1000000 ) {
                    self::$globalNumber = 1;
            } 
            $this->number = self::$globalNumber;
            self::$globalNumber += 1;
        }
        public function setBirthDate ($birthDate) {
            $this->birthDate = $birthDate;
        }
        public function setSeries() {
            if ( self::$globalNumber == 1000000 ) {
                if ( self::$globalSeries [1] == 'Z' ) {
                    self::$globalSeries[0] = chr( ord( self::$globalSeries[0]) + 1 );
                    self::$globalSeries[1] = 'A';
                } else {
                    self::$globalSeries[1] = chr( ord( self::$globalSeries[1]) + 1 );
                }
            }
            $this->series[0] = self::$globalSeries[0];
            $this->series[1] = self::$globalSeries[1];
        }
        public function setNewNumber( $number ) {
            if ( $number > 0 && $number < 1000000) {
                self::$globalNumber = $number;
            } 
            self::setNumber();
        }
        public function setNewSeries($series) {
            if ( $series[0] >= 'A' && $series[1] >= 'A' && $series[1] <= 'Z' && $series[1] <= 'Z' && $series[0] >= self::$globalSeries[0] && $series[1] > self::$globalSeries[1]) {
                self::$globalSeries[0] = $series[0];
                self::$globalSeries[1] = $series[1];
                self::$globalNumber = 1;
            }   
            self::setSeries();
        }
        public function setSeriesNumber($series, $number) {
            self::setNewSeries($series);
            self::setNewNumber($number);
        }
        public function __toString() {
            echo $this->birthDate->format('Y-m-d') . PHP_EOL;
            return sprintf("Series: %s%s, Number: %06d, Name: %s, Surname: %s", $this->series[0], $this->series[1], $this->number, $this->name, $this->surname);
        }
    }
?>