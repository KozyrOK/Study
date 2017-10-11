<?php
$number = (int)fgets(STDIN);
for($i = 1; $i <= $number; $i++) {
    echo implode(' ', range(1+($number-$i)*$number, ($number - $i + 1)*$number)) . PHP_EOL;
}
?>