#ifndef L&S_H_INCLUDED
#include<iostream>
#include "mystring.h"
#include <iostream>
#include<string.h>
#include <mysql.h>
#include <sstream>
#include <windows.h>

HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
struct Sign_Up{
    char usn[30]{NULL};
    char em[30]{NULL};
    char pwn[30]{NULL};
    char ad[30]{NULL};
    char np[11]{NULL};
    bool chackE=false,chackNP=false,chackPhone;
}SU;
struct Login{

    string name;
    char em[50]{NULL};
    char pw[50]{NULL};
    char wo[50]{NULL};
    bool chackem=true;
    bool chackpw=true;
    bool chackmanger=false;
    bool Back=false;
}Lo;
struct connect{
    MYSQL* conn;
    int qstate;
    MYSQL_ROW row;
    MYSQL_RES * res;
    string query;
    const char * q;
}c;
struct input{
    string reem;
    string repw;
    string rech;
    char em[50];
    char pw[50];
}i;


void Connect(){
    c.conn = mysql_init(0);
    c.conn = mysql_real_connect(c.conn, "localhost", "root", "", "rsms", 0, NULL, 0);

    }
void C_SU(){
        Connect();
        if(c.conn){
        cout<<countlength(SU.em)<<" 2-"<<countlength(SU.pwn)<<endl;
        std::stringstream ss;
        cout<<countlength(SU.em)<<" 2-"<<countlength(SU.pwn)<<endl;
        system("pause");
        ss << " INSERT INTO employees (Name, Email, Password , Number_phone,Address) values ('" << SU.usn<<"','"
        << SU.em<<" ','" <<SU.pwn<<" ','" <<SU.np <<" ','" <<SU.ad<<"');";
        c.query = ss.str ();
        c.q = c.query.c_str();
        c.qstate = mysql_query(c.conn, c.q);
    }else cout<<"database is off\ngo on database for run program";
}
void C_L(){
        Connect();

        if(!(c.conn)) {cout<<"database is off\n";system("pause");}
        c.qstate = mysql_query(c.conn, "SELECT `Email`,`Password`,`Name`,`manger` FROM `employees` WHERE 1");
        if (!c.qstate)
        {
            c.res = mysql_store_result(c.conn);

            while (c.row = mysql_fetch_row (c.res))
            {
                 i.reem=c.row[0];
                 i.repw=c.row[1];
                 i.rech=c.row[3];
                strcpy(i.em,i.reem.c_str());
                strcpy(i.pw,i.repw.c_str());

                if(chack(i.em,Lo.em)){
                    Lo.chackem=false;
                    if(chack(i.pw,Lo.pw)){
                            Lo.chackpw=false;
                            Lo.name=c.row[2];
                            if(i.rech=="1")Lo.chackmanger=true;
                    }
                }
            }

        }
}




void sgin_up(){
    start:
    system("cls");

        if(SU.chackE==true||SU.chackNP==true){
            cout<<"\t\t sign up\nusername:";
            show(SU.usn);
            cout<<endl;
            }else{
            cout<<"\t\t sign up\nusername:";
            gets(SU.usn);
        }

        if (SU.chackNP==true){
            cout<<"email:";show(SU.em);cout<<endl;
            cout<<"password:";show(SU.pwn);cout<<endl;
            cout<<"address:";show(SU.ad);cout<<endl;
        }else {
            cout<<"email:";gets(SU.em);
            if (countchar(SU.em,'@')==0 || countchar(SU.em,'@')>1){
                cout<<"your email invalid should have one @ only\n";
                system("pause");
                SU.chackE=true;
                goto start;
            }else SU.chackE=false;

            if (countchar(SU.em,'.')==0){
                cout<<"your email  invalid should have at least one comma .\n";
                system("pause");
                SU.chackE=true;
                goto start;
            }
                else SU.chackE=false;

                cout<<"password:";gets(SU.pwn);
                cout<<"address:";gets(SU.ad);
                }

	cout<<"phone:";gets(SU.np);
	for(int i=0,c=0;i<11;i++){
        SU.chackPhone=(SU.np[i]<='9'&&SU.np[i]>='0');
        if(SU.np[i]==0)c++;
        if(SU.chackPhone&&c<9) SU.chackPhone=true;
        else SU.chackPhone=false;
        }
	if(!(SU.chackPhone)){
        cout<<"enter is invalid should be 11 number and should be least 10 number at zero";
        SU.chackNP=true;
        system("pause");
        goto start;
	}else SU.chackNP=false;
	null(Lo.wo);
	 C_SU();
    }

void login(){
u:
    SetConsoleTextAttribute(h,6);

	cout<<"\t\t Login    (if you don't have account enter 0)\n";SetConsoleTextAttribute(h,4);  show(Lo.wo);SetConsoleTextAttribute(h,7);

	cout<<"\nusername:";gets(Lo.em);

    //  space =32 and we shuold remove last space
    if(Lo.em[countlength(Lo.em)-1]!=32){
    Lo.em[countlength(Lo.em)+1]='\0';
    Lo.em[countlength(Lo.em)]=' ';
    }


	if(Lo.em[0]=='0'){
        sgin_up();
    system("pause");
        goto u;
	}


	C_L();

    if(Lo.chackem){
            system("cls");
            strcpy(Lo.wo,"wrong username plaes enter true username ");
            goto u;
        }


    null(Lo.wo);

pa:
    system("cls");
	cout<<"username:"<<Lo.em<<endl;SetConsoleTextAttribute(h,4);show(Lo.wo);SetConsoleTextAttribute(h,7);cout<<endl;
	cout<<"password:";gets(Lo.pw);





    Lo.pw[countlength(Lo.pw)+1]='\0';
    Lo.pw[countlength(Lo.pw)]=' ';




    C_L();
	if(Lo.chackpw){
        strcpy(Lo.wo,"worng password");
        goto pa;
        }



    null(Lo.wo);
	system("cls");

	}


#endif // L&S_H_INCLUDED
