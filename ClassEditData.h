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
	string deleteOneChar(string dataString) {
		string tmpString = "";
		tmpString = data;
		data = "";
		if (tmpString.length() > 0) {
			for (int i = 0; i < tmpString.length() - 1; i++)
				data = data + tmpString[i];
		}
		return data;
	}

	string getData(string dataString = "") {
		char ch = 0;
		while (ch != 13) { //13 - код enter чтобы ввести значения
			ch = _getch();
			if (ch == 8) {  // Backspace удалить символ
				data = deleteOneChar(data);
				cout << data;
				continue;
			}
			cout << ch;
			data = data + ch;
		}
		return data;
	}


	bool isDigit(char ch) {
		if (ch >= 48 and ch <= 57)
			return true;
		else
			return false;
	}


	int getDigitData(string dataString, int min, int max) {
		char ch = 0;
		while (ch != 13) { //13 - код enter чтобы ввести значения
			ch = _getch();
			if (ch == 8) {  // Backspace удалить символ
				data = deleteOneChar(data);
				cout << data;
				continue;
			}
			if (isDigit(ch)){
				cout << ch;
				data = data + ch;
			}
		}

		return 0;

	}

};

