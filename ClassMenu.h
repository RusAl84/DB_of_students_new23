//класс для меню
#pragma once
#include "windows.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include "ClassEditData.h"

class ClassMenu
{
private:
	string upTitle; //Заголовок меню (сверху)
	string items[100];//Пункты меню
	string downTitle; //Заголовок  меню (снизу)
public:
	ClassMenu() {

	}

	void draw(){
	}


	int run() {
		draw();
		ClassEditData* cl = new ClassEditData();
		cl->setLabel("Введите месяц: ");
		int min=0, max = 10;
		int selectItem = cl->getData(editType::onlyDigit, min, max);

		return selectItem;
	}

};

