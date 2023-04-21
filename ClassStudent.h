#pragma once
#include <string>

using namespace std;

enum class sex : char { Women, Men, Any };
enum class markType : char { Fail, Pass, Excellent5, Good4, Satisfactory3, Bad2};

class ClassStudent
{

};

struct ExamsRecords {
	string name;
	enum class markType;
	bool isEmpty; // заполнено ли поле?
};

struct StudentNode
{
	char surName[30];
	char name[30];
	char middleName[30];
	char faculty[30];
	char department[30];
	char group[30];
	char recordСardNumber[30];
	char birthDateString[30];
	enum class sex sex; 
	int startYear;
	ExamsRecords examsRecordsData[9][10];
	StudentNode* next;
	int id;
};
