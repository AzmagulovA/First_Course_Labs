

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    stack <int> stack1;
    stack <int> stack2;
    stack <int> stack3;
    int k = 0;
    while (k <= 0) {
        cout << "Введите количество элементов стека" << endl;
        cin >> k;
    }
    cout << "Вводите значения элементов стека" << endl;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        stack1.push(a);
    }
    while (stack1.empty() == false) {  // проверяем пуст ли стек (нет)
        cout << stack1.top() << " "; // выводим верхний элемент
        if (stack1.top() % 2 == 1) {
            stack2.push(stack1.top());
        }
        stack1.pop();//Удаление верхнего элемента стека
    }
    cout << " -Первоначальный стэк" << endl;

    while (stack2.empty()==false) {  // проверяем пуст ли стек (нет)  

            stack3.push(stack2.top());
        
        stack2.pop();//Удаление верхнего элемента стека
        
    }
    while (stack3.empty() == false) {  // проверяем пуст ли стек (нет)
        cout << stack3.top() << " "; // выводим верхний элемент
        
        stack3.pop();//Удаление верхнего элемента стека
    }
    cout << " -Отсортированный стек" << endl;
    return 0;
}
