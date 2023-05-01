#include <iostream>
#include "ClassEditData.h"
#include <iostream>
#include <string>
#include "ClassMenu.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);

    cout << "Курсовая работа начата!\n";

    // Тестирование меню
    //ClassEditData *cl =  new ClassEditData();
    //cl->clear("Русаков");
    //cl->setLabel("Введите фамилию: ");
    //string surName = cl->getData(editType::onlyAlpha, 10);
    //cl->clear();
    //cl->setLabel("Введите месяц: ");
    //int month = cl->getData(editType::onlyDigit, 1, 12);
    //cout << endl << "Фамилия: " << surName << endl;
    //cout << "Месяц: " << month;

    ClassMenu* mainMenu = new ClassMenu("Основное меню");
    mainMenu->addMenuItem("Выход"); // 0
    mainMenu->addMenuItem("Отобразить/изменить данные о студентах"); // 1 
    mainMenu->addMenuItem("Добавить данные о новом студенте"); // 2
    mainMenu->addMenuItem("Выполнить задание"); // 3
    int selectedItem = mainMenu->run();
    
    
    cout << endl << "Вы выбрали: " << selectedItem;

}

