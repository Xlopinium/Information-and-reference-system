#include "include/Car.h"
#include "include/OList.h"
#include <iostream>
#include <fstream>		// для записи/чтения из файла
#include <stdlib.h>		// для очистки консоли
#include <Windows.h>	// для локализации

using namespace std;

int main()
{
	SetConsoleCP(1251);				// Русский ввод в консоль
	SetConsoleOutputCP(1251);		// Русский вывод консоли
	cout.setf(ios::fixed);			// Выводить большие числа в нормальной форме
	cout.precision(2);				// Количество знаков после запятой
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); ////////////////////////////////////////////
	CONSOLE_CURSOR_INFO structCursorInfo;		//										  //
	GetConsoleCursorInfo(h, &structCursorInfo); //  Отключение мигания курсора в консоли  //
	structCursorInfo.bVisible = FALSE;			//										  //
	SetConsoleCursorInfo(h, &structCursorInfo); ////////////////////////////////////////////
	List data;
	char answer;
	do {
		system("CLS");
		cout << "Загрузить базу из файла?" << endl;
		cout << "1. Да" << endl;
		cout << "2. Нет" << endl;
		cout << "3. Выход" << endl;
		answer = getchar();
		switch (answer)
		{
		case '1': data.load(); system("PAUSE"); break;
		case '2': break;
		case '3': exit(0); break;
		}
	} while (answer == '1' || answer == '2');
	answer = '0';
	do {
		system("CLS");
		cout << "1. Загрузить" << endl;
		cout << "2. Сохранить" << endl;
		cout << "3. Добавить" << endl;
		cout << "4. Удалить" << endl;
		cout << "5. Просмотреть" << endl;
		cout << "6. Редактировать" << endl;
		cout << "7. Фильтр по объему" << endl;
		cout << "8. Минимальный расход топлива" << endl;
		cout << "9. Выход" << endl;
		answer = getchar();
		switch (answer)
		{
		case '1': system("CLS"); data.load();	 system("PAUSE"); break;
		case '2': system("CLS"); data.save();	 system("PAUSE"); break;
		case '3': system("CLS"); data.add();	 system("PAUSE"); break;
		case '4': system("CLS"); data.remove();  system("PAUSE"); break;
		case '5': system("CLS"); data.show();	 system("PAUSE"); break;
		case '6': system("CLS"); data.edit();	 system("PAUSE"); break;
		case '7': system("CLS"); data.filter();  system("PAUSE"); break;
		case '8': system("CLS"); data.showMin(); system("PAUSE"); break;
		}
	} while (answer != '9');

	system("pause");
}