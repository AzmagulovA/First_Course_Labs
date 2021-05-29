// 18.10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	Time x;//создать объект
	Time c;
	cin >> x;//ввести значения атрибутов
	cout << x;//вывести значения атрибутов
	Time  y;//создать объект
	cin >> y;
	cout << y;//вывести значения атрибутов
	x == y;//операция присваивания
	c=x + y;
	cout<<c;
	
}*/
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
#include "file_work.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	file_work a;
	Time p, p1, p2,pp;
	int col;
	int k, c;
	 char file_name[30];
	do
	{ //Меню
		cout << "\n1. Make file";
		cout << "\n2. Print file";
		cout << "\n3. Delete record from file";
		cout << "\n4. Add record to file";
		cout << "\n5. Change record in file";
		cout << "\n6. Добавление ко всем элементам константы";
		cout << "\n7. Добавление нескольких элементов ";
		cout << "\n8. Удаление нескольких элементов";
		cout << "\n0. Exit\n";
		
		cin >> c;
		switch (c)
		{
		case 1: cout << "file name?"; cin >> file_name;//задаем имя файла
			k = a.make_file(file_name);//вызов функции для записи в файл
			if (k < 0)cout << "Can't make file";//вывод сообщения об ошибке
			break;

		case 2: cout << "file name?"; cin >> file_name;//задаем имя файла
			k = a.print_file(file_name);//вызов функции для печати файла
			if (k == 0)cout << "Empty file\n";//если файл пустой
			if (k < 0)cout << "Can't read file\n";//если файл нельзя открыть
			break;
		case 3: cout << "file name?"; cin >> file_name;
			int nom; cout << "nom?"; cin >> nom;
			k = a.del_file(file_name, nom);
			if (k < 0)cout << "Can't read file";
			break;
		case 4: cout << "file name?";		
			cin >> file_name;
			cout << "nom?"; cin >> nom;
			cout << "New Time:"; cin >> p1;
			k = a.add_file(file_name, nom, p1);
			if (k < 0) cout << "Can't read file";
			if (k == 0) k = a.add_end(file_name, pp);
			break;
		case 5: cout << "file name?";
			cin >> file_name;
			cout << "nom?"; cin >> nom;
			cout << "New Time:";		
			cin >> p2;
			k = a.change_file(file_name, nom, p2);
			if (k < 0) cout << "\nCan't read file";
			if (k == 0) cout << "\nNot such record";
			break;
		case 6:
			k = a.change_all(file_name);
			if (k < 0) cout << "Can't read file";
			if (k == 0) k = a.add_end(file_name, pp);
			break;
		case 7:
			cout << "file name?";
			cin >> file_name;
			cout << "nom?"; cin >> nom;
			cout << "количество?"; cin >> col;
			cout << "New Time:"; cin >> p1;
			k = a.adds_file(file_name, nom,col);
			if (k < 0) cout << "Can't read file";
			if (k == 0) k = a.add_end(file_name, pp);
			break;
		case 8:
			cout << "file name?"; cin >> file_name;
			
			
			 
			
			cout << "Значение, которое надо удалить?"; cin >> p1;
			k = a.dels_file(file_name, p1);
			if (k < 0)cout << "Can't read file";
			break;
		

		}
		
	} while (c != 0);
}