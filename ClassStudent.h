#pragma once
#include <string>
#include "ClassEditData.h"

using namespace std;

enum class sex : char { Women, Men, Any };  // ��� ��������
enum class markType : char { Fail, Pass, Excellent5, Good4, Satisfactory3, Bad2}; // ������ �� �������

class ClassStudent
{
private:
	string filename;
public:
	ClassStudent() {
		filename = "database.bin";
	}
	void viewInfo(StudentNode *st) {
		cout << "_________���������� � ��������:_________" << endl;
		cout << "�������: " << st->surName << "���: " << st->name << "��������: " << st->middleName << endl;
		cout << "���������: " << st->faculty << "�������: " << st->department << "������: " << st->group << endl;
		//char record�ardNumber[30];
		//char birthDateString[30];
		//enum class sex sex;
		//int startYear;
		//ExamsRecords examsRecordsData[9][10];
		//int id;
	}

	void addNewStudent() {
		ClassEditData *edit =  new ClassEditData();
		edit->clear("");
		edit->setLabel("������� �������: ");
		string surName = edit->getData(editType::onlyAlpha, 10);

	int id;

		delete edit;
	}

};

struct ExamsRecords {
	string name;
	enum class markType;
	bool isEmpty; // ��������� �� ����?
};

struct StudentNode
{
	char surName[30];
	char name[30];
	char middleName[30];
	char faculty[30];
	char department[30];
	char group[30];
	char record�ardNumber[30];
	char birthDateString[30];
	enum class sex sex; 
	int startYear;
	ExamsRecords examsRecordsData[9][10];
	StudentNode* next;
	int id;
};
