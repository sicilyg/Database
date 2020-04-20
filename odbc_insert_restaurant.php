<html>
<body>
<h3>Enter information about a student to add to the database:</h3>

<form action="odbc_insert_restaurant.php" method="post">
    Student ID: <input type="string" name="id"><br>
    Name: <input type="text" name="name"><br>
    Major: <input type="text" name="major"><br>
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
    $name = escapeshellarg($_POST[name]);
    $major = escapeshellarg($_POST[major]);


    	$command = '/home/xsguo/public_html/project_cpp/odbc_insert_restaurant.exe ' . $id . ' ' . $name . ' ' . $major;
    	echo '<p>' . 'command: ' . $command . '<p>';

    	// remove dangerous characters from command to protect web server
    	$command = escapeshellcmd($command);

    	// run odbc_insert_restaurant.exe
 	system($command);

}
?>
