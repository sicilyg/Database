<html>
<body>
<h3>View All Course From Specific Department</h3>

<form action="odbc_view_course.php" method="post"> 
	DeptCode: <input type="text" name="DeptCode"> <br>
	<input name="submit" type="submit"> <br><br><br>
	<a href = "http://www.csce.uark.edu/~xsguo/project_cpp/hello.php"> Main Menu </a>
</form>
<br><br>

</body>
</html>

<?php
if (isset($_POST['submit'])) {
	$DeptCode = escapeshellarg($_POST[DeptCode]);

	$command = '/home/xsguo/public_html/project_cpp/odbc_view_course.exe ' . $DeptCode;
	echo '<p>' . 'command: ' . $command . '<p>';

	$command = escapeshellcmd($command);

	system($command);
}
?>

