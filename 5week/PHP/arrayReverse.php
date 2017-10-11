<?php
function arrayReverse($array, $size) {
    for ( $i = 0, $j = $size - 1; $i < $j; $i++, $j-- ) {
        $buffer = $array[$i];
        $array[$i] = $array[$j];
        $array[$j] = $buffer;
    }
    return $array;
}
?>