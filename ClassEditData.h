//класс ввода данных 
#pragma once
#include "windows.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
//#include "ClassMenu.h"

using namespace std;

enum class editType { onlyDigit, onlyAlpha, all };


class ClassEditData
{
private:
	string data;
public:
	ClassEditData() {
		data = "";
	}
	bool isDigit(char ch) {
		if (ch >= 48 and ch <= 57)
			return true;
		else
			return false;
	}
	bool isAlpha(int ch) {
		if (ch >= 65 and ch <= 90)
			return true;
		if (ch >= 97 and ch <= 122)
			return true;
		if (ch >= -200 and ch <= -1)
			return true;
		return false;
	}
	bool isSpace(char ch) {
		if (ch == 32)
			return true;
		else
			return false;
	}
	bool isSpec(char ch) {
		if (ch >= 33 and ch <= 47)
			return true;
		else
			return false;
	}
	void clear() {
		system("cls");
		data = "";
	}
	string getData(enum class editType et) {
		char ch = 0;
		while (ch != 13) { //13 - код enter чтобы ввести значения
			ch = _getch();
			if (ch == 8) {  // Backspace удалить символ
				data.pop_back(); 
				system("cls");
				cout << data;
				continue;
			}
			if (et == editType::onlyDigit)
				if (isDigit(ch)) {
					cout << ch;
					data = data + ch;
				}
			if (et == editType::onlyAlpha)
				if (isAlpha(ch)) {
					cout << ch;
					data = data + ch;
				}
			if (et == editType::all) {
				cout << ch;
				data = data + ch;
			}
		}
		return data;
	}





};

