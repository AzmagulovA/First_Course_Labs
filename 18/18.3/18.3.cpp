#include <iostream>
using namespace std;
class time {
public:
    int min, sec;
    time() { min = 0; sec = 0; }
    time(int m, int s) { min = m; sec = s; }
    time(const time& t) { min = t.min; sec = t.sec; }
    ~time() {}
    int get_min() { return min; }
    int get_sec() { return sec; }
    void set_min(int m) { min = m; }
    void set_sec(int s) { sec = s; }
    //перегруженные:
    time& operator=(const time&);
    time& operator++();
    time operator++(int);
    time operator+(const time&);
    bool operator==(const time&);
    //глобальные ввода и вывода:
    friend istream& operator>>(istream& in, time& t);
    friend ostream& operator<<(ostream& out, const time& t);
};
bool time::operator==(const time& t) {
    /*
    if (t.min == this->min && t.sec == this->sec) {
        return true;
    }
    else {
        return false;
    }
    */
    return (t.min == this->min && t.sec == this->sec);
}
    time& time::operator = (const time& t) {
        if (&t == this)return *this;
        min = t.min;
        sec = t.sec;
        return *this;
    }

    time& time::operator++() {
        int temp = min * 60 + sec;
        temp++;
        min = temp / 60;
        sec = temp % 60;
        return *this;
    }
    time time::operator++(int)
    {
        int temp = min * 60 + sec;
        ++temp;
        min = temp / 60;
        sec = temp % 60;
        return *this;
    }
    time time::operator+(const time& t) {
        int temp1 = min * 60 + sec;
        int temp2 = t.min * 60 + t.sec;
        time p;
        p.min = (temp1 + temp2) / 60;
        p.sec = (temp1 + temp2) % 60;
        return p;
    }

    istream& operator>>(istream& in, time& t) {
        cout << "min?";
        in >> t.min;
        cout << "sec?";
        in >> t.sec;
        return in;
    }
    ostream& operator<<(ostream& out, const time& t) {
        return (out << t.min << " : " << t.sec);
    }

int main()
{
    setlocale(LC_ALL, "rus");
    time a;
    time b;
    time c;
    cin >> a;
    cin >> b;
    if (a == b) {
        cout << "Значения равны" << endl;
    }
    else {
        cout << "Значения не равны" << endl;
    }
    ++a;
    cout << a << endl;
    c = (a++) + b;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl;
}
