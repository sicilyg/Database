#include "odbc_db.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	string Username = "xsguo";
	string mysqlPassword = "YuzuruHanyu2018";
	string SchemaName = "xsguo";

	odbc_db myDB;
	myDB.Connect(Username, mysqlPassword, SchemaName);
	myDB.init();

	string builder = "";
	string deptCode = argv[1];
	string query1 = "SELECT * FROM Course WHERE DeptCode = '" + deptCode + "';";
	builder.append("<br><br><br> All Courses: " + myDB.query(query1));
	cout << builder;

	myDB.disConnect();

	return 0;

}
