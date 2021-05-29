#include "Fractionn.h"
void Fractionn::operator==(const Fractionn& t) {
	if ((t.cel == this->cel && t.drob == this->drob)) {
		cout << "Числа равны" << endl;
	}
	else {
		if ((t.cel > this->cel) || (t.cel == this->cel && t.drob > this->drob)) {
			cout << "Первое число меньше" << endl;
		}
		else {
			cout << "Второе число меньше" << endl;
		}
	}
}
istream& operator>>(istream& in, Fractionn& t) {
	cout << "cel?";
	in >> t.cel;
	cout << "drob?";
	in >> t.drob;
	return in;
}

