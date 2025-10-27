<html>
    <head><center><h1><b>Progress Report</b></h1></center></head>
    <body><center>
        <?php

        
         $name = $_GET["nam"];
         $engl = (int)$_GET["eng"];
         $mala = (int)$_GET["mal"];
         $math = (int)$_GET["mat"];
         $scie = (int)$_GET["sci"];
         $total = (int) $engl + $mala + $math + $scie;

         echo "Name  : $name<br>";
         echo "English : $engl<br>";
         echo "Malayalam : $mala<br>";
         echo "Maths: $math<br>";
         echo "Science : $scie<br>";
         echo "Marks obtained : $total<br>";
         echo "Total marks : 400 <br>";
        ?>

    <h2><center><b>CONGRATULATIONS</b></center></h2> 
</center>   

    </body>
</html>