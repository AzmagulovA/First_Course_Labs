// 18.13(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// 18.11(4).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "Time.h"
#include "set"
#include "vector"
#include <iostream>
#include <algorithm>
//#include <stack>
#include <vector>
using namespace std;


typedef set<Time>Tset;//определяем тип для работы со словарем
typedef Tset::iterator it;//итератор
//typedef stack<Time>St;//стек
//typedef vector<Time>Vec;

//функция для формирования словаря
Tset make_set(int n)
{
    Tset m;//пустой словарь
    Time a;
    for (int i = 0; i < n; i++)
    {
        cout << "?";
        cin >> a;
        //создаем пару и добавляем ее в словарь
        m.insert( a);
        //s.push(a);
    }
    //возвращаем словарь как результат работы функции
    return m;
}
void print_map(Tset m)
{
    multiset <Time> ::iterator it = m.begin();

    for (int i = 0; it != m.end(); i++, it++) {
        cout << *it << " ";
    }
}
/*Tset make_stack(int n)
{
    St s;
    Time t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;//ввод переменной
        s.push(t);//добавление ее в стек
    }
    return s;//вернуть стек как результат функции
}*/
/*Vec copy_stack_to_vector(St s)
{
    Vec v;
    while (!s.empty())//пока стек не пустой
    {
        //добавить в вектор элемент из вершиы стека
        v.push_back(s.top());
        s.pop();
    }
    return v; //вернуть вектор как результат функции
}
//копирует вектор в стек
St copy_vector_to_stack(Vec v)
{
    St s;
    for (int i = 0; i < v.size(); i++)
    {
        s.push(v[i]);//добавить в стек элемент вектора
    }
    return s; //вернуть стек как результат функции
}
Time Srednee(St s)
{
    Vec v = copy_stack_to_vector(s);//копируем стек в вектор
    int n = 1;
    Time sum = s.top();//начальное значениедля суммы
    s.pop();//удалить первый элемент из вектора
    while (!s.empty())//пока стек не пустой
    {
        sum = sum + s.top();//добавить в сумму элемент из вершины стека
        s.pop();//удалить элемент
        n++;
    }
    s = copy_vector_to_stack(v);//скопировать вектор в стек
    return sum / n; //вернуть среднее арифметическое
}
//функция для печати словаря

/*Tset delete_min(Tset m) {
    multiset <Time> ::iterator it = m.begin();
    
    Tset::iterator i;
    
    i = min_element(m.begin(), m.end());
    

    for (int i = 0; it != m.end(); i++, it++) {
        
        if (*it == i) {

        }
        
    }

}*/
Time Srednee(Tset s,int n)
{
   //копируем стек в вектор
    
    multiset <Time> ::iterator it = s.begin();
    
    Time sum;//начальное значение для суммы
   // s.pop();//удалить первый элемент из вектора
    while (it!=s.end())//пока стек не пустой
    {
        
        sum = sum + *it;//добавить в сумму элемент из вершины стека
        it++;
       
    }
    
   return sum / n; //вернуть среднее арифметическое
}
Tset slog(Tset m,Time n,int col)
{
    Tset r;
    multiset <Time> ::iterator it = m.begin();

    /*for (int i = 0; it != m.end(); i++, it++) {
        cout << *it << " ";
    }*/
    //Tset m;//пустой словарь
    Time a;
    Time sum;
    for (int i = 0; i < col; i++)
    {
        sum = *it;
        //cout << "?";
        //cin >> a;
        a = sum + n;
        //создаем пару и добавляем ее в словарь
        r.insert(a);
        it++;
        //s.push(a);
    }
    return r;
}



int main()
{
    setlocale(LC_ALL, "rus");

    int n=0;
    while (n <= 0) {
        cout << "N?";
        cin >> n;
    }

    Tset m;
    //St s;
 
    //Tset m;
    m= make_set(n);
    print_map(m);
    Tset::iterator i;
    //поставили итератор i на максимальный элемент
    
    i = max_element(m.begin(), m.end());
   // copy(m.begin(), m.end(), ostream_iterator<int>(cout, " "));

  
   
    cout << "max=" << *i<< endl;
    Time sred =Srednee(m,n);
    cout << sred<<endl;
    Tset d=slog(m,sred,n);
    print_map(d);

}

