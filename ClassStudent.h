#pragma once
#include <string>

using namespace std;


class ClassStudent
{

};

struct ExamsRecords {
	string name;
	int mark;
	// 0 - �� �����  
	// 1 - �����  
	// 2,3,4,5 - ������
	bool isEmpty; // ��������� �� ����?
};

struct StudentNode
{
	string surName;
	string name;
	string middleName;
	string faculty;
	string department;
	string group;
	string record�ardNumber;
	string birthDateString;
	bool sex; // true - �������
	// false - �������
	int startYear;

	ExamsRecords examsRecordsData[9][10];
	StudentNode* next;
	int id;
	double avrMarks;
	double Marks45;
	double countMarks5;
	double countMarks4;
	double countMarks3;

};
