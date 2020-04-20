/* Compile using:
g++ -Wall -I/usr/include/cppconn -o odbc odbc_insert_course.cpp -L/usr/lib -lmysqlcppconn
run:
./odbc */
#include "odbc_db.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
string Username = "xsguo";            // Change to your own username
string mysqlPassword = "YuzuruHanyu2018";  // Change to your mysql password
string SchemaName = "xsguo";          // Change to your username

   odbc_db myDB;
   myDB.Connect(Username, mysqlPassword, SchemaName);
   myDB.init();

   // For debugging purposes:  Show the database before insert
   string builder = "";
   string query1 = "SELECT * from Course";
   builder.append("<br><br><br> Course table before:" + myDB.query(query1) +"<br>");

   // Parse input string to get course department code, crouse number, title, and credit number
   string dept_code = "DEPT CODE";
   string course_number = "COURSE NUMBWE";
   string title = "TITLE";
   string credit = "CREDIT NUMBER";

   // Read command line arguments
   // First arg, arg[0] is the name of the program
   // Next args are the parameters
   dept_code = argv[1];
   course_number = argv[2];
   title = argv[3];
   credit = argv[4];

   // Insert the new course
   string input = dept_code + ",'" + course_number + "','" + title + "','" + credit + "'";
   myDB.insert("Course", input);    // insert new course

   //For debugging purposes: Show the database after insert
   builder.append("<br><br><br> Table Course after:" + myDB.query(query1));
   cout << builder;

   myDB.disConnect();//disconect Database

   return 0;
}
