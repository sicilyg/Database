/* Compile using:
g++ -Wall -I/usr/include/cppconn -o odbc odbc_insert_restaurant.cpp -L/usr/lib -lmysqlcppconn 
run: 
./odbc */
#include "odbc_db.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
string Username = "MYUSERNAME";            // Change to your own username
string mysqlPassword = "MYMYSQLPASSWORD";  // Change to your mysql password
string SchemaName = "MYUSERNAME";          // Change to your username

   odbc_db myDB;
   myDB.Connect(Username, mysqlPassword, SchemaName);
   myDB.initDatabase();
 
   // For debugging purposes:  Show the database before insert
   string builder = "";
   string query1 = "SELECT * from Restaurant;";
   builder.append("<br><br><br> Restaurant table before:" + myDB.query(query1) +"<br>");
 
   // Parse input string to get restaurant Name and Type and  City
   string restaurantID = "4";
   string name = "NAME";
   string type = "TYPE";
   string city = "CITY";

   // Read command line arguments
   // First arg, arg[0] is the name of the program
   // Next args are the parameters
   name = argv[1];
   type = argv[2];
   city = argv[3];
 
   // Insert the new restaurant
   string input = restaurantID + ",'" + name + "','" + type + "','" + city + "'";               
   myDB.insert("Restaurant", input);    // insert new restaurant
 
   //For debugging purposes: Show the database after insert
   builder.append("<br><br><br> Table Restaurant after:" + myDB.query(query1));
   cout << builder; 
       
   myDB.disConnect();//disconect Database

   return 0;
}


