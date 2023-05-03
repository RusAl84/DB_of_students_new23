#pragma once
#include <string>
#include <iostream>
#include "ClassEditData.h"

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
public:
	ClassStudent() {
		filename = "database.bin";

	}
	~ClassStudent() {

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

	void addNewStudent() {
		setDefaultData();
		ClassMenu* studMenu = new ClassMenu("Меню редактирования студента");
		ClassEditData *edit =  new ClassEditData();
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
		while (selectedItem != 0) {
			printInfo();
			_getch();
			selectedItem = studMenu->run();
			switch (selectedItem)
			{
				case 1:
					edit->clear(st.surName); edit->setLabel("Введите фамилию: ");
					strncpy_s(st.surName, edit->getData(editType::onlyAlpha, 30).c_str(), 30);
					break;
				case 2:
					edit->clear(st.name); edit->setLabel("Введите имя: ");
					strncpy_s(st.name, edit->getData(editType::onlyAlpha, 30).c_str(), 30);
					break;				
				case 3:
					edit->clear(st.middleName); edit->setLabel("Введите отчество: ");
					strncpy_s(st.middleName, edit->getData(editType::onlyAlpha, 30).c_str(), 30);
					break;
				case 4:
					edit->clear(st.institute); edit->setLabel("Введите институт: ");
					strncpy_s(st.institute, edit->getData(editType::onlyAlpha, 30).c_str(), 30);
					break;				
				case 5:
					edit->clear(st.department); edit->setLabel("Введите кафедру: ");
					strncpy_s(st.department, edit->getData(editType::onlyAlpha, 30).c_str(), 30);
					break;
				case 6:
					edit->clear(st.group); edit->setLabel("Введите группу: ");
					strncpy_s(st.group, edit->getData(editType::all, 30).c_str(), 30);
					break;
				case 7:
					ClassMenu * sexMenu = new ClassMenu("Меню редактирования пола студента");
					sexMenu->addMenuItem("Выход"); // 0
					sexMenu->addMenuItem("Мужской"); // 1 
					sexMenu->addMenuItem("Женский"); // 2
					sexMenu->addMenuItem("Неопределен"); // 3
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

