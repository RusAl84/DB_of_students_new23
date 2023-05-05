#include <iostream>
#include "ClassEditData.h"
#include <iostream>
#include <string>
#include "ClassMenu.h"
#include "ClassStudent.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    ClassStudent* st = new ClassStudent();
    ClassMenu* mainMenu = new ClassMenu("Основное меню");
    mainMenu->addMenuItem("Выход"); // 0
    mainMenu->addMenuItem("Отобразить/изменить данные о студентах"); // 1 
    mainMenu->addMenuItem("Добавить данные о новом студенте"); // 2
    mainMenu->addMenuItem("Выполнить задание"); // 3
    int selectedItem = -1;
    while (selectedItem != 0){
        selectedItem = mainMenu->run();
        switch (selectedItem)
        { 
        case 1:
            st->getShortInfoFromFile();
            break;
        case 2:
            st->editStudent();
            st->addSt2File();
            break;
        deafault:
            break;
        }
    }
}

