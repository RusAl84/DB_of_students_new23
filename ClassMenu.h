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
	ClassMenu() {

	}

	void draw(){
	}


	int run() {
		draw();
		ClassEditData* cl = new ClassEditData();
		cl->setLabel("������� �����: ");
		int min=0, max = 10;
		int selectItem = cl->getData(editType::onlyDigit, min, max);

		return selectItem;
	}

};

