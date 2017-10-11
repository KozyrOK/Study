<?php
class Gun {
    private  $amount, $capacity, $isReady, $model, $totalShots;
    private function validate($value) {
            if ( is_int($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
    public function __construct($capacity, $model) {
        $this->model = $model;
        $this->capacity = $this->validate($capacity);
        $this->amount = 0;
        $this->totalShots = 0;
        $this->isReady = false;
        }
    public function __get($name) {
            return $this->$name;
        }
        public function prepare() {
            $this->isReady = true;
        }
        public function reload() {
            $this->amount = $this->capacity;
        }
        public function shoot() {
            if ($this->isReady == false) {
                throw new Exception ("NotReady");
            }
            if ($this->amount == 0) {
                throw new Exception ("OutOfRounds");
            }
            $this->amount -=1;
            $this->totalShots +=1;
            echo "Bang!" . PHP_EOL;
        }
        public function __toString() {
                return sprintf("(model = %s, \n capacity = %s,\n amount = %s, \n ready = %b, \n totalShots = %s \n)", $this->model, $this->capacity, $this->amount,
                     $this->isReady, $this->totalShots);
            }
}
?>