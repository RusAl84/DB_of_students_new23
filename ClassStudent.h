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
	StudentNode* st;
public:
	ClassStudent() {
		filename = "database.bin";
		st = new StudentNode();
	}
	void viewInfo() {
		cout << "_________Информация о студенте:_________" << endl;
		cout << "Фамилия: " << st->surName << "Имя: " << st->name << "Отчество: " << st->middleName << endl;
		cout << "Факультет: " << st->faculty << "Кафедра: " << st->department << "Группа: " << st->group << endl;
		cout << "Номер зачетной книжки: " << st->recordСardNumber;
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
	string name; // Название предмета
	enum class markType; // Оценка
	bool isEmpty; // заполнено ли поле?
};

struct StudentNode  // Структура студент
{
	char surName[30]; // Фамилия
	char name[30]; // Имя
	char middleName[30]; // Отчество
	char faculty[30]; // Институт 
	char department[30]; // Кафедра
	char group[30]; // Группа	
	char recordСardNumber ; // Номер зачетной книжки
	char birthDateString[15]; // Дата рождения
	enum class sex sex; // Пол
	int startYear; // Год начала обучения
	ExamsRecords examsRecordsData[9][10]; // Оценки за сессию  9 сессий по 10 слотов под зачеты и экзамены
};
