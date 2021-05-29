
#include "iostream"
using namespace std;

struct List {
	int data;
	List* next;
};
List* make(int size) {
	List* first, * p;
	first = NULL;
	cout << "Введите 1 элемент:";
	p = new List;//Выделяем память под элемент
	cin >> p->data;//Вводим значение 
	first = p;//first указывает на первый элемент
	if (size !=1) {
	
		for (int i = 2; i <= size; i++) {
			List* h = new List;//Cоздаем указатель след элемента
			p->next = h;//Переходим на следующий элемент
			cout << "Введите " << i << " элемент:";
			cin >> h->data;
			h->next = NULL;//Указатель следующего элемента NULL, т.к. такого элемента нет
			p = h;
		}
		return first;//Возвращаем указатель на первый элемент списка
	}
	}


void print(List* first, int size) {
	if (first == NULL) {
		cout << "Cписок пуст" << endl;
	}
	else {
		List* p = first;//p указывает на первый элемент 
		if (size == 1) {			
			if (p->data % 2 == 1) {
				cout << p->data << " ";
				
			}
		}
		else {
			while (p != NULL) {
				if (p->data % 2 == 1) {
					cout << p->data << " ";
					p = p->next;
				}
				else {
					p = p->next;
				}
			}
			cout << endl;
		}
	}
}

int main(){
	setlocale(LC_ALL, "Russian");
	int size = 0;
	while(size <=0) {
		cout << "Введите количество элементов" << endl;
		cin >> size;
	}
	List* list = make(size);
	cout << "Ваш список: " << endl;
	print(list,size);
	return 0;
}
