<?php
$number = (int)fgets(STDIN);
for($i = 1; $i <= $number; $i++) {
    echo implode(' ', range(1+($i-1)*$number, $i*$number)) . PHP_EOL;
}
?>