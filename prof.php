<html>
<head>
<title>Professor</title>
</head>

<center>
<body>

<p><em>Enter the requested information to view the results of the query.</em></p><br>

<form name="input" action="" method="post">
SSN of professor: <input type="text" name="PROFSSN">
<input type="submit" value="Submit">
</form>

<form name="input" action="" method="post">
Course Number: <input type="text" name="COURSENUMBER">
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
     
     $prof_ssn = $_POST["PROFSSN"];
     $course_num = $_POST["COURSENUMBER"];

     if($prof_ssn != ""){
          $query = "SELECT Course.Title, Classroom, Meeting_days,
          Beginning_time, Ending_time FROM Professor, Section, Course
          WHERE Ssn = '$prof_ssn' AND Ssn = pSsn AND cNum = cNumber";

          echo "<p>";
          echo $query;
          echo "<p>";

          $result = mysql_query($query,$link);

          for($i = 0; $i < mysql_numrows($result); $i++){
                 echo "Title: ", mysql_result($result,$i,"Title");
                 echo "<br>";
                 echo "Classroom: ", mysql_result($result,$i,"Classroom");
                 echo "<br>";
                 echo "Meeting Days: ", mysql_result($result,$i,"Meeting_days");
                 echo "<br>";
                 echo "Start Time: ", mysql_result($result,$i,"Beginning_time");
                 echo "<br>";
                 echo "End Time: ", mysql_result($result,$i,"Ending_time");
                 echo "<br><br>";
          }
     }
     if($course_num != ""){
          $query = "SELECT Grade, COUNT(Cw_id) AS Num_of_Students
          FROM Enrollment_Record WHERE Course_No = '$course_num' GROUP BY Grade";

          echo "<p>";
          echo $query;
          echo "<p>";

          $result = mysql_query($query,$link);

          for($i = 0; $i < mysql_numrows($result); $i++){
                 echo "Grade: ", mysql_result($result,$i,"Grade");
                 echo "<br>";
                 echo "Number of Students With This Grade: "
                 , mysql_result($result,$i,"Num_of_students");
                 echo "<br><br>";
          }
     }

     mysql_close($link);
?>
