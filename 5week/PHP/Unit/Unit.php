<?php
    class Unit {
    private  $damage, $hitPoints, $hitPointsLimit, $name;
    private function validate($value) {
            if ( is_int($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
    private function ensureIsAlive() {
       if ( $this->hitPoints == 0 ) {
           throw new Exception ("UnitIsDead");
       }
    }
    public function __construct($name, $hp, $dmg) {
        $this->name = $name;
        $this->hitPointsLimit = $this->validate($hp);
        $this->damage= $this->validate($dmg);
    {
        $this->hitPoints = $this->hitPointsLimit;
    }
        }
    public function __get($name) {
            return $this->$name;
        }
   public function addHitPoints($hp){
        try {
        ensureIsAlive();
        $currentHitPoint = $this->hitPoints;
        $currentHitPoint += $hp;
        if ($currentHitPoint > $hitPointsLimit) {
            $this->hitPoints = $hitPointsLimit;
        } else {
            $this->hitPoints =  $currentHitPoint;
        }
        } catch (Exception $a) {
            echo "Cant Heal dead unit" . PHP_EOL;
        }
    }
           public function takeDamage($dmg) {
        $currentHitPoint = $this->hitPoints;
        $currentHitPoint -= $dmg;
        if ($currentHitPoint <= 0) {
            $currentHitPoint = 0;
        } 
        $this->hitPoints = $currentHitPoint;
    }
        public function attack(Unit $enemy) {
        try {
        $this->ensureIsAlive();
        $enemy->takeDamage($this->damage);
        $enemy->counterAttack($this);
        } catch (Exception $a) {
            echo "my target is dead" . PHP_EOL;
        }
    }
        public function counterAttack(Unit $enemy) {
        try {
        $this->ensureIsAlive();
        $enemy->takeDamage($this->damage/2);
        } catch (Exception $a) {
            echo "my target is dead" . PHP_EOL;
        }
    }
        public function __toString() {
                return sprintf("damage = %s, \n hit Points = %s,\n Max HP = %s, \n Unit = %s \n", $this->damage, $this->hitPoints, $this->hitPointsLimit,
                     $this->name);
            }
    }
?>