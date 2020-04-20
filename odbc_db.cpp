#include "odbc_db.h"
#include <string>
using namespace std;

// Connect to the database
void odbc_db::Connect(string Username, string mysqlPassword, string SchemaName)
{
   try
   {
      driver = get_driver_instance();
      connection = driver->connect("tcp://127.0.0.1:3306", Username, mysqlPassword);
      connection->setSchema(SchemaName);
   }
  catch (sql::SQLException &e) 
  {
      cout << "ERROR: SQLException in " << __FILE__;
      cout << " (" << __func__<< ") on line " << __LINE__ << endl;
      cout << "ERROR: " << e.what();
      cout << " (MySQL error code: " << e.getErrorCode();
      cout << ", SQLState: " << e.getSQLState() << ")" << endl;
   }
}

// Disconnect from the database
void odbc_db::disConnect()  
{
   delete resultSet;
   delete statement;
   connection -> close();
   delete connection;
}

// Execute an SQL query passed in as a String parameter
// and print the resulting relation
string odbc_db::query(string q) 
{
string builder = ""; 
   try 
   {
      resultSet = statement->executeQuery(q);
      builder.append("<br>---------------------------------<br>");
      builder.append("Query: <br>" + q + "<br><br>Result: ");
      builder.append(print(resultSet));
   }
   catch (sql::SQLException e) 
   {
      cout << "ERROR: SQLException in " << __FILE__;
      cout << " (" << __func__<< ") on line " << __LINE__ << endl;
      cout << "ERROR: " << e.what();
      cout << " (MySQL error code: " << e.getErrorCode();
      cout << ", SQLState: " << e.getSQLState() << ")" << endl;
   }
   return builder;
}

// Print the results of a query with attribute names on the first line
// Followed by the tuples, one per line
string odbc_db::print (sql::ResultSet *resultSet) 
{
string builder = ""; 
   try
   {
      if (resultSet -> rowsCount() != 0)
      {
         sql::ResultSetMetaData *metaData = resultSet->getMetaData();
         int numColumns = metaData->getColumnCount();
         builder.append(printHeader( metaData, numColumns));
         builder.append(printRecords( resultSet, numColumns));
      }
      else
         throw runtime_error("ResultSetMetaData FAILURE - no records in the result set");
   }
   catch (std::runtime_error &e) 
   {
   }
   return builder;
 }

// Print the attribute names
string odbc_db::printHeader(sql::ResultSetMetaData *metaData, int numColumns)
{ 
string builder = "";

   try 
   {
      //Printing Column names
      for (int i = 1; i <= numColumns; i++) 
      {
         if (i > 1)
            builder.append(",  ");
         builder.append(metaData->getColumnName(i));; //ColumnName
      }
      builder.append("<br>");
   }
   catch (sql::SQLException &e)
   {
   }
   return builder;
}

// Print the attribute values for all tuples in the result
string odbc_db::printRecords(sql::ResultSet *resultSet, int numColumns)   
{ 
string builder = "";

   //Printing Records
   try
   {
      while (resultSet->next()) 
      {
         for (int i = 1; i <= numColumns; i++) 
         {
            if (i > 1)
               builder.append(",  ");
            builder.append(resultSet->getString(i)); 
         }
         builder.append("<br>");
      }
   }
   catch (sql::SQLException &e)
   {
   }
   return builder;
}

// Insert into any table, any values from data passed in as String parameters
void odbc_db::insert(string table, string values) 
{
string query = "INSERT into " + table + " values (" + values + ")";

   statement->executeUpdate(query);
}

