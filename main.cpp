#include <iostream>
#include<string.h>
#include "mystring.h"
#include "Robot.h"
#include"L&S.h"
#include "myDS.h"
using namespace std;

int main()
{

    login();


    if(Lo.chackmanger){
        cout<<"yooooooooooooooo \n";
        system("pause");
    }
    int x,y,s,co,mobile,ii=0,limt=10,i=0;
	char n[20]{NULL},chack,c;

    cout << "Welcome Mr."<<Lo.name<<" ^_^\nChoose company that make your robots :";
	gets(Robot::company );
	system("cls");

    cout<<"enter count robot you want buy:";
    while(!(cin>>co)||co<0)cin.clear(),cin.ignore();
    Robot *ob=new Robot [co];
    system("cls");


    while(i<co){
        system("cls");
		cout << "Robot [" << i + 1 << "]\n";
		cout << "name Robot:";
		getchar();
		gets(n);
		ob[i].input(n);

		system("cls");
		cout << "choose shape (price:1=10$)\n1-circle \n2-rectangular\n"; cin >> s;
		switch (s)
		{
            case 1:
                cout << "enter radius:"; cin >> x;
                ob[i].area(x);
			break;
            case 2:
                cout << "enter width and hight:";
                cin >> x >> y;
                ob[i].area(x, y);
			break;
            default:
                cout << "worng value";
			break;
		}

        do {
            system("cls");
            cout << "Robot speed level:" << ob[i].get_speed() << "\n";
            cout << "choose what you want \n1-add\n2-add full  \n3-subb\n4-sub full\n5-any number quit\n";
            cin >> x;

            switch (x)
            {
                case 1:
                    if (ob[i].get_speed() < limt)
                        ob[i].add(1);

                    else {
                        cout << "out of range 1-10\n";
                        system("pause");
                    }
                break;
                case 2:
                    ob[i].add(true,limt);
                break;
                case 3:
                    if (ob[i].get_speed() > 1)
                        ob[i].sub(1);
                    else {
                        cout << "out of range 1-10\n";
                        system("pause");
                    }
                break;

                case 4:
                    ob[i].sub(false);
                break;
            }
    }while (x>=0&&x<=5);

    ob[i].pric();
    getchar();


            system("cls");
        cout<<"want add mobile control ? enter \n1-yes(price=500$) anyvalue- no\n";
        cin>>mobile;
        if (mobile ==1)ob[i].mobilec();

    i++;
	}
	system("cls");
	cout << "number of Robot :" << Robot::getcount() << endl << endl;

	for (size_t i = 0; i < co; i++)
	{
		ob[i].display();
		cout << endl;
	}


	return 0;
}

