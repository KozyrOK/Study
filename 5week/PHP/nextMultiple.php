<?php
$divident = (int)fgets(STDIN);
$divisor = (int)fgets(STDIN);
echo ceil($divident/$divisor) * $divisor;
?>