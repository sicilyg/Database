<html>
<body>
<h3>View All Course That A Student is Enrolled IN </h3>

<form action="odbc_view_enrollment.php" method="post">
	StudentID: <input type="text" name="studentID"> <br>
	<input name="submit" type="submit"> <br><br><br>
	<a href = "http://www.csce.uark.edu/~xsguo/project_cpp/hello.php"> Main Menu </a>
</form>
<br><br>

</body>
</html>

<?php
if (isset($_POST['submit'])) {
	$studentID = escapeshellarg($_POST[studentID]);

	$command = '/home/xsguo/public_html/project_cpp/odbc_view_enrollment.exe ' . $studentID;
	echo '<p>' . 'command: ' . $command . '<p>';

	$command = escapeshellcmd($command);

	system($command);
}
?>
