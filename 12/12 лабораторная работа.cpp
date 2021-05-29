
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>


using namespace std;
struct Student {
    string fio;
    string group;
    int number;
};

void Vvod(Student b[], const int size) {
   
    ifstream fin("Names.txt");    
    if (fin.is_open())//Если открытие файла прошло успешно
    {
        cout << "Файл открыт." << endl;
        for (int i = 0; i < size; i++) {
            getline(fin, b[i].fio);
            getline(fin, b[i].group);
            string line;
            getline(fin, line);
            b[i].number = atoi(line.c_str());           
        }
    }
   
};

void vivod(Student b[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << endl;
        cout << "ФИО : " << b[i].fio << endl;
        cout << "Группа студента " << b[i].group << endl;
        cout << "Рейтинг студена " << b[i].number << endl;
    }
};

void search(Student b[], string substr, int size) {
    int strl, substrl, res = -1;   
    substrl = substr.size();    
    for (int i = 0; i<size; i++) {
        string str = b[i].fio;
        strl =b[i].fio.size();
        
            if (strl != 0 && substrl != 0) {
                for (int j = 0; j < substrl; j++) {
                    if (substr[j] != str[j]) {
                        break;
                    }
                    else if (j == substrl - 1) {
                        res = i;
                        break;
                    }
                }
            }
        
        else break;
    }
    if (res == -1) {
        cout << "Такого студента нет" << endl;
    }
    else {
        cout << "ФИО : " << b[res].fio << endl;
        cout << "Группа студента " << b[res].group << endl;
        cout << "Рейтинг студена " << b[res].number << endl;
    }
    
}
int InterpolSearch(Student b[],int* a, int size, int key) {
    int mid, left = 0, right = size - 1;    
    for (int y = 0; y < size; y++) {
        a[y] = b[y].number;
    }
    bool f = true;
    while (f == true)
    {
        f = false;
        for (int re = size-1; re >= 1; re--)
        {
            if (a[re - 1] > a[re])
            {
                int  o = a[re];
                a[re] = a[re - 1];
                a[re - 1] = o;
                f = true;
            }
        }
    } 
    
    while (a[left] <= key && a[right] >= key) {
        mid = left + ((key - a[left]) * (right - left)) / (a[right] - a[left]);
        if (a[mid] < key)  left = mid + 1;
        else   if (a[mid] > key)  right = mid - 1;
        else {
            return mid;
            break;
        }
    }
    if (a[left] == key) return left;
    else return -1;   
    }

void LineSearch(Student b[],int size) {
    int key2=0;
    bool flag = false;
    while (key2 <= 0) {
        cout << "Введите рейтинг студента, которого вы ищите(Линейный поиск):" << endl;
        cin >> key2;
    }
    for (int i = 0; i < size; i++) {
        if (b[i].number == key2) {
            flag = true;
            cout << "ФИО : " << b[i].fio << endl;
            cout << "Группа студента " << b[i].group << endl;
            cout << "Рейтинг студена " << b[i].number << endl;
        }
        
    }
    if (flag == false) {
        cout << "Такого студента нет" << endl;
    }
}

int main()
{   
    setlocale(LC_CTYPE, "Russian");
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);   
    int* a;     
    int key = 0;
    string substr;   
    const int size = 32;   
    a = (int*)malloc((size) * sizeof(int));//Выделение памяти под массив
    Student* b = new Student[size];
    Vvod(b, size);
    vivod(b, size);   
    int op = 0;
    while (op != 4) {
        cout <<endl<< "1-Поиск по ФИО" << endl << "2-Поиск по рейтингу(Интерполяционный)" << endl;
        cout << "3-Поиск по рейтингу (Линейный )" << endl<<"4-Завершение работы"<<endl << "Введите номер вашей операции:" << endl;
        cin >> op;
        while ((op < 0) || (op > 5)) {
            cout<<"Введите номер вашей операции:" << endl;
            cin >> op;
        }
        if (op == 1) {
            cout << "Введите ФИО студента, которого вы ищите" << endl;
            cin.ignore();
            getline(cin, substr);
            search(b, substr, size);
        }
        if (op == 2) {
            key = 0;
            while (key <= 0) {
                
                cout << "Введите рейтинг студента, которого вы ищите(Интерполяционный поиск):" << endl;
                cin >> key;
            }
            if (InterpolSearch(b, a, size, key) == -1) {
                cout << "Такого элемента нет" << endl;
            }
            else {
                for (int i = 0; i < size; i++) {
                    if (b[i].number == a[InterpolSearch(b, a, size, key)]) {
                        cout << "ФИО : " << b[i].fio << endl;
                        cout << "Группа студента " << b[i].group << endl;
                        cout << "Рейтинг студена " << b[i].number << endl;
                    }
                }
            }
        }
        if (op == 3) {
            LineSearch(b, size);
        }       
     }
       return 0;    
}


