#include <iostream>
using namespace std;

struct List {
    char data;
    List* next;
    List* prev;
};

List* make(int size) {   
    List* first, * p;//Пока нет элементов,first указывает на NuLL
    first = NULL;
    p = new List;
    cout << "Введите 1 элемент:";
    cin >> p->data;//Вводим его значение
    first = p;
    p->next = NULL;//Cлед элемент NULL, т.к. его нет
    p->prev = NULL;//Пред элемент NULL,т.к. это первый элемент
    for (int i = 2; i <= size; i++) {
        List* h = new List;//Выделяем память под новый элемент
        List* q = p;//Для записи двух указателей
        p->next = h;//Настраиваем указатель следующего элемента
        p = p->next; //Переходим на след элемент
        cout << "Введите " << i << " элемент:";
        cin >> p->data;//Ввод значения      
        p->next = NULL;//Указатель на следующий элемент NULL, т.к. след элемента нет
        p->prev = q;//Указываем на прошлый элемент
    }
    return first;
}
void insert(int size1,int size, List* first)
{
    List* p = first;
    for (int i = 0; i < size1 - 1 && p!=NULL; i++) {        
        p = p->next;
    }
    if (size1 == size) {
        List* h = new List;//Выделяем память под новый элемент
        List* q = p;//Для записи двух указателей
        p->next = h;//Настраиваем указатель следующего элемента
        p = p->next; //Переходим на след элемент     
        cin >> p->data;//Ввод значения      
        p->next = NULL;//Указатель на следующий элемент NULL, т.к. след элемента нет
        p->prev = q;//Указываем на прошлый элемент
    }
    else {
        List* h = new List;//Выделяем память под новый элемент
        cin >> h->data;
        h->next = p->next;
        h->prev = p;
        p->next->prev = h;
        p->next = h;
    }    
}
void print(List* first) {
    if (first == NULL) {
        cout << "Список пустой" << endl;
    }
    else {
        List* p = first;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int size=0;
    int size1 = 0;
    while (size <= 0) {
        cout << "Введите размер " << endl;
        cin >> size;
    }
    List* list = make(size);
    print(list);


    while ((size1 <= 0)||(size1>size)) {
        cout << "Введите номер элемента, после которого будет стоять новый элемент:" << endl;
        cin >> size1;
    }   
    insert(size1,size,list );
    cout << "Ваш новый список" << endl;
    print(list);   
    return 0;
}

