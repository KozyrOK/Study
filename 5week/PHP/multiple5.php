<?php
$numb = (int)fgets(STDIN);
$last = $numb - $numb % 5;
echo implode(' ', range(0, $last, 5)) . PHP_EOL;
?>