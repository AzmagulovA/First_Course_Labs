
#include <iostream>
#include <list>
#include <fstream>
#include <windows.h>
#include <math.h>
#include <string>

using namespace std;
struct Student
{
    string fio;
    string group;
    string number;
    
};
struct Student1
{
    string fio;
    string group;
    string number;
    Student1* pNext;
};
void Vvod(Student b[], const int size) {
    ifstream fin("Names.txt");
    if (fin.is_open())//Если открытие файла прошло успешно
    {
        cout << "Файл открыт." << endl;
        for (int i = 0; i < size; i++) {
            getline(fin, b[i].fio);
            getline(fin, b[i].group);
            getline(fin, b[i].number);

        }
    }
}
void vivod(Student b[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << endl;
        cout << "ФИО : " << b[i].fio << endl;
        cout << "Группа студента " << b[i].group << endl;
        cout << "Рейтинг студена " << b[i].number << endl;
    }
};

int  ASKII(string s){
    int p = 0;
    for (int i = 0; i < 5; i++)
    {
        p = p + (int)s[i];
    }
    return abs(p);
}
int main() {
    setlocale(LC_CTYPE, "Russian");
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    const int size = 32;
    Student* b = new Student[size];
    Student1* a = new Student1[size];
    Vvod(b, size);
    vivod(b, size);
    int c = 0;

    for (int i = 0; i < size; i++) {
        a[i].fio = "-";
        a[i].group = "-";
        a[i].number = "-";
        a[i].pNext = nullptr;

    }
    for (int i = 0; i < size; i++) {
        string s = b[i].fio;
        int ind = ASKII(s) % 32;
        if (a[ind].fio == "-") {
            a[ind].fio = b[i].fio;
            a[ind].group = b[i].group;
            a[ind].number = b[i].number;
            a[ind].pNext = nullptr;
        }
        else {
            c = c + 1;
            Student1* q = new Student1;
            Student1* p = &a[ind];
            while (p->pNext != nullptr) {

                p = p->pNext;
            }
            q->fio = b[i].fio;
            q->group = b[i].group;
            q->number = b[i].number;
            //a[ind].pNext = q;
            p->pNext = q;
            q->pNext = nullptr;
        }
    }

    cout << "Количество коллизий: " << c << endl;
        string key;
        int op = 1;
        while (op == 1) {
            cout << "Введите искомое ФИО" << endl;
            getline(cin, key);
            int ind = ASKII(key) % 32;
            for (int i = 0; i < size; i++) {
                if (ind == i) {

                    bool f = true;
                    if (a[ind].fio == key) {
                        cout << "" << endl;
                        cout << endl;
                        cout << "ФИО : " << a[i].fio << endl;
                        cout << "Группа студента " << a[i].group << endl;
                        cout << "Рейтинг студена " << a[i].number << endl;
                        f = false;
                    }
                    Student1* p = a[ind].pNext;
                    while ((f == true) && (p != nullptr)) {
                        if (p->fio == key) {
                            cout << "" << endl;
                            cout << endl;
                            cout << "ФИО : " << p->fio << endl;
                            cout << "Группа студента " << p->group << endl;
                            cout << "Рейтинг студена " << p->number << endl;
                            f = false;
                        }
                        else {
                            p = p->pNext;
                        }
                    }
                    if (f == true) {
                        cout << "Такого студента нет" << endl;
                    }
                }
            }
            cout << "Если желаете продолжить нажмите 1" << endl<<"В противном случае-другую цифру"<<endl;
            cin >> op;
            cin.ignore();
        }
        return 0;
    }

