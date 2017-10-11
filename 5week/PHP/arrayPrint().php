<?php
    function arrayPrint($file, $array) {
        fwrite($file, implode(' ', $array));
    }
?> 