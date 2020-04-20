#include <iostream>
#include <string>
#include "odbc_db.h"

using namespace std;

int main(int argc, char *argv[]) {
	string Username = "xsguo";
	string mysqlPassword = "YuzuruHanyu2018";
	string SchemaName = "xsguo";

	odbc_db myDB;
	myDB.Connect(Username, mysqlPassword, SchemaName);
	myDB.initDatabase();

	//testing
	string builder = "";
	string query1 = "SELECT * FROM Student";
	string query2 = "SELECT * FROM Course";
	string query3 = "SELECT * FROM Enrollment";
	builder.append("<br><br><br> Student Table: " + myDB.query(query1) + "<br>");
	builder.append("<br><br><br> Course Table: " + myDB.query(query2) + "<br>");
	builder.append("<br><br><br> Enrollment Table: " + myDB.query(query3) + "<br>");
	cout << builder << endl;

	cout << "Successfully Initiated Database" << endl;
}
