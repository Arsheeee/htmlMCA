<?php
echo"<form method='POST'>";
echo"Roll no : <input type='text' name = 'rollno'><br>";
echo"Name : <input type='text' name = 'name'><br>";
echo"Address : <input type='text' name = 'address'><br>";
echo"Phone Number : <input type='number' name = 'phonenumber'><br>";
echo"Username : <input type='username' name = 'username'><br>";
echo"Password : <input type='password' name = 'password'><br>";
echo"Retype Password : <input type='password' name = 'retypepassword'><br><br>";
echo"<input type='Submit' name = 'submit' value='Submit'><br><br>";
echo"<input type='Submit' name = 'reset' value='Reset'><br>";
?>
<?php
 $con=mysqli_connect("localhost","root","","student");
 if($con)
    echo "connected";
else
    print "not connected";

 if(isset($_POST['submit']))
        {
        $roll = mysqli_real_escape_string($con, $_POST['rollno']);
        $name = mysqli_real_escape_string($con, $_POST['name']);
        $address = mysqli_real_escape_string($con, $_POST['address']);
        $phone = mysqli_real_escape_string($con, $_POST['phonenumber']);
        $username = mysqli_real_escape_string($con, $_POST['username']);
        $password = mysqli_real_escape_string($con, $_POST['password']);
        $repassword = mysqli_real_escape_string($con, $_POST['retypepassword']);

        if($password !== $repassword)
        {
            echo "<script>alert('Adichathenne adikkadaa maganee....');</script>";
        }
        else{

            $query= "INSERT INTO studreg(rollno,name,address,phone,username,password)
             VALUES ('$roll','$name','$address','$phone','$username','$password')";
    
            $result=mysqli_query($con,$query);
        }

        if ($result) {
        echo "<script>alert('Data inserted successfully');</script>";
    } else {
        echo "Error: " . mysqli_error($con);
    }
        

        }


?>