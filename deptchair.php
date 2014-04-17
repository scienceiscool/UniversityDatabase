<html>
<head>
<title>Department Chair</title>
</head>

<center>
<body>

<p><em>Enter the requested information to view the results of the query.</em></p><br>

<form name="input" action="" method="post">
Name of professor: <input type="text" name="PROFNAME">
<input type="submit" value="Submit">
</form>

<form name="input" action="" method="post">
Department Number: <input type="text" name="DEPTNUMBER">
<input type="submit" value="Submit">
</form>

</body>
</center>

</html>

<?php
     $link = mysql_connect('ecsmysql', 'username', 'password');

     if(!$link){
       die('Could not connect: ' . mysql_error());
     }

     echo 'Connected successfully!<p>';

     mysql_select_db("username",$link);
     
     $prof_name = $_POST["PROFNAME"];
     $dept_num = $_POST["DEPTNUMBER"];


     if($prof_name != ""){
       $query = "SELECT cNumber, Course.Title, Units FROM Professor, Section,
       Course WHERE pName = '$prof_name' AND Ssn = pSsn AND cNum = cNumber";

       echo "<br><p>";
       echo $query;
       echo "<p><br>";

       $result = mysql_query($query,$link);
  
       for($i = 0; $i < mysql_numrows($result); $i++){
           echo "Course No: ", mysql_result($result,$i,"cNumber"), "<br>";
           echo "Title: ", mysql_result($result,$i,"Title"), "<br>";
           echo "Units: ", mysql_result($result,$i,"Units"), "<br><br>";
       }
     }
     if($dept_num != ""){
          $query = "SELECT dNumber, SUM(Units) AS units FROM Department, Course
          WHERE dNumber = '$dept_num' AND dNumber = dNo GROUP BY dNumber";

          echo "<p>";
          echo $query;
          echo "<p>";

          $result = mysql_query($query,$link);

	   for($i = 0; $i < mysql_numrows($result); $i++){
          echo "Department Number: ", mysql_result($result,$i,"dNumber");
	   echo "<br>";
          echo "Total Number of Units: ", mysql_result($result,$i,"units");
          echo "<br><br>";
          }
	}

     mysql_close($link);
?>
