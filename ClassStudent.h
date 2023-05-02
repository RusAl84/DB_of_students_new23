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
	char faculty[30]; // �������� 
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
		strncpy_s(st.faculty, "���",30);
		strncpy_s(st.department, "�������������� ������������",30);
		strncpy_s(st.group, "����-01-22",30);
		st.record�ardNumber=1032086; 
		strncpy_s(st.birthDateString, "27.12.1984", 30);
		st.sex = sex::Men; 
		st.startYear=2002; 
	}

	void viewInfo() {
		cout << endl << "_________���������� � ��������:_________" << endl;
		cout << " �������: " << st.surName << " ���: " << st.name << " ��������: " << st.middleName << endl;
		cout << " ���������: " << st.faculty << " �������: " << st.department << " ������: " << st.group << endl;
		cout << " ����� �������� ������: " << st.record�ardNumber << " ���� ��������: " << st.birthDateString << endl;
		cout << " ���: ";
		if (st.sex == sex::Men) { cout << "������� "; }
		if (st.sex == sex::Women) { cout << "������� "; }
		if (st.sex == sex::Any) { cout << "�� ��������� "; }
		cout << " ���  ������ ��������: " << st.startYear << endl;
		//cout << " ��� ���� ����� ���������� ������������ ������� 1";
		//ExamsRecords examsRecordsData[9][10];
	}

	void addNewStudent() {
		setDefaultData();
		viewInfo();

		ClassMenu* studMenu = new ClassMenu("���� �������������� ��������");
		ClassEditData *edit =  new ClassEditData();
		edit->clear("");
		edit->setLabel("������� �������: ");
		string surName = edit->getData(editType::onlyAlpha, 10);


		delete edit;
	}

};

