<html>
<head>
<title>Student</title>
</head>

<center>
<body>

<p><em>Enter the requested information to view the results of the query.</em></p><br>

<form name="input" action="" method="post">
Course Number: <input type="text" name="COURSENUM">
<input type="submit" value="Submit">
</form>

<form name="input" action="" method="post">
CWID: <input type="text" name="CWID">
<input type="submit" value="Submit">
</form>

</body>
</center>

</html>

<?php
     $link = mysql_connect('ecsmysql', 'cs332g24', 'eedapoog');

     if(!$link){
       die('Could not connect: ' . mysql_error());
     }

     echo 'Connected successfully!<p>';

     mysql_select_db("cs332g24",$link);

     $course_num = $_POST["COURSENUM"];
     $cwid = $_POST["CWID"];

     if($course_num != ""){
          $query = "SELECT Classroom, Meeting_days, Beginning_time, Ending_time,
          COUNT(Cw_id) AS Num_of_students, sNumber FROM Course, Section,
          Enrollment_Record WHERE cNumber = '$course_num' AND cNum = cNumber AND
          cNum = Course_No GROUP BY Course_No";

          echo "<p>";
          echo $query;
          echo "<p>";

          $result = mysql_query($query,$link);

          for($i = 0; $i < mysql_numrows($result); $i++){
                 echo "Section: ", mysql_result($result,$i,"sNumber");
                 echo "<br>";
                 echo "Classroom: ", mysql_result($result,$i,"Classroom");
                 echo "<br>";
                 echo "Meeting Days: ", mysql_result($result,$i,"Meeting_days");
                 echo "<br>";
                 echo "Start Time: ", mysql_result($result,$i,"Beginning_time");
                 echo "<br>";
                 echo "End Time: ", mysql_result($result,$i,"Ending_time");
                 echo "<br>";
                 echo "Number of Students Enrolled: ", mysql_result($result,$i,"Num_of_students");
                 echo "<br><br>";
          }
     }
     if($cwid != ""){
          $query = "SELECT Course_No, Grade FROM Student, Enrollment_Record
          WHERE Cwid = '$cwid' AND Cwid = Cw_id";

          echo "<p>";
          echo $query;
          echo "<p>";

          $result = mysql_query($query,$link);

          echo "Current Transcript"."<br><br>";

          for($i = 0; $i < mysql_numrows($result); $i++){
                 echo "Course Number: ", mysql_result($result,$i,"Course_No");
                 echo "<br>";
                 echo "Grade: ", mysql_result($result,$i,"Grade");
                 echo "<br><br>";
          }
     }

     mysql_close($link);
?>