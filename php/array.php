<?php
$empname = array ("Anuj kumar","Sanjeev Kumar","Rahul Chaubey");
echo "This is the First Example of Numeric Index Array".'<br>'.'<br>';
echo $empname[0].'<br>';
echo $empname[1].'<br>';
echo $empname[2];

$empname[0]="VAnuj kumar";
$empname[1]="Sanjeev Kumar";
$empname[2]="rahul Chaubey";
echo "This is the Second Example of Numeric Index Array ".'<br>' ;
echo '<br>' .$empname[0]. '<br>' .$empname[1]. '<br>' .$empname[2] ;

$studentpercent ['Anuj'] = "76";
$studentpercent ['Sanjeev'] = "68";
$studentpercent ['Rahul'] = "90";
echo "This is First Example of Associative Array" .'<br>'.'<br>';
echo "Anuj have " . $studentpercent ['Anuj'] . " Percent marks in B.Tech.";

$studentpercent = array ("Anuj"=>76, "Sanjeev"=>68, "Rahul"=>90);
echo "This is Second Example of Associative Array" .'<br>'.'<br>';
echo "Rahul have " . $studentpercent ['Rahul'] . " Percent marks in MBA.";

$myLists['Employee'] = array("1"=>"Anuj Kumar",
 "2"=>"Sanjeev kumar",
 "3"=>"Rahul Chaubey",
 "4"=>"Atul Raguvanshi",
 "5"=>"Ashish Jain");
echo "This is the First Example of Multidimensional Array".'<br>'.'<br>';
echo $myLists ['Employee'][5] . " is a owner of company .";

$department = array
(
 "Development"=>array ( "Anuj", "Amit", "Sanjeev" ),
"Designing"=>array ( "Ashish" ),
"Testing"=>array ( "Atul", "Rahul", "Himanshu" )
);
echo "This is the Second Example of Multidimensional Array".'<br>' .'<br>';
echo $department ['Development'][2] . " is a employee of the Development
department.";


?>