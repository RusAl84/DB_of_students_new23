//класс для меню
#pragma once
#include "windows.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include "ClassEditData.h"
#include "ClassList.h"

class ClassMenu
{
private:
	string upTitle; //Заголовок меню (сверху)
	ClassList items; //Пункты меню  
	string downTitle; //Заголовок  меню (снизу)
public:

	ClassMenu(string _upTitle){	
		upTitle = move(_upTitle);
		//upTitle =  _upTitle; // Так не нядо ... долго;(
	}

	ClassMenu(): ClassMenu("Главное меню"){
		downTitle = "Выберите пункт из меню (число): ";
	}
	
	void addMenuItem(string _item) {
		items.push_back(_item);
	}
	void draw(){
		system("cls");
		cout << upTitle << endl;
		//int count = items.getCount();
		//for (int i = 0; i < count; i++) {
		//	cout << i << ". " << items.getItem(i) << endl;
		//}
		items.printItems4Menu();
		cout << downTitle << endl;
	}
	int run() {
		draw();
		ClassEditData* cl = new ClassEditData();
		cl->setLabel("Введите число");
		int min=0, max = items.getCount();
		int selectItem = cl->getData(editType::onlyDigit, min, max);
		delete cl;
		return selectItem;
		
	}

};

