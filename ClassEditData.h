//����� ����� ������ 
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
	string label;
	string data;
public:
	ClassEditData() {
		label = "";
		data = "";
	}
	void setLabel(string _label) {
		if (_label.length() > 1)
			this->label = _label;
		else
			label = "";
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
	void clear(string _data="") {
		system("cls");
		data = _data;
	}

	string getData(enum class editType et) {
		char ch = 0;
		cout << label <<endl << data;
		while (ch != 13) { //13 - ��� enter ����� ������ ��������
			ch = _getch();
			if (ch == 8) {  // Backspace ������� ������
				data.pop_back(); 
				system("cls");
				cout << label << endl <<  data;
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

