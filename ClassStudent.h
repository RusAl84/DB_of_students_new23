#pragma once
#include <string>
#include <iostream>
#include "ClassEditData.h"
#include <windows.h>
#include <stdio.h>
using namespace std;

enum class sex : char { Women, Men, Any };  // ��� ��������
enum class markType : char { Fail, Pass, Excellent5, Good4, Satisfactory3, Bad2}; // ������ �� �������

struct ExamsRecords {
	string name; // �������� ��������
	enum class markType; // ������
	bool isEmpty; // �������� �� ����?
};

struct StudentNode  // ��������� �������
{
	char surName[30]; // �������
	char name[30]; // ���
	char middleName[30]; // ��������
	char institute[30]; // ��������  (� ������� ���������)
	char department[30]; // �������
	char group[30]; // ������	
	int record�ardNumber; // ����� �������� ������
	char birthDateString[15]; // ���� ��������
	enum class sex sex; // ���
	int startYear; // ��� ������ ��������
	ExamsRecords examsRecordsData[9][10]; // ������ �� ������  9 ������ �� 10 ������ ��� ������ � ��������
};


class ClassStudent
{
private:
	string filename;
	StudentNode st;
	ClassEditData* edit;
public:
	ClassStudent() {
		filename = "database.bin.txt";
		edit = new ClassEditData();
	}
	~ClassStudent() {
		delete edit;
	}
	void setDefaultData()
	{
		strncpy_s(st.surName, "�������",30);
		strncpy_s(st.name, "��������",30);
		strncpy_s(st.middleName, "���������",30);
		strncpy_s(st.institute, "���",30);
		strncpy_s(st.department, "�������������� ������������",30);
		strncpy_s(st.group, "����-01-22",30);
		st.record�ardNumber=1032086; 
		strncpy_s(st.birthDateString, "27.12.1984", 30);
		st.sex = sex::Men; 
		st.startYear=2002; 
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 10; j++) {
				st.examsRecordsData[i][j].isEmpty = true;
			}
	}

	void printInfo() {
		cout << endl << " _________���������� � ��������:_________" << endl;
		cout << " �������: " << st.surName << " ���: " << st.name << " ��������: " << st.middleName << endl;
		cout << " ��������: " << st.institute << " �������: " << st.department << " ������: " << st.group << endl;
		cout << " ����� �������� ������: " << st.record�ardNumber << " ���� ��������: " << st.birthDateString << endl;
		cout << " ���: ";
		if (st.sex == sex::Men) { cout << "������� "; }
		if (st.sex == sex::Women) { cout << "������� "; }
		if (st.sex == sex::Any) { cout << "�� ��������� "; }
		cout << " ���  ������ ��������: " << st.startYear << endl;

	}

	void editStudent() {
		setDefaultData();
		ClassMenu* studMenu = new ClassMenu("���� �������������� ��������");

		studMenu->addMenuItem("�����"); // 0
		studMenu->addMenuItem("�������� �������"); // 1 
		studMenu->addMenuItem("�������� ���"); // 2
		studMenu->addMenuItem("�������� ��������"); // 3
		studMenu->addMenuItem("�������� ��������"); // 4
		studMenu->addMenuItem("�������� �������"); // 5
		studMenu->addMenuItem("�������� ������"); // 6
		studMenu->addMenuItem("�������� ���"); // 7
		studMenu->addMenuItem("�������� ���  ������ ��������"); // 8
		studMenu->addMenuItem("�������� ����� �������� ������"); // 9
		studMenu->addMenuItem("�����������/�������� ������������"); // 10
		int selectedItem = -1;
		ClassMenu* sexMenu = new ClassMenu("���� �������������� ���� ��������");
		sexMenu->addMenuItem("�����"); // 0
		sexMenu->addMenuItem("�������"); // 1 
		sexMenu->addMenuItem("�������"); // 2
		sexMenu->addMenuItem("�����������"); // 3
		int sexItem = -1;
		string str;
		while (selectedItem != 0) {
			printInfo();
			_getch();
			selectedItem = studMenu->run();
			switch (selectedItem)
			{
				case 1:
					edit->clear(st.surName); edit->setLabel("������� �������: ");
					str = edit->getData(editType::onlyAlpha, 30).c_str();
					strncpy_s(st.surName, str.c_str(), str.size());
					break;
				case 2:
					edit->clear(st.name); edit->setLabel("������� ���: ");
					str = edit->getData(editType::onlyAlpha, 30).c_str();
					strncpy_s(st.name, str.c_str(), str.size());
					break;				
				case 3:
					edit->clear(st.middleName); edit->setLabel("������� ��������: ");
					str = edit->getData(editType::onlyAlpha, 30).c_str();
					strncpy_s(st.middleName, str.c_str(), str.size());
					break;
				case 4:
					edit->clear(st.institute); edit->setLabel("������� ��������: ");
					str = edit->getData(editType::onlyAlpha, 30).c_str();
					strncpy_s(st.institute, str.c_str(), str.size());
					break;				
				case 5:
					edit->clear(st.department); edit->setLabel("������� �������: ");
					str = edit->getData(editType::onlyAlpha, 30).c_str();
					strncpy_s(st.department, str.c_str(), str.size());
					break;
				case 6:
					edit->clear(st.group); edit->setLabel("������� ������: ");
					str = edit->getData(editType::onlyAlpha, 30).c_str();
					strncpy_s(st.group, str.c_str(), str.size());
					break;
				case 7:

					while (sexItem != 0) {
						sexItem = sexMenu->run();
						if (sexItem == 1) { st.sex = sex::Men; sexItem = 0; }
						if (sexItem == 2) { st.sex = sex::Women; sexItem = 0; }
						if (sexItem == 3) { st.sex = sex::Any; sexItem = 0; }
					}

					break;
				case 8:
					edit->clear(to_string(st.startYear));
					edit->setLabel("������� ��� ������ ��������: ");
					st.startYear = edit->getData(editType::onlyDigit, 1940, 2012);
					break;
				deafault:
					break;
			}
		}
		delete sexMenu;
		delete studMenu;

	}

	void addSt2File() {
		FILE* binaryFile;
		fopen_s(&binaryFile, filename.c_str(), "a+");
		fwrite(&st, sizeof(st), 1, binaryFile);
		fclose(binaryFile);
	}

	int countRecords() {
		FILE* binaryFile;
		fopen_s(&binaryFile, filename.c_str(), "r");
		fseek(binaryFile, 0L, SEEK_END);
		int size = ftell(binaryFile);
		fclose(binaryFile);
		return size / sizeof(st);
	}

	void getShortInfoFromFile() {
		system("cls");
		cout << "������ ������ � ���������: " << endl;
		int size = countRecords();
		FILE* binaryFile;
		fopen_s(&binaryFile, filename.c_str(), "r");
		for (int i=0; i<size; i++) {
			fread_s(&st, sizeof(st), sizeof(st), 1, binaryFile);
			cout << i << ". " << st.surName << " " << st.name << " " << st.middleName << " " << st.group << endl;
		}
		fclose(binaryFile);
		_getch();
		edit->clear();
		edit->setLabel("������� ����� �� ������ ����� �������� ��������� ���������� � ��������. ");
		int num = edit->getData(editType::onlyDigit, 0, size);
		setStudentData(num);
		editStudent();
		write2FileStudentData(num);
	}

	void setStudentData(int num) {
		FILE* binaryFile;
		fopen_s(&binaryFile, filename.c_str(), "r");
		fseek(binaryFile, num * sizeof(st), SEEK_SET);
		fread_s(&st, sizeof(st), sizeof(st), 1, binaryFile);
		fclose(binaryFile);
	}
	void write2FileStudentData(int num) {
		int size = countRecords();

		FILE* binaryFile;
		FILE* tmpFile;
		fopen_s(&binaryFile, filename.c_str(), "r");
		fopen_s(&tmpFile, "tmp.txt", "w+");
		StudentNode tmp_st;
		for (int i = 0; i < size; i++) {
			fread_s(&tmp_st, sizeof(tmp_st), sizeof(tmp_st), 1, binaryFile);
			if (i==num)
				fwrite(&st, sizeof(st), 1, tmpFile);
			else
				fwrite(&tmp_st, sizeof(tmp_st), 1, tmpFile);
		}
		fclose(binaryFile);
		fclose(tmpFile);
		remove(filename.c_str());
		rename("tmp.txt", filename.c_str());

	}

};

