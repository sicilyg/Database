<html>
<body>
<h3>Enter information about a restaurant to add to the database:</h3>

<form action="odbc_insert_restaurant.php" method="post">
    Name: <input type="text" name="name"><br>
    Type: <input type="text" name="type"><br>
    City: <input type="text" name="city"><br>
    <input name="submit" type="submit" >
</form>
<br><br>

</body>
</html>

<?php
if (isset($_POST['submit'])) 
{
    // replace ' ' with '\ ' in the strings so they are treated as single command line args
    $name = escapeshellarg($_POST[name]);
    $type = escapeshellarg($_POST[type]);
    $city = escapeshellarg($_POST[city]);

    $command = '/home/MYUSERNAME/public_html/project_cpp/odbc_insert_restaurant.exe ' . $name . ' ' . $type . ' ' . $city;
    echo '<p>' . 'command: ' . $command . '<p>';

    // remove dangerous characters from command to protect web server
    $command = escapeshellcmd($command);
 
    // run odbc_insert_restaurant.exe
    system($command);           
}
?>


