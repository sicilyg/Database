<html>
<body>
<h3>View All Students</h3>

<form action="odbc_view_student.php" method="post"> 
	 <a href = "http://www.csce.uark.edu/~xsguo/project_cpp/hello.php"> Main Menu </a>
	<br><br>
</form>
<br><br>

</body>
</html>

<?php
	$command = '/home/xsguo/public_html/project_cpp/odbc_view_student.exe';
	echo '<p>' . 'command: ' . $command . '<p>';

	$command = escapeshellcmd($command);

	system($command);
?>
