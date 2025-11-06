<?php
 $con=mysqli_connect("localhost","root","","arshi");
 
 if($con)
echo " connection success";
else
echo "cant be connected";

        echo "<form action='' method='POST'>"
        echo " Username :<input type='text' name='text'>"
        echo " Password :<input type='password' name='password'>"
        echo " <input type = 'submit' name ='login' value='Login'>"
        echo "<input type = 'reset' name = 'res'>"

        </form>

        ?>
    <?php

        $user = $_POST["text"];
        $pass = $_POST["password"];

  if(isset($_POST['login']))
    {

        $query="SELECT * FROM login WHERE usename='$user' AND password='$pass'";
     
        $result=mysqli_query($con,$query)
         if(mysqli_num_rows($result)>0)
         { 
            
         }
    }      
   

 ?>       