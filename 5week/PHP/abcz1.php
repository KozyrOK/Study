<?php
$a = (int) fgets(STDIN);
$b = (int) fgets(STDIN);
if ( $a <= $b ) {
    echo "alpha\n";
} else if ($a < 0) {
    echo "bravo\n";
} else if  ($b == 0) {
    echo "charlie\n";
} else { echo "zulu\n";
}
?>