#pragma once
#include "../include/Car.h"
#include <iostream>
#include <iomanip>	// �������������� ������� ����
using namespace std;

void Car::input()
{
	cout << "����:\t";
	float value;
	cin >> value;
	if (this->price == value)
	{
		cout << "\n���� �������� ��� ���������.\n";
		return;
	}
	else
	{
		this->price = value;
		cout << "���-��:\t";
		cin >> this->amount;
		cout << "�����:\t";
		cin >> this->brand;
		cout << "������:\t";
		cin >> this->country;
		cout << "���:\t";
		cin >> this->year;
		cout << "����� ���������:\t";
		cin >> this->volume;
		cout << "������ �������:\t";
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
