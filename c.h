#ifndef C_H_INCLUDED
#define C_H_INCLUDED
#include<iostream>
#include "mystring.h"
#include <iostream>
#include<string.h>
#include <mysql.h>
#include <sstream>
#include "L&S.h"
void Connect(){
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES * res;


    int qstate;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "rsms", 0, NULL, 0);

    }
    void C_SU(){
    {
        Connect();
        std::stringstream ss;
        ss << " INSERT INTO employees (Name, Email, Password , Number_phone,Address) values ('" << SU.usn<<"','"
        << SU.em<<" ','" <<SU.pwn<<" ','" <<SU.np <<" ','" <<SU.ad<<"');";
        string query = ss.str ();
        const char * q = query.c_str();
        qstate = mysql_query(conn, q);

    }




#endif // C_H_INCLUDED
