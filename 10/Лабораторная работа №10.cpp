// Лабораторная работа №10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int* a;  // указатель на массив
    int i, q,r,w,t,y;
    int* b;
    q = 0;
    while (q <= 1) {
        cout << "Введите размер массива" << endl;
        cin >> q;
    }

    a = (int*)malloc(q * sizeof(int));//Выделение памяти под массив
    b = (int*)malloc(q * sizeof(int));

    for (int i = 1; i <= q; i++) {
        a[i] = rand()%100 ;
        cout << "a[" << i << "]=" << a[i] << endl;
    }
    r = 0;
    while ((r <= 0) || (r > q)) {
        cout << "Номер элемента, который вы хотите удалить" << endl;
        cin >> r;
    }
    i = 1;
    y = i;
    for (i; i <=q;  i++) {
        if (i != r) {
            b[y] = a[i];
            cout << "a[" << y << "]=" << b[y] << endl;
            y++;
        }
    }
    w = 0;
    while ((w <= 0) || (w > (q-1))) {
        cout << "Номер элемента, после которого будет стоять новое значение:" << endl;
        cin >> w;
    }
    cout << "Значение нового элемента:" << endl;
    cin >> t;
    i = 1;
    y = 1;
    for (i; i < q; i++) {
        if (i != w) {
            cout << "a[" << y << "]=" << b[i] << endl;
            y++;
        }
        else {
            cout << "a[" << y << "]=" << b[y] << endl;
            y++;
            cout << "a[" << y << "]=" << t << endl;
            y++;
        }        
    }
    return 0;
 }