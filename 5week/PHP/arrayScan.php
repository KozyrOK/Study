<?php
function arrayScan($file, $array, $limit) {
    $array = str_split(fread($file, $limit));
    return count($array) ;
}