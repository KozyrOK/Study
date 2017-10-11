<?php
class Date{
    private $day, $month, $year;
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
    public function __construct($day, $month, $year) {
        $this ->day = $this->validate($day);
        $this ->month = $this->validate($month),
        $this ->year = $this->validate($year)
        }
        public function validate($day, $month, $year) {
        $chek;
        $LeapYear;
        if ( $month > 12 || $month < 1) {
            throw new Exception ("invalid month");
        }
        $LeapYear = $this->year % 4;
        $chek = ($this->month % 2) ^ ($this->month / 8);
            if ( $chek == 1 ) {
                if ($this->day > 31) {
                    throw new Exception ("invalid day");
                };
            } else if ( $this->month == 2 ) {
                if ( $LeapYear == 0) {
                    if ($this->day > 28) {
                        throw new Exception ("invalid day");
                    }
                } else {
                    if ($this->day > 29) {
                        throw new Exception("invalid day");
                    }
                }
        } else {
                if ($this->day > 30) {
                    throw new Exception ("invalid day");
                }
            }
    }
    public function __get($name) {
            return $this->$name;
        }
        public function __toString() {
    return sprintf(" (day %s, month %s, year %s \n)", $this->day, $this->month, $this->year);
}
}
?>