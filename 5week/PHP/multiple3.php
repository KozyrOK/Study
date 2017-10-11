<?php
$numb = (int)fgets(STDIN);
$last = $numb - $numb % 3;
echo implode(' ', range(0, $last, 3)) . PHP_EOL;
?>