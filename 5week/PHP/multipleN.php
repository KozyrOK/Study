<?php
$max = (int)fgets(STDIN);
$divisor = (int)fgets(STDIN);
$last = $max - $max % $divisor;
echo implode(' ', range(0, $last, $divisor)) . PHP_EOL;
?>