
#include <iostream>
using namespace std;
class Pair {
public:
	int first, second;
	Pair() { first = 0; second = 0; }
	Pair(int f, int s) { first = f; second = s; };
	Pair(const Pair& t1) { first = t1.first; second = t1.second; }
	~Pair() {};
	//bool get_Pair(const Pair& t1);
	void operator=(const Pair&);
	friend istream& operator>>(istream& in, Pair& t);
	friend ostream& operator<<(ostream& out, const Pair& t);
};
void Pair::operator=(const Pair& t) {
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
istream& operator>>(istream& in, Pair& t) {
	cout << "first?";
	in >> t.first;
	cout << "second?";
	in >> t.second;
	return in;
}

/*bool get_Pair(const Pair& t1,const Pair&t2) {
	return(t1.first>t2.first)||(t1.first==t2.first&&t1.second>t2.second);
}*/

class Fraction :public Pair {
protected:
	int cel, drob;
public:
	Fraction() { cel = 0, drob = 0; };
	Fraction(int f, int s) { cel = f, drob = s; }
	Fraction(const  Fraction& t1) { first = t1.cel; second = t1.drob; }
	~Fraction() {};
	void operator==(const Fraction&);
	friend istream& operator>>(istream& in, Fraction& t);
	friend ostream& operator<<(ostream& out, const Fraction& t);
};
void Fraction::operator==(const Fraction& t) {
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
istream& operator>>(istream& in, Fraction& t) {
	cout << "cel?";
	in >> t.cel;
	cout << "drob?";
	in >> t.drob;
	return in;
}


int main() {
	setlocale(LC_ALL, "rus");
	Pair a;
	Pair b;
	cout << "Первая пара чисел" << endl;
	cin >> a;
	cout << "Вторая пара чисел" << endl;
	cin >> b;
	a = b;
	Fraction c;
	Fraction d;
	cout << "Первое число" << endl;
	cin >> c;
	cout << "Второе число" << endl;
	cin >> d;
	c == d;
	system("pause");
}
