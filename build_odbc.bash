#!/bin/bash
set -e -v

g++ -c odbc_view_student.cpp
g++ -c odbc_insert_restaurant.cpp
g++ -c odbc_db.cpp
g++ -c hello.cpp
g++ -Wall -I/usr/include/cppconn -o hello.exe hello.o odbc_db.o -L/usr/lib -lmysqlcppconn
g++ -Wall -I/usr/include/cppconn -o odbc_insert_restaurant.exe odbc_insert_restaurant.o odbc_db.o -L/usr/lib -lmysqlcppconn
g++ -Wall -I/usr/include/cppconn -o odbc_view_student.exe odbc_view_student.o odbc_db.o -L/usr/lib -lmysqlcppconn
