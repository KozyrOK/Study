<?php
function arrayShiftLeft($array, $size) {
    $last = $size - 1;
    $temp = $array[0];
    
    for ( $i = 0; $i < $size; $i++ ) {
        $array[$i] = $array[$i+1];
    }
    $array[$last] = $temp;
    return $array;
}
?>