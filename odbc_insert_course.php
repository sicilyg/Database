<html>
<body>
<h3>Enter information about a course to add to the database:</h3>

<form action="odbc_insert_course.php" method="post">
    Course ID: <input type="text" name="course_ID"><br>
    Department Code: <input type="text" name="dept_code"><br>
    Course Number: <input type="text" name="course_number"><br>
    Title: <input type="text" name="title"><br>
    Credit Hours: <input type="text" name="credit"><br>

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
    $course_ID = escapeshellarg($_POST[course_ID]);
    $dept_code = escapeshellarg($_POST[dept_code]);
    $course_number = escapeshellarg($_POST[course_number]);
    $title = escapeshellarg($_POST[title]);
    $credit = escapeshellarg($_POST[credit]);

    $command = '/home/xsguo/public_html/project_cpp/odbc_insert_course.exe ' .$course_ID. ' ' .$dept_code . ' ' . $course_number . ' ' . $title . ' ' .$credit;
    echo '<p>' . 'command: ' . $command . '<p>';

    // remove dangerous characters from command to protect web server
    $command = escapeshellcmd($command);

    // run odbc_insert_restaurant.exe
    system($command);
}
?>
