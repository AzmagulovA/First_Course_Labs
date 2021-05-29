#include "Pairrr.h"
Pairrr::Pairrr(void){
	first = 0;
	second = 0;
}
Pairrr::~Pairrr(void) {

}
Pairrr::Pairrr(int c, int p) {
	first = c;
	second = p;
}
Pairrr::Pairrr(const Pairrr& t) {
	first = t.first;
	second = t.second;
}
Pairrr& Pairrr::operator=(const Pairrr& c) {
	if (&c == this)return *this;
	first = c.first;
	second = c.second;
	return *this;
}
void Pairrr::set_first(int f) {
	first = f;
}
void Pairrr::set_second(int s) {
	second = s;
}

void Pairrr::operator==(const Pairrr& t) {
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
}

istream& operator>>(istream& in, Pairrr& t) {
	cout << "first?";
	in >> t.first;
	cout << "second?";
	in >> t.second;
	return in;
}
ostream& operator<<(ostream& out, const Pairrr& t) {
	out << "first" << t.first;
	out << "second" << t.second;
	return out;
}
void Pairrr::Show() {
	cout << first;
	cout << second;
	cout << endl;
}