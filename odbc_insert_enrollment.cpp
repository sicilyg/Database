/* Compile using:
g++ -Wall -I/usr/include/cppconn -o odbc odbc_insert_enrollment.cpp -L/usr/lib -lmysqlcppconn
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
   string query1 = "SELECT * from Enrollment";
   builder.append("<br><br><br> Student table before:" + myDB.query(query1) +"<br>");

   // Parse input string to get restaurant Name and Type and  City
   string enroll_ID = "ENROLLMENT ID";
   string ID = "4";
   string course_ID = "COURSE ID";
   string dept_code = "DEPT CODE";
   string course_number = "COURSE NUMBER";

   // Read command line arguments
   // First arg, arg[0] is the name of the program
   // Next args are the parameters
   enroll_ID = argv[1];
   ID = argv[2];
   course_ID = argv[3];
   dept_code = argv[4];
   course_number = argv[5];

   // Insert the new restaurant
   string input = enroll_ID + ",'" + ID+ "','" + course_ID + "','" +dept_code + "','" + course_number + "'";
   myDB.insert("Enrollment", input);    // insert new restaurant

   //For debugging purposes: Show the database after insert
   builder.append("<br><br><br> Table Student after:" + myDB.query(query1));
   cout << builder;

   myDB.disConnect();//disconect Database

   return 0;
}
