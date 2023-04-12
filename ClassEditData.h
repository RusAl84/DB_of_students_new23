//класс ввода данных 
#pragma once
#include "windows.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
//#include "ClassMenu.h"

using namespace std;

class ClassEditData
{
private:
	string data;
public:
	ClassEditData() {
		data = "";
	}
	string getData(string dataString = "") {
		char ch = 0;
		while (ch != 13) { //13 - код enter чтобы ввести значения
			ch = _getch();
			if (ch == 8) {  // Backspace удалить символ
				string tmpString = "";
				tmpString = data;
				data = "";
				if (tmpString.length() > 0) {
					for (int i = 0; i < tmpString.length() - 1; i++)
						data = data + tmpString[i];
					//draw();
					cout << data;
				}
				continue;
			}
			cout << ch;
			data = data + ch;
		}
		return data;
	}
};

