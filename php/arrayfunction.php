<?php
$data = array("red", "green", "blue");
echo "Array has " . sizeof($data) . " elements";
echo "<br>";

$data = array("hero" => "Holmes", "villain" => "Moriarty");
print_r(array_values($data));
echo "<br>";

$data = array("hero" => "Holmes", "villain" => "Moriarty");
print_r(array_keys($data));
echo "<br>";

$data = array("Donald", "Jim", "Tom");
array_pop($data);
print_r($data);
echo "<br>";

$data = array("Donald", "Jim", "Tom");
array_push($data, "Harry");
print_r($data);
echo "<br>";

$data = array("Donald", "Jim", "Tom");
array_shift($data);
print_r($data);
echo "<br>";

$data = array("Donald", "Jim", "Tom");
array_unshift($data, "Sarah");
print_r($data);

echo "<br>";
$data = array("g", "t", "a", "s");
sort($data);
print_r($data);
echo "<br>";


$data = array("a" => "apple", "b" => "ball");
print_r(array_flip($data));


$data = array(10, 20, 25, 60);
print_r(array_reverse($data));
echo "<br>";

$data1 = array("cat", "goat");
$data2 = array("dog", "cow");
print_r(array_merge($data1, $data2));
echo "<br>";

$data = array("white", "black", "red");
echo "Today's color is " . $data[array_rand($data)];
echo "<br>";

$data = array("blue" => "#0000cc", "black" => "#000000", "green" => "#00ff00");
echo "Found " . array_search("#0000cc", $data);
echo "<br>";

$data = array("vanilla", "strawberry", "mango", "peaches");
print_r(array_slice($data, 1, 2));
$data = array(1,1,4,6,7,4);
print_r(array_unique($data));

function reduceBy10(&$val, $key) {
$val -= $val * 0.1;
}
echo "<br>";

$data = array(10,20,30,40);
array_walk($data, 'reduceBy10');
print_r($data);
?>