// Remove all records and fill them with values for testing
// Assumes that the tables are already created
// Assumes that connection to database is already made
void odbc_db::initDatabase()
{
   try 
   {
      // Drop records from existing tables
      statement = connection->createStatement();
      statement->executeUpdate("DELETE from Student");
      statement->executeUpdate("DELETE from Course");
      //statement->executeUpdate("DELETE from Enrollment");

      insert("Student", "1001, 'Devin Casey', 'Computer Science'");
      insert("Student", "1002, 'Kylie McGregor', 'Psychology'");
      insert("Student", "1003, 'Jai Thorpe', 'Chemical Engineering'");
      insert("Student", "1004, 'Dylon Hermaqn', 'Business'");

      insert("Course", "2001, 'CSCE', 2004, 'Programming Foundations I', 4");
      insert("Course", "2002, 'CSCE', 2014, 'Programming Foundations II', 4");
      insert("Course", "2003, 'MATH', 2554, 'Calculus I', 4");
      insert("Course", "2004, 'MATH', 2574, 'Calculus II', 4");

      // Add records to the tables
      /*insert("Restaurant", "0, 'Tasty Thai', 'Asian', 'Dallas'");
      insert("Restaurant", "3,'Eureka Pizza','Pizza', 'Fayetteville'");
      insert("Restaurant", "5,'Tasty Thai','Asian', 'Las Vegas'");

      insert("Dish", "13,'Spring Roll','ap'");
      insert("Dish", "15,'Pad Thai','en'");
      insert("Dish", "16,'Pad Stickers','ap'");
      insert("Dish", "22,'Masaman Curry','en'");
      insert("Dish", "10,'Custard','ds'");
      insert("Dish", "12,'Garlic Bread','ap'");
      insert("Dish", "44,'Salad','ap'");
      insert("Dish", "07,'Cheese Pizza','en'");
      insert("Dish", "19,'Pepperoni Pizza','en'");
      insert("Dish", "77,'Vegi Supreme Pizza','en'");

      insert("MenuItem", "0,0,13,8.00");
      insert("MenuItem", "1,0,16,9.00");
      insert("MenuItem", "2,0,44,10.00");
      insert("MenuItem", "3,0,15,19.00");
      insert("MenuItem", "4, 0,22,19.00");
      insert("MenuItem", "5, 3,44,6.25");
      insert("MenuItem", "6, 3,12,5.50");
      insert("MenuItem", "7, 3,7,12.50");
      insert("MenuItem", "8, 3,19,13.50");
      insert("MenuItem", "9,5,13,6.00");
      insert("MenuItem", "10,5,15,15.00");
      insert("MenuItem", "11,5,22,14.00");

      insert("FoodOrder", "0,2,STR_To_DATE('01,03,2017', '%d,%m,%Y'), '10:30'");
      insert("FoodOrder", "1,0,STR_To_DATE('02,03,2017', '%d,%m,%Y'), '15:33'");
      insert("FoodOrder", "2,3,STR_To_DATE('01,03,2017', '%d,%m,%Y'), '15:35'");
      insert("FoodOrder", "3,5,STR_To_DATE('03,03,2017', '%d,%m,%Y'), '21:00'");
      insert("FoodOrder", "4,7,STR_To_DATE('01,03,2017', '%d,%m,%Y'), '18:11'");
      insert("FoodOrder", "5,7,STR_To_DATE('04,03,2017', '%d,%m,%Y'), '18:51'");
      insert("FoodOrder", "6,9,STR_To_DATE('01,03,2017', '%d,%m,%Y'), '19:00'");
      insert("FoodOrder", "7,11,STR_To_DATE('05,03,2017', '%d,%m,%Y'), '17:15'");
*/

   }
   catch (sql::SQLException &e)
   {
      cout << "ERROR: SQLException in " << __FILE__;
      cout << " (" << __func__<< ") on line " << __LINE__ << endl;
      cout << "ERROR: " << e.what();
      cout << " (MySQL error code: " << e.getErrorCode();
      cout << ", SQLState: " << e.getSQLState() << ")" << endl;
   }
}

void odbc_db::init() {
	try {
		statement = connection->createStatement();
	} catch (sql::SQLException &e) {
		cout << "ERROR: SQLException in " << __FILE__;
      		cout << " (" << __func__<< ") on line " << __LINE__ << endl;
      		cout << "ERROR: " << e.what();
      		cout << " (MySQL error code: " << e.getErrorCode();
      		cout << ", SQLState: " << e.getSQLState() << ")" << endl;
	}
}
