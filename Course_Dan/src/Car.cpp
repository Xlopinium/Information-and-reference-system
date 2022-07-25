#pragma once
#include "../include/Car.h"
#include <iostream>
#include <iomanip>	// форматирование таблицы авто
using namespace std;

void Car::input()
{
	cout << "Цена:\t";
	float value;
	cin >> value;
	if (this->price == value)
	{
		cout << "\nЦена осталась без изменений.\n";
		return;
	}
	else
	{
		this->price = value;
		cout << "Кол-во:\t";
		cin >> this->amount;
		cout << "Марка:\t";
		cin >> this->brand;
		cout << "Страна:\t";
		cin >> this->country;
		cout << "Год:\t";
		cin >> this->year;
		cout << "Объем двигателя:\t";
		cin >> this->volume;
		cout << "Расход бензина:\t";
		cin >> this->gasMileage;
		cout << "\n";
	}
}

void Car::show()
{
	cout << setw(14) << left << this->price
	 << setw(14) << this->amount
	 << setw(18) << this->brand
	 << setw(14) << this->country
	 << setw(6)	 << this->year
	 << setw(7)	 << this->volume
	 << setw(18) << this->gasMileage
	 << "\n";
}
