// 18.13(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// 18.11(4).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "Time.h"
#include "stack"
#include "vector"
#include <iostream>
#include <algorithm>
using namespace std;


typedef stack<Time> St;
typedef vector<Time> Vec;
Time s;
//формирование вектора
Vec make_vector(int n)
{
    Time a;
    Vec v;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    return v;
}
//печать вектора
void print_vector(Vec v)
{
    for (int i = 0; i < v.size(); i++)cout << v[i] << endl;
    cout << endl;
}
struct Greater_s //больше, чем s
{
    bool operator()(Time t)
    {
        if (t > s) return true; else return false;
    }
};
Time srednee(Vec v)
{
    Time s = v[0];
    //перебор вектора
    for (int i = 1; i < v.size(); i++)
        s = s + v[i];
    int n = v.size();//количество элементов в векторе
    return s / n;
}
struct Comp_less // для сортировки по убыванию
{

    bool operator()(Time t1, Time t2)
    {
        if (t1 > t2)return true;
        else return false;
    }
};
struct Equal_s
{
    bool operator()(Time t)
    {
        if (t == s == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};
St make_stack(int n)
{
    St s;
    Time t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;//ввод переменной
        s.push(t);//добавление ее в стек
    }
    return s;//вернуть стек как результат функции
}

Vec copy_stack_to_vector(St s)
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
void  print_stack(St s) {
    St b;
    Vec v;
    v = copy_stack_to_vector(s);
    b = copy_vector_to_stack(v);

    while (!b.empty())
    {
        cout << b.top() << " ";
        b.pop();

    }
}
Time Max(St s)
{
    Time m = s.top();//переменной m присваиваем значение из вершины стека
    Vec v = copy_stack_to_vector(s);//копируем стек в вектор
    while (!s.empty())//пока стк не пустой
    {
        if (s.top() > m)m = s.top();//срвниваем m и элемнт в вершине стека
        s.pop();//удаляем элемент из стека
    }
    s = copy_vector_to_stack(v);//копиуем вектор в стек
    return m; //возвращаем m
}



int main()
{
    setlocale(LC_ALL, "rus");
   
    int n;
    cout << "N?";
    cin >> n;
    Vec v;
    v = make_vector(n);
    print_vector(v);
    Vec::iterator i;
    //поставили итератор i на максимальный элемент
    i = max_element(v.begin(), v.end());
    cout << "max=" << *(i) << endl;
    Time m = *(i);


    s = m;//нашли среднее арифметическое вектора
    /*cout << "sred=" << s << endl;
    //замена с использованием предиката
    replace_if(v.begin(), v.end(), Greater_s(), m);
    cout << "ZAMENA" << endl;
    print_vector(v);
    */

    cout << "ZAMENA max na new :" << endl;
    Time r;
    cin >> r;
    replace_if(v.begin(), v.end(), Equal_s(), r);
    
    St st;
    st = copy_vector_to_stack( v);
    print_stack(st);

    cout << endl<< "Delete min : ";
    i = min_element(v.begin(), v.end());
    s = *i;
    v = copy_stack_to_vector(st);
    cout << endl;
    //переместили элементы совпадающие с min в конец вектора
    i = remove_if(v.begin(), v.end(), Equal_s());
    //удалили элементы, начиная с i и до конца вектора
    v.erase(i, v.end());
    st = copy_vector_to_stack(v);
    print_stack(st);

    // по убыванию
        cout << endl << "Sortirovka po ubivaniu:" << endl;
        v = copy_stack_to_vector(st);
    sort(v.begin(), v.end(), Comp_less());
    st = copy_vector_to_stack(v);
    print_stack(st);
    //по возрастанию
    cout << endl<< "Sortirovka po vozrasaniu:" << endl;
    v = copy_stack_to_vector(st);
    sort(v.begin(), v.end());

    st = copy_vector_to_stack(v);
    print_stack(st);

    i = find_if(v.begin(), v.end(), Equal_s());
    if (i != v.end())//если нет конца вектора
        cout << *(i) << endl;
    else
        cout << "Not such element!" << endl;
}

