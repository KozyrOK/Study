<?php
$divident = (int)fgets(STDIN);
$divisor = (int)fgets(STDIN);
echo floor($divident/$divisor) * $divisor;
?>