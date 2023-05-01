#pragma once
#include <string>
#include "ClassEditData.h"

using namespace std;

enum class sex : char { Women, Men, Any };  // пол студента
enum class markType : char { Fail, Pass, Excellent5, Good4, Satisfactory3, Bad2}; // оценки за предмет

class ClassStudent
{
private:
	string filename;
public:
	ClassStudent() {
		filename = "database.bin";
	}
	void viewInfo(StudentNode *st) {
		cout << "_________Информация о студенте:_________" << endl;
		cout << "Фамилия: " << st->surName << "Имя: " << st->name << "Отчество: " << st->middleName << endl;
		cout << "Факультет: " << st->faculty << "Кафедра: " << st->department << "Группа: " << st->group << endl;
		//char recordСardNumber[30];
		//char birthDateString[30];
		//enum class sex sex;
		//int startYear;
		//ExamsRecords examsRecordsData[9][10];
		//int id;
	}

	void addNewStudent() {
		ClassEditData *edit =  new ClassEditData();
		edit->clear("");
		edit->setLabel("Введите фамилию: ");
		string surName = edit->getData(editType::onlyAlpha, 10);

	int id;

		delete edit;
	}

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
