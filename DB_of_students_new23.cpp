#include <iostream>
#include "ClassEditData.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    cout << "Курсовая работа начата!\n";
    ClassEditData *cl =  new ClassEditData();
    string surName = cl->getData(editType::onlyAlpha); 
    int month = atoi(cl->getData(editType::onlyAlpha).c_str());
    cout << "Фамилия" << surName << endl;
    cout << "Месяц" << month;

}

