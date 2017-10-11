<?php
$a = (int)fgets(STDIN);
$flag = true;
if ( $a % 2 == 0 ) {
    echo"alpha" . PHP_EOL;
    $flag = false;
}
if ( $a % 3  == 0) {
    echo"bravo" . PHP_EOL;
    $flag = false;
}
if ( $a % 5 == 0 ) {
    echo"charlie" . PHP_EOL;
    $flag = false;
}
if  ( $flag ) { 
    echo"zulu" . PHP_EOL;
}
?>