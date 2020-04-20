<html>
<body>
<h3>Enter information about a student to add to the database:</h3>

<form action="odbc_insert_enrollment.php" method="post">
    Student ID: <input type="string" name="id"><br>
    Course ID: <input type="text" name="course_ID"><br>
    <input name="submit" type="submit" >
    <br><br>
    <a href = "http://www.csce.uark.edu/~xsguo/project_cpp/hello.php"> Main Menu </a>
</form>
<br><br>

</body>
</html>

<?php
if (isset($_POST['submit']))
{
    // replace ' ' with '\ ' in the strings so they are treated as single command line args
    $id = escapeshellarg($_POST[id]);
    $course_ID = escapeshellarg($_POST[course_ID]);

    	$command = '/home/xsguo/public_html/project_cpp/odbc_insert_enrollment.exe ' . $id . ' ' . $course_ID;
    	echo '<p>' . 'command: ' . $command . '<p>';

    	// remove dangerous characters from command to protect web server
    	$command = escapeshellcmd($command);

    	// run odbc_insert_restaurant.exe
 	system($command);

}
?>
