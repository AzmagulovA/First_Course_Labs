
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
    for (int i = 0; i < size; i++) {
        string str = b[i].fio;
        strl = b[i].fio.size();

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

void boyer(Student b[], string substr, int size) {
    int strl, substrl;
    substrl = substr.size();//длина шаблона
    bool k = false;
    for (int i = 0; i < size; i++) {
        string str = b[i].fio;
        strl = b[i].fio.size();//длина строки
       if(substrl==strl){
           if (strl != 0 && substrl != 0) {
               int r, p;
               int a[256];
               for (r = 0; r < 256; r++) {
                   a[r] = substrl;
               }
               for (r = substrl; r >= 0; r--) {
                   if (a[int(unsigned char(substr[r]))] == substrl) {
                       a[int(unsigned char(substr[r]))] = substrl - r - 1;
                   }
               }
               p = substrl - 1;
               while (p < substrl) {
                   if (substr[substrl - 1] != str[p]) {
                       p += a[int((unsigned char)str[p])];
                   }
                   else {
                       for (r = substrl - 1; r >= 0; r--) {
                           if (substr[r] != str[p - substrl + r + 1]) {
                               p += a[int((unsigned char)str[p - substrl + r + 1])];
                               break;
                           }
                           else if (r == 0) {
                               k = true;
                               cout << "ФИО : " << b[i].fio << endl;
                               cout << "Группа студента " << b[i].group << endl;
                               cout << "Рейтинг студена " << b[i].number << endl;
                               break;
                           }

                       }
                       break;
                   }
               }
           }
        }
                       
    }
    if ((k == false) ) {
        cout << "Такого студента нет" << endl;
    }
   
}

void KMPSearch(Student b[], string substr, int size) { //в качестве параметров в функцию передается строка и субстрока
    int  sl, ssl;
    bool l = true;
    int res = -1;                                               //присваивается длина строки
    ssl = substr.size();  
    for (int z = 0; z < size; z++) {//присваивается длина субстроки
        sl = b[z].fio.size();                                                         
        int  i, j = 0, k = -1;
        int* d;
        d = new int[1000];                                         //создали динамический одномерный массив
        d[0] = -1; //первый элемент делаем равным -1
        if (sl == ssl) {
            while (j < ssl - 1) {
                //пока  j < кол-ва эл-тов строки
                while (k >= 0 && substr[j] != substr[k]) /*пока k больше или равно 0 и j-тый элемент субстроки не равен
                                                                               k-тому присваиваем k k-тый элемент динамического массива*/
                    k = d[k];
                j++;                                                         //увеличиваем j
                k++;
                if (substr[j] == substr[k])                   //если j-ый элемент субстроки равен k-тому
                    d[j] = d[k];                                             //присваиваем j-тому элементу динамического массива k-тый
                else                                                         //иначе
                    d[j] = k;                                                 //присваиваем k
            }
            i = 0;
            j = 0;                                                         //обнулили i, j
            while (j < ssl && i < sl) {                               //пока j < длины субстроки и i < длины строки
                while (j >= 0 && b[z].fio[i] != substr[j])       // пока j >= 0 и i-ый элемент субстроки не равен j-ому
                    j = d[j];                                                  //j присваивается j-ый элемент динамического массива
                i++;
                j++;                                                         //увеличиваем i и j
            }
            delete[] d;                                                 //удаляем динам. массив                                                
            if (j == ssl) {
                cout << "ФИО : " << b[z].fio << endl;
                cout << "Группа студента " << b[z].group << endl;
                cout << "Рейтинг студена " << b[z].number << endl;
                l = false;
            }

        }
    }
   
    if (l == true) {
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
            cout << endl << "1-Поиск по ФИО (Бойер-Мур)" << endl << "2-Поиск по ФИО (Прямой)" << endl;
            cout << "3-Поиск по ФИО(КМП)" << endl << "4-Завершение работы" << endl << "Введите номер вашей операции:" << endl;
            cin >> op;
            while ((op < 0) || (op > 5)) {
                cout << "Введите номер вашей операции:" << endl;
                cin >> op;
            }
            if (op == 1) {
                cout << "Введите ФИО студента, которого вы ищите (Бойер-Мур)" << endl;
                cin.ignore();
                getline(cin, substr);
                boyer(b, substr, size);
            }
            if (op == 2) {
                cout << "Введите ФИО студента, которого вы ищите (Прямой)" << endl;
                cin.ignore();
                getline(cin, substr);
                search(b, substr, size);
            }
            if (op == 3) {
                cout << "Введите ФИО студента, которого вы ищите(КМП)" << endl;
                cin.ignore();
                getline(cin, substr);
                KMPSearch(b, substr, size);
            }
        }
        return 0;
    }



