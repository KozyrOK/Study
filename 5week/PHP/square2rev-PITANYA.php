<?php
    $numb = (int)fgets(STDIN);
    for($i = 1; $i <= $numb; $i++) {
        echo implode(' ', range(1+($numb-$i)*$numb, ($numb - $i + 1)*$numb)) . PHP_EOL;
    }
?>