#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED
#include <iostream>
#include<string.h>
using namespace std;
class Robot {
	char name[20];
	int speed,price;
	bool ch;
	float size;
static int count;
public:
    static int getcount(){return count;}
	static char company[20];
	Robot() {

		size = price =speed = 1;
		ch=false;
		//count++;
	}
	int get_speed() {
		return speed;
	}
	void input(char name[]) {
		strcpy_s(this->name, name);
	}

	void area(float x) {
		size= x * x * (22.0 / 7);
	}
	void area(float x,float y) {
		size=x*y;
	}


	void add(int x) {
		speed++;
	}
	void add(bool x,int l) {
		speed=l;
	}


	void sub(int x) {
		speed--;
	}
	void sub(bool x) {
		speed=1;
	}


	void pric() {
		price = speed*50;
		price += size*10;

	}

	void mobilec(){
	price+=500;
	ch=true;
	count++;
	}


	void display_speed() {
		cout << "Robot speed level:" << speed<<endl;
	}
	void display() {
		cout << "name:"; puts(name);
		cout << "Robot speed level:" << speed << endl;
		cout << "size Robot:" << size << endl;
		if(ch==true)cout<<"mobile control: Yes";else cout<<"mobile control: No";
		cout << "\nprice Robot:" << price<<"$" << endl;
		cout << "manufacturing company:" << company<<endl;
	}

};
int Robot::count=0;
char Robot::company [20];

#endif // ROBOT_H_INCLUDED
