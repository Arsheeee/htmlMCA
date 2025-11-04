<?php
$rollno = (int)$_GET["rollno"];
$name = $_GET["name"];
$gender = $_GET["gender"];
$mark1 = (int)$_GET["marka"];
$mark2 = (int)$_GET["markb"];
$Total = (int) $mark1 + $mark2;



$con=mysqli_connect("localhost","root","","arshi");
if($con)
    echo " connection success";
else
    echo "cant be connected";
// $rollfetch="SELECT rollno from student";
// $rollresult=mysqli_query($con,$sqlfetch);
 
// if(mysqli_num_rows($rollresult))


// echo '<select><option name="roll" value=</select>'

$sqlfetch="SELECT * from student";

$result=mysqli_query($con,$sqlfetch);

if(mysqli_num_rows($result)>0)
    while($row=mysqli_fetch_assoc($result))
{
    // echo "Rollno :" .$row["rollno"];
//     echo "Name :" .$row["name"];
//     echo "Rollno :" .$row["gender"];
//     echo "Rollno :" .$row["mark1"];
//     echo "Rollno :" .$row["mark2"];
//     echo "Rollno :" .$row["total"];
if($row["rollno"]==$rollno)
{

    echo '<script>alert("Student already exists....Press OK to return to the preveus page");document.location="database.php"</script>';
    
    }
 else{
    $query = "INSERT INTO student values('$rollno', '$name','$gender','$mark1','$mark2','$Total' , '' , '')";
if(mysqli_query($con,$query))
    echo '<script>alert("Inserted Successfully");document.location="database.php"</script>';
 } 
}
else{
$query = "INSERT INTO student values('$rollno', '$name','$gender','$mark1','$mark2','$Total' , '' , '')";
if(mysqli_query($con,$query))
    echo '<script>alert("Inserted Successfully");document.location="database.php"</script>';
}


?>