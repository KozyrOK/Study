<?php
function arraySerch($array, $element) {
    $a = array_search($array, $destination);
    if ($a == null) {
        return -1;
    }
    return $a;
}
?>