//����� ��� ����
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
	string upTitle; //��������� ���� (������)
	string items[100];//������ ����
	string downTitle; //���������  ���� (�����)
public:

	ClassMenu(string _upTitle){	
		upTitle = _upTitle;
	}
	ClassMenu(): ClassMenu("������� ����"){
		downTitle = "�������� ����� �� ���� (�����): ";
	}
	int getCountItems() {
		int count = 0;
		for (int i = 0; i < 100; i++) {
			if (items[i].length() > 0)
				count++;
		}
		return count;
	}
	void draw(){
		system("cls");
		cout << upTitle << endl;
		int count = getCountItems();
		for (int i = 0; i < count; i++) {
			cout << items[i] << endl;
		}
		cout << downTitle << endl;
	}
	void addMenuItem(string _item) {

	}

	int run() {
		draw();
		ClassEditData* cl = new ClassEditData();
		cl->setLabel("������� �����");
		int min=0, max = 10;
		int selectItem = cl->getData(editType::onlyDigit, min, max);

		return selectItem;
	}

};

