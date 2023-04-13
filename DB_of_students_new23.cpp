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
    cl->clear("Русаков");
    cl->setLabel("Введите фамилию: ");
    string surName = cl->getData(editType::onlyAlpha, 10); 
    cl->clear();
    cl->setLabel("Введите месяц: ");
    int month = cl->getData(editType::onlyDigit, 1, 12);
    cout << endl << "Фамилия: " << surName << endl;
    cout << "Месяц: " << month;

}

