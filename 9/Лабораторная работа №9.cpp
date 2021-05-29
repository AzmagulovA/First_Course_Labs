// Лабораторная работа №9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    string row;

    string path = "myFile.txt";
    int n = 10;


    ofstream fout;
    fout.open(path);

    fout.is_open();

    if (!fout.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        for (int i = 1; i <= n; i++) {
            fout << "Строка номер " << i << endl;
        }
    }
    fout.close();


    fout.is_open(); //Открываем файл с исходными данными

    if (fout.is_open()) //если файл был открыт

    {

        ofstreamoutput("F2.txt"); //открываем файл для записи

        introwNum = 1; //Номер обрабатываемой строки

        while (!input.eof())

        {

            stringrow; //Строка из файла

            string* words; //Массив слов в строке

            intwordsInRow; //Количество слов в строке

            getline(input, row); //Чтение строки из файла

            splitRow(row, words, wordsInRow); //Разбиение стоки на слова

            if (hasDoubles(words, wordsInRow)) //Если в строкеестьдубли

                output << row << '\n'; //Запись строки в файл


        }
    }
}
