#pragma once
#include <string>
#include <iostream>
#include "ClassEditData.h"
#include <windows.h>
#include <stdio.h>
using namespace std;

enum class sex : char { Women, Men, Any };  // пол студента
enum class markType : char { Fail, Pass, Excellent5, Good4, Satisfactory3, Bad2}; // оценки за предмет

struct ExamsRecords {
	string name; // Название предмета
	enum class markType; // Оценка
	bool isEmpty; // заполнен ли слот?
};

struct StudentNode  // Структура студент
{
	char surName[30]; // Фамилия
	char name[30]; // Имя
	char middleName[30]; // Отчество
	char institute[30]; // Институт  (в задании факультет)
	char department[30]; // Кафедра
	char group[30]; // Группа	
	int recordСardNumber; // Номер зачетной книжки
	char birthDateString[15]; // Дата рождения
	enum class sex sex; // Пол
	int startYear; // Год начала обучения
	ExamsRecords examsRecordsData[9][10]; // Оценки за сессию  9 сессий по 10 слотов под зачеты и экзамены
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
		strncpy_s(st.surName, "Русаков",30);
		strncpy_s(st.name, "Вячеслав",30);
		strncpy_s(st.middleName, "Андреевич",30);
		strncpy_s(st.institute, "ИКБ",30);
		strncpy_s(st.department, "Информационная безопасность",30);
		strncpy_s(st.group, "БИСО-01-22",30);
		st.recordСardNumber=1032086; 
		strncpy_s(st.birthDateString, "27.12.1984", 30);
		st.sex = sex::Men; 
		st.startYear=2002; 
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 10; j++) {
				st.examsRecordsData[i][j].isEmpty = true;
			}
	}

	void printInfo() {
		cout << endl << " _________Информация о студенте:_________" << endl;
		cout << " Фамилия: " << st.surName << " Имя: " << st.name << " Отчество: " << st.middleName << endl;
		cout << " Институт: " << st.institute << " Кафедра: " << st.department << " Группа: " << st.group << endl;
		cout << " Номер зачетной книжки: " << st.recordСardNumber << " Дата рождения: " << st.birthDateString << endl;
		cout << " Пол: ";
		if (st.sex == sex::Men) { cout << "мужской "; }
		if (st.sex == sex::Women) { cout << "женский "; }
		if (st.sex == sex::Any) { cout << "не определен "; }
		cout << " Год  начала обучения: " << st.startYear << endl;

	}

	void editStudent() {
		setDefaultData();
		ClassMenu* studMenu = new ClassMenu("Меню редактирования студента");

		studMenu->addMenuItem("Выход"); // 0
		studMenu->addMenuItem("Изменить фамилию"); // 1 
		studMenu->addMenuItem("Изменить имя"); // 2
		studMenu->addMenuItem("Изменить отчество"); // 3
		studMenu->addMenuItem("Изменить институт"); // 4
		studMenu->addMenuItem("Изменить кафедру"); // 5
		studMenu->addMenuItem("Изменить группу"); // 6
		studMenu->addMenuItem("Изменить пол"); // 7
		studMenu->addMenuItem("Изменить год  начала обучения"); // 8
		studMenu->addMenuItem("Изменить номер зачетной книжки"); // 9
		studMenu->addMenuItem("Просмотреть/изменить успеваемость"); // 10
		int selectedItem = -1;
		ClassMenu* sexMenu = new ClassMenu("Меню редактирования пола студента");
		sexMenu->addMenuItem("Выход"); // 0
		sexMenu->addMenuItem("Мужской"); // 1 
		sexMenu->addMenuItem("Женский"); // 2
		sexMenu->addMenuItem("Неопределен"); // 3
		int sexItem = -1;
		string str;
		while (selectedItem != 0) {
			printInfo();
			_getch();
			selectedItem = studMenu->run();
			switch (selectedItem)
			{
				case 1:
					edit->clear(st.surName); edit->setLabel("Введите фамилию: ");
					str = edit->getData(editType::onlyAlpha, 30).c_str();
					strncpy_s(st.surName, str.c_str(), str.size());
					break;
				case 2:
					edit->clear(st.name); edit->setLabel("Введите имя: ");
					str = edit->getData(editType::onlyAlpha, 30).c_str();
					strncpy_s(st.name, str.c_str(), str.size());
					break;				
				case 3:
					edit->clear(st.middleName); edit->setLabel("Введите отчество: ");
					str = edit->getData(editType::onlyAlpha, 30).c_str();
					strncpy_s(st.middleName, str.c_str(), str.size());
					break;
				case 4:
					edit->clear(st.institute); edit->setLabel("Введите институт: ");
					str = edit->getData(editType::onlyAlpha, 30).c_str();
					strncpy_s(st.institute, str.c_str(), str.size());
					break;				
				case 5:
					edit->clear(st.department); edit->setLabel("Введите кафедру: ");
					str = edit->getData(editType::onlyAlpha, 30).c_str();
					strncpy_s(st.department, str.c_str(), str.size());
					break;
				case 6:
					edit->clear(st.group); edit->setLabel("Введите группу: ");
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
					edit->setLabel("Введите год начала обучения: ");
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
		cout << "Список данных о студентах: " << endl;
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
		edit->setLabel("Введите номер из списка чтобы получить подробную информацию о студенте. ");
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

