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
	string surName;
	string name;
	string middleName;
	string faculty;
	string department;
	string group;
	string recordСardNumber;
	string birthDateString;
	enum class sex sex; 
	int startYear;
	ExamsRecords examsRecordsData[9][10];
	StudentNode* next;
	int id;
};
