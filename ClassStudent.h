#pragma once
#include <string>
#include <iostream>
#include "ClassEditData.h"

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
public:
	ClassStudent() {
		filename = "database.bin";

	}
	~ClassStudent() {

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

	void addNewStudent() {
		setDefaultData();
		ClassMenu* studMenu = new ClassMenu("���� �������������� ��������");
		ClassEditData *edit =  new ClassEditData();
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
		while (selectedItem != 0) {
			printInfo();
			_getch();
			selectedItem = studMenu->run();
			switch (selectedItem)
			{
				case 1:
					edit->clear(st.surName); edit->setLabel("������� �������: ");
					strncpy_s(st.surName, edit->getData(editType::onlyAlpha, 30).c_str(), 30);
					break;
				case 2:
					edit->clear(st.name); edit->setLabel("������� ���: ");
					strncpy_s(st.name, edit->getData(editType::onlyAlpha, 30).c_str(), 30);
					break;				
				case 3:
					edit->clear(st.middleName); edit->setLabel("������� ��������: ");
					strncpy_s(st.middleName, edit->getData(editType::onlyAlpha, 30).c_str(), 30);
					break;
				case 4:
					edit->clear(st.institute); edit->setLabel("������� ��������: ");
					strncpy_s(st.institute, edit->getData(editType::onlyAlpha, 30).c_str(), 30);
					break;				
				case 5:
					edit->clear(st.department); edit->setLabel("������� �������: ");
					strncpy_s(st.department, edit->getData(editType::onlyAlpha, 30).c_str(), 30);
					break;
				case 6:
					edit->clear(st.group); edit->setLabel("������� ������: ");
					strncpy_s(st.group, edit->getData(editType::all, 30).c_str(), 30);
					break;
				case 7:
					ClassMenu * sexMenu = new ClassMenu("���� �������������� ���� ��������");
					sexMenu->addMenuItem("�����"); // 0
					sexMenu->addMenuItem("�������"); // 1 
					sexMenu->addMenuItem("�������"); // 2
					sexMenu->addMenuItem("�����������"); // 3
					int sexItem = -1;
					while (sexItem != 0) {
						sexItem = sexMenu->run();
						switch (sexItem)
						{
							case 0: sexItem = 0; break;
							case 1: st.sex = sex::Men; sexItem = 0;  break;
							case 2: st.sex = sex::Women; sexItem = 0;  break;
							case 3: st.sex = sex::Any; sexItem = 0;  break;
						}
					}
					delete sexMenu;
					break;
				deafault:
					break;
			}
		}

		delete studMenu;
		delete edit;
	}

};

