<?php
$con=mysqli_connect("localhost","root","","arshi");
if($con)
    echo " connection success";
else
    echo "cant be connected";

$fetch="SELECT rollno from student";
$result=mysqli_query($con,$fetch);

?>
<form action="" method="POST">
    <label for="roll">Roll NO: </label>
    <select name="roll" required>
        <option value="">Select Roll num</option>

        <?php
         while($row=mysqli_fetch_assoc($result))
          {
            echo '<option value="'.$row['rollno'].'">'.$row['rollno'].'</option>';
          }   
        ?>
    </select>
    <input type="submit" value="Search">
    <!-- <input type="submit" value="Update"> -->
</form>

<?php
  if(isset($_POST['roll']))
  {
    $roll = $_POST['roll'];
    $query = "SELECT * FROM student WHERE rollno='$roll'";
    $result = mysqli_query($con,$query);
        if($row=mysqli_fetch_assoc($result))
        {
            echo "<h3>Student Details : </h3>";
            echo "Roll NO : <input type='text' name='roll' value='{$row['rollno']}'><br><br>";
            echo "Name    : <input type='text' name='nam' value='{$row['name']}'><br><br>";
            echo "Gender  : <input type='text' name='gende' value='{$row['gender']}'><br><br>";
            echo "Mark1   : <input type='text' name='mark1' value='{$row['mark1']}'><br><br>";
            echo "Mark2   : <input type='text' name='mark2' value='{$row['mark2']}'><br><br>";
            echo "Total   : <input type='text' name='tot' value='{$row['total']}'><br><br>";
        }
        else{
            echo "NO record found...";
        }
  }
  mysqli_close($con);
?>

<form action="" method="POST">
    <input type="submit" name="update" value="Update">
</form>

<?php
  function Updatestd()
  {
      $con=mysqli_connect("localhost","root","","arshi");
    $rollno = $_POST['rollno'];
    $name = $_POST['nam'];
    $Gender = $_POST['gende'];
    $mark1 = $_POST['mark1'];
    $mark2 = $_POST['mark2'];
    $total = $_POST['tot'];

    $query = "UPDATE student SET name='$name', mark1='$mark1', mark2='$mark2' WHERE  rollno='$rollno'";

    if(mysqli_query($con,$query))
    {
        echo "Updated Successfully";
    }
    
    else{
        echo "Error Updating Record :".mysqli_error($con);
    }
  }

  if(isset($_POST['update']))
    Updatestd();
 ?>
 
