#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class file_work {
public:
	int make_file(const char* f_name)
	{
		fstream stream(f_name, ios::out | ios::trunc);//открыть для записи
		if (!stream)return -1;//ошибка открытия файла
		int n;
		Time p;
		cout << "N?"; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> p;//ввод атрибутов объекта из стандартного потока
			stream << p << "\n";//запись объекта в файловый поток
		}
		stream.close();//закрыть поток
		return n;//вернуть количество записанных объектов
	}
	int print_file(const char* f_name)
	{
		fstream stream(f_name, ios::in);//открыть для чтения
		if (!stream)return -1;//ошибка открытия файла
		Time p; int i = 0;
		while (stream >> p)
		{
			cout << p << "\n";
			i++;
		}
		stream.close();
		return i;
	}
	int del_file(const char* f_name, int k)
	{
		fstream temp("temp", ios::out);//открыть для записи
		fstream stream(f_name, ios::in);//открыть для чтения
		if (!stream)return -1;//ошибка открытия файла
		int i = 0; Time p;
		while (stream >> p)//пока нет конца файла выполняем чтение объекта
		{
			//если прочитан признак конца файла,то выход из цикла
			if (stream.eof())break;
			i++;
			//если номер объекта не равен k, то записываем его во вспомогательый файл
			if (i != k) temp << p;
		}
		//закрыть файлы
		stream.close(); temp.close();
		remove(f_name);//удалить старый файл
		rename("temp", f_name);// переименовать temp
		return i;//количество прочитанных 
	}
	int add_file(const char* f_name, int k, Time pp) {
		fstream temp("temp", ios::out);//открыть для записи
		fstream stream(f_name, ios::in);//открыть для чтения
		if (!stream)return -1;//ошибка открытия файла
		Time p; int i = 0, l = 0;
		while (stream >> p)
		{
			if (stream.eof())break;
			i++;
			if (i == k)
			{
				temp << pp;//записать в temp новую запись
				l++;
			}
			temp << p;
		}
		stream.close(); temp.close();
		remove(f_name);
		rename("temp", f_name);
		return l;//количество добавленных
	}
	int add_end(const char* f_name, Time pp)
	{
		fstream stream(f_name, ios::app);//открыть для добавления
		if (!stream)return -1;//ошибка открытия файла
		stream << pp; //записать новую запись
		return 1;
	}
	int change_file(const char* f_name, int k, Time pp)
	{
		fstream temp("temp", ios::out);//открыть для записи
		fstream stream(f_name, ios::in);//открыть для чтения
		if (!stream)return -1;//ошибка открытия файла
		Time p; int i = 0, l = 0;
		char x;
		while (stream >> p)
		{
			if (stream.eof())break;
			i++;
			if (i == k)
			{
				cout << p << " - is changing... Continue[y/n]?\n";
				cin >> x;
				if (x == 'n' || x == 'N')break;
				temp << pp;
				l++;
			}
			else temp << p;
		}
		stream.close(); temp.close();
		remove(f_name);
		rename("temp", f_name);
		return l;//количество измененных элементов
	}
	 int change_all(const char* f_name){
	fstream temp("temp", ios::out);//открыть для записи
		fstream stream(f_name, ios::in);//открыть для чтения
		if (!stream)return -1;//ошибка открытия файла
		int i=0;
		int l = 0;
		Time p;
		Time d(1, 30);
		Time c;
		while (stream >> c)
		{
			
			if (stream.eof())break;
			i++;
			
			temp<<c+d;
			l++;
			}
		stream.close(); temp.close();
		remove(f_name);
		rename("temp", f_name);
		return l;//количество измененных элементов
	
	}
	 int adds_file(const char* f_name, int k, int col) {
		 fstream temp("temp", ios::out);//открыть для записи
		 fstream stream(f_name, ios::in);//открыть для чтения
		 if (!stream)return -1;//ошибка открытия файла
		 Time pp;
		 Time p; int i = 0, l = 0;
		 while (stream >> p)
		 {
			 if (stream.eof())break;
			 i++;
			 if (i == k)
			 {
				 for (int z = 1; z < col; z++) {
					 cout << "New Time:"; cin >> pp;
					 temp << pp;//записать в temp новую запись
					 l++;
				 }
			 }
			 temp << p;
		 }
		 stream.close(); temp.close();
		 remove(f_name);
		 rename("temp", f_name);
		 return l;//количество добавленных
	 }
	 int dels_file(const char* f_name,  Time p1)
	 {
		 fstream temp("temp", ios::out);//открыть для записи
		 fstream stream(f_name, ios::in);//открыть для чтения
		 if (!stream)return -1;//ошибка открытия файла
		 int i = 0; Time p;
		 while (stream >> p)//пока нет конца файла выполняем чтение объекта
		 {
			 //если прочитан признак конца файла,то выход из цикла
			 if (stream.eof())break;
			 i++;
			 //если номер объекта не равен k, то записываем его во вспомогательyый файл
			 if (p==p1!=0) temp << p;
		 }
		 //закрыть файлы
		 stream.close(); temp.close();
		 remove(f_name);//удалить старый файл
		 rename("temp", f_name);// переименовать temp
		 return i;//количество прочитанных 
	 }

};
