<?php
include 'Car.php';
include 'Point.php';
$point = new Point(3,4);
$point1 = new Point(2,5);
$car = new Car(100, 2, $point, "Lada", 50);
echo $car;
$car->drive($point1);
echo $car;
?>