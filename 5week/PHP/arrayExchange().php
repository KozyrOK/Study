<?php
function arrayExchange($array, $len)
{
    for ($i = 1, $j = 0; $i < $len; $i += 2, $j += 2 ) {
        $temp = $array[$j];
        
        $array[$j] = $array[$i];
        $array[$i] = $temp;
    }
    return $array;
}
?>