<?php
class Mohican {
    private $next, $prev, $name;
    public static $lastMohican = NULL;
    public function __construct($name) {
        $this->name = $name;
        if (self::$lastMohican == NULL) {
            self::$lastMohican = $this;
            $this->prev = NULL;
        } else {
            $this->prev = self::$lastMohican;
            self::$lastMohican = $this;
            $this->prev->next = self::$lastMohican;
            }
        }
    public function __destruct() {
        if ($this->prev == NULL && $this->next ==NULL) {
            self::$lastMohican = NULL;
        }
        if ( self::$lastMohican == $this ) {
            self::$lastMohican = $this->prev;
        }
        if ( $this->next != NULL) {
            $this->next ->prev = $this->prev;
        }
        if ( $this->prev != NULL) {
            $this->prev ->next = $this->next;
        }
    }
    public function __get($name) {
        return $this->$name;
    }
    public function __toString() {
    return sprintf(" (name %s)", $this->name);
}
}
?>