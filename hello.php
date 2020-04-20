<html>
<body>
<h3>Main Menu</h3>

<form action="hello.php" method="post">
	<input type = "submit" class = "button" name = "init" value = "initDatabase" /> <br> <br><br>
	 <a href = "http://www.csce.uark.edu/~xsguo/project_cpp/odbc_insert_restaurant.php"> Insert Student </a>
	<br><br>
	<a href = "http://www.csce.uark.edu/~xsguo/project_cpp/odbc_insert_course.php"> Insert Course </a>
	<br><br>
	<a href = "http://www.csce.uark.edu/~xsguo/project_cpp/odbc_insert_enrollment.php"> Insert Enrollment </a>
  <br><br>
	<a href = "http://www.csce.uark.edu/~xsguo/project_cpp/odbc_view_student.php"> View All Students </a>
	<br><br>
	<a href = "http://www.csce.uark.edu/~xsguo/project_cpp/odbc_view_course.php"> View Course from Department </a>


</form>
<br><br>

</body>
</html>

<?php
if (isset($_POST['init'])) {
	$command = '/home/xsguo/public_html/project_cpp/hello.exe';

	$command = escapeshellcmd($command);

	echo "command: $command <br>";
	system($command);
}
?>
