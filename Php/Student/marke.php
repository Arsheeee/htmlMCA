<?php
$con=mysqli_connect("localhost","root","","student");
if($con)
    echo "connected<br>";
else
    echo "connection error<br>";

if(isset($_POST['submit']))
{
     $roll = mysqli_real_escape_string($con,$_POST['rollno']);
     $sci  = (int)$_POST['scie'];
     $math = (int)$_POST['math'];
     $eng  = (int)$_POST['eng'];
     $totalmark = (int)$_POST['totm'];

     $query= "INSERT INTO markentry(rollno,science,maths,english,totalmark)
             VALUES ('$roll','$sci','$math','$eng','$totalmark')";

     $result=mysqli_query($con,$query);

     if ($result) {
        echo "<script>alert('Data inserted successfully');</script>";
    } else {
        echo "Error: " . mysqli_error($con);
    }
}
?>

<?php

echo "<form method='POST'>";
echo "Roll no : <input type='number' name='rollno' required><br><br>";
echo "Science : <input type='number' name='scie' id='scie' required><br><br>";
echo "Maths : <input type='number' name='math' id='math' required><br><br>";
echo "English : <input type='number' name='eng' id='eng' required><br><br>";
echo "Total Mark : <input type='number' name='totm' id='totm' readonly><br><br>";
echo "<input type='button' name='add' value='Add Marks' onclick='calctotal()'>";
echo "<input type='submit' name='submit' value='Submit'><br><br>";
echo "<input type='reset' value='Reset'>";
echo "</form>";

// JavaScript using echo
echo "<script>
function calctotal(){
    var scie = parseInt(document.getElementById('scie').value) || 0;
    var math = parseInt(document.getElementById('math').value) || 0;
    var eng  = parseInt(document.getElementById('eng').value) || 0;

    var total = scie + math + eng;
    document.getElementById('totm').value = total;
}
</script>";
?>
