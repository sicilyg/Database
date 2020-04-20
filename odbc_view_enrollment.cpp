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

   string builder = "";
   string studentID = argv[1];

   string query1 = "select * from Course where Course.CourseID in (SELECT C_ID FROM Enrollment where S_ID = " + studentID + ")";
   builder.append("<br><br><br> Course Table: " + myDB.query(query1) + "<br>");
   cout << builder;

   myDB.disConnect();
   
   return 0;
}
