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
        myDB.init();

        //testing
        string builder = "";
        string query1 = "SELECT * FROM Student";
        builder.append("<br><br><br> Student Table: " + myDB.query(query1) + "<br>");
        cout << builder << endl;

}
