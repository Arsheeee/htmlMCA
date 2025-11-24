<?php
 $con=mysqli_connect("localhost","root","","student");
 
 if($con)
echo " connection success";
else
echo "cant be connected";

        echo "<form action='' method='POST'>";
        echo " Username :<input type='text' name='username'>";
        echo " Password :<input type='password' name='password'>";
        echo " <input type = 'submit' name ='login' value='Login'>";
        echo "<input type = 'reset' name = 'res'>";
        echo "</form>";


        
        if(isset($_POST['login']))
        {
        $user = mysqli_real_escape_string($con, $_POST['username']);
        $pass = mysqli_real_escape_string($con, $_POST['password']);

        $query="SELECT * FROM login WHERE username='$user' AND password='$pass'";
     
        $result=mysqli_query($con,$query);
         if($result && mysqli_num_rows($result)>0)
         { 
            header("Location: adminhome.php");
            exit();
         }
         else{
         echo "<script> alert('Invalid username or password') </script>";
            
         }
    }      
   

 ?>       