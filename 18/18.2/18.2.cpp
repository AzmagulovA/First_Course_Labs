

#include <iostream>

using namespace std;
class student {
	string fio;
	string group;
	float ball;
public:
	student();
	student(string, string, float);
	student(const student&);
	~student();
	string get_fio();
	void set_fio(string);
	string get_group();
	void set_group(string);
	float get_ball();
	void set_ball(float);
	void show();
};
student::student() {
	fio = "_";
	group = "_";
	ball = 0;
}
student::student(string n,string a,float b) {
	fio = n;
	group = a;
	ball = b;
}
student::student(const student&t) {
	fio = t.fio;
	group = t.group;
	ball = t.ball;
}
student::~student() {
	cout << "Destructor" << this<<endl;
	
}
string student::get_fio(){
	return fio;
}
string student::get_group() {
	return group;
}
float student::get_ball() {
	return ball;
}
void student::set_group(string a) {
	group=a;
}
void student::set_fio(string b) {
	fio = b;
}
void student::set_ball(float c) {
	ball = c;
}
void student::show() {
	cout << endl;
	cout << "FIO :" << fio<< endl;
	cout << "group :" << group << endl;
	cout << "ball :" << ball << endl;
}
student make_student(){
	string s,b;
    float i;
	cout << endl;
	cout << "FIO: " << endl;
	cin >> s;
	cout << "group: " << endl;
	cin >> b;
	cout << "ball(myach): " << endl;
	cin >> i;
	student t(s, b, i);
	return t;
}
void print_student(student t) {
	t.show();
}
void main() {
	setlocale(LC_ALL, "rus");
	student t1;
	t1.show();
	student t2("Азмагулов Артём В.", "РИС-20-1б", 4.01);
	t2.show();
	student t3 = t2;
	t3.set_fio("волугомзА мётрА");
	t3.set_group("б1-02-СИР");
	t3.set_ball(3.99);
	print_student(t3);
	t1 = make_student();
	t1.show();

}


