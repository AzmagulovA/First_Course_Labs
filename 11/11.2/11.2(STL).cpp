
#include <iostream>
#include <list>     // подключаем заголовок списка
#include <iterator> // заголовок итераторов
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    list<int> myList; // объявляем пустой список
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    int q, size,w,r;
    cout << "Введите размер списка" << endl;
    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> q;      
            myList.push_back(q); // добавляем в список новые элементы  
    }
    cout << "Введите положение нового элемента" << endl;
    cin >> w;
    if ((w <= 0) || (w > size) ){
        cout << "Введите положение нового элемента" << endl;
            cin >> w;
    }
    cout << "Введите значение нового элемента" << endl;
        cin >> r;
        list<int>::iterator it =myList.begin();

        advance(it, w);
        myList.insert(it, r);
    cout << "Список: ";
    copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " "));
    return 0;
}

