#include "Time.h"

Time::Time(void)
{
	min = sec = 0;
}
Time::Time(int M, int S)
{
	min = M+S/60; sec = S%60;
}
Time::Time(const Time& t)
{
	min = t.min+t.sec/60;
	sec = t.sec%60;
}
Time& Time::operator =(const Time& t)
{
	min = t.min;
	sec = t.sec;
	return*this;
}
ostream& operator<<(ostream& out, const Time& t)
{
	out << t.min << " : " << t.sec;
	return out;
}
istream& operator>>(istream& in, Time& t)
{
	t.min = -1;
	while (t.min < 0) {
		cout << "\nmin?"; in >> t.min;
	}
	t.sec = -1;
	while (t.sec < 0) {
		cout << "\nsec?"; in >> t.sec;	
	}
	t.min = t.min +t.sec / 60;
	t.sec = t.sec % 60;
	return in;
}
Time Time::operator+(Time k)
{
	int t = min * 60 + sec;
	int kt = k.min * 60 + k.sec;
	t += kt;
	Time temp(t / 60, t % 60);
	return temp;
}
