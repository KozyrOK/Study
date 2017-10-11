<?php
function arraySearch($array, $needle) {
    $a = array_search($needle, $array);
    if ($a == null) {
        return -1;
    }
    return $a;
}
?>