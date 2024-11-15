<?php
$data = array("hero" => "Holmes", "villain" => "Moriarty");
while (list($key, $value) = each($data)) {
echo "$key: $value n";
}
?>