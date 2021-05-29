#include "Time.h"

Time::Time()
{
	min = 0; sec = 0;
}
Time::Time(int N, int A)
{
	min = N+A/60; sec = A%60;
}
Time::Time(const Time& p)
{
min = p.min+p.sec/60; sec = p.sec%60;
}
Time& Time::operator+(const Time& c) {
	
	this->min = this->min + c.min+ (this->sec + c.sec)/60;
	this->sec = (this->sec + c.sec)%60;
	return *this;
}

int Time::operator ==(const Time& p)
{
	
	if ((p.min == this->min && p.sec == this->sec)) {
		return 0;
	}
	else {
		if ((p.min > this->min) || (p.sec == this->sec && p.min > this->min)) {
			return 1;
		}
		else {
			return 2;//cout << "Второй временной промежуток больше" << endl;
		}
	}
	
}
fstream& operator>>(fstream& fin, Time& p)
{
	fin >> p.min;
	fin >> p.sec;
	return fin;
}
fstream& operator<<(fstream& fout, const Time& p)
{
	fout << p.min << "\n" << p.sec << "\n";
	return fout;
}
/*void Pairrr::operator==(const Pairrr& t) {
	if ((t.first == this->first && t.second == this->second)) {
		cout << "Пары чисел равны" << endl;
	}
	else {
		if ((t.first > this->first) || (t.first == this->first && t.second > this->second)) {
			cout << "Вторая пара больше" << endl;
		}
		else {
			cout << "Первая пара больше" << endl;
		}
	}
}*/
Time::~Time()
{
}
ostream& operator<<(ostream& out, const Time& p)
{
	out << "min: " << p.min << " sec:" << p.sec << "\n";
	return out;
}
istream& operator>>(istream& in, Time& p)
{
	int a, b;

	cout << "min?"; in >> p.min; cout << "sec?"; in >> p.sec;
	p.min = p.min + p.sec / 60;
	p.sec = p.sec % 60;
	
	
	return in;
}