#include "Fractionn.h"
void Fractionn::operator==(const Fractionn& t) {
	if ((t.cel == this->cel && t.drob == this->drob)) {
		cout << "����� �����" << endl;
	}
	else {
		if ((t.cel > this->cel) || (t.cel == this->cel && t.drob > this->drob)) {
			cout << "������ ����� ������" << endl;
		}
		else {
			cout << "������ ����� ������" << endl;
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

