#pragma once
#include <iostream>//библиотека для работы со стандартными потоками
#include <fstream> //библиотека для работы со файловыми потоками
#include <string>
using namespace std;
class Time
{
public:
	Time();
	Time(int, int);
	Time(const Time&);
	int operator ==(const Time&);
	Time& operator+(const Time& c);
	friend ostream& operator <<(ostream& out, const Time& p);
	friend istream& operator>>(istream& in, Time& p);
	friend fstream& operator>>(fstream& fin, Time& p);
	friend fstream& operator <<(fstream& fout, const  Time& p);
public:
	~Time();
private:
	int min;
	int sec;
};

