#include <iostream>
#include "ClassEditData.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    cout << "Курсовая работа начата!\n";
    ClassEditData *cl =  new ClassEditData();
    cl->clear();
    cout << "Введите фамилию: ";
    string surName = cl->getData(editType::onlyAlpha); 
    cl->clear();
    cout << "Введите месяц: ";
    string month = cl->getData(editType::onlyDigit);
    cout << endl << "Фамилия: " << surName << endl;
    cout << "Месяц: " << month;

}

