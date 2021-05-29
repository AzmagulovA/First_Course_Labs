
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>


using namespace std;
struct Student {
    string fio;
    long int tel;
    int number;
};

void Vvod(Student b[], const int size) {

    ifstream fin("Names.txt");
    if (fin.is_open())//Если открытие файла прошло успешно
    {
        cout << "Файл открыт." << endl;
        for (int i = 0; i < size; i++) {
            getline(fin, b[i].fio);
            string line1;           
            string line2;
            getline(fin, line1);
            b[i].tel = atoi(line1.c_str());
            getline(fin, line2);
            b[i].number = atoi(line2.c_str());
        }
    }

};
void vivod(Student b[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << endl;
        cout << "ФИО : " << b[i].fio << endl;
        cout << "Телефон студента " << "89"<<b[i].tel << endl;
        cout << "Рейтинг студена " << b[i].number << endl;
    }
};
void Shell_Sort(Student b[], int n,const int size) {
    int i, j, d, count;
    int x[32];
    for (int k = 0; k < size; k++) {
        x[k] = b[k].number;
    }   
    d = n;
    d = d / 2;
    while (d > 0)
    {
        for (i = 0; i < n - d; i++)
        {
            j = i;
            while (j >= 0 && x[j] > x[j + d])
            {
                count = x[j];
                x[j] = x[j + d];
                x[j + d] = count;
                j--;
            }
        }
        d = d / 2;
    }
    for (int p = 0; p < 32; p++) {
        for (int i = 0; i < size; i++) {
            if (b[i].number == x[p]) {                
                cout << "ФИО : " << b[i].fio << endl;
                cout << "Телефон студента " << "89" << b[i].tel << endl;
                cout << "Рейтинг студена " << b[i].number << endl;
            }

        }
    }
}
void khoaraQuickSort(int* numbers, int left, int right)
{
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        khoaraQuickSort(numbers, left, pivot - 1);
    if (right > pivot)
        khoaraQuickSort(numbers, pivot + 1, right);
}

int main()
{
    setlocale(LC_ALL, "Russian");  
    int key = 0;
    string substr;
    const int size = 32; 
    Student* b = new Student[size];
    Vvod(b, size);
    vivod(b, size);
    int n = size;
    int op = 0;
    while (op != 4) {
        cout << endl << "1-Сортировка Шелла(рейтинг)" << endl << "2-Cтировка Хоара(телефон) " << endl;
        cout <<  endl << "Введите номер вашей операции:" << endl;
        cin >> op;
        while ((op < 0) || (op > 2)) {
            cout << "Введите номер вашей операции:" << endl;
            cin >> op;
        }
        if (op == 1) {
            Shell_Sort(b, n, size);
        }
        if (op == 2) {
            int numbers[32];
            
            for (int i = 0; i < size; i++) {
                numbers[i] = b[i].tel;

            }
            int left = 0;
            int right = 31;           
            khoaraQuickSort(numbers,left, right);
            for (int p = 0; p < 32; p++) {
                for (int i = 0; i < size; i++) {
                    if (b[i].tel == numbers[p]) {
                        cout << "ФИО : " << b[i].fio << endl;
                        cout << "Телефон студента " << "89" << b[i].tel << endl;
                        cout << "Рейтинг студена " << b[i].number << endl;
                    }

                }
            }
        }
       
    }
    return 0;
}



