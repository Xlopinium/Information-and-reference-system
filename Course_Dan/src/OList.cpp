#pragma once
#include "../include/OList.h"
#include <iomanip> // форматирование таблицы авто

List::Node::Node(Car& value, Node* n)
{
	data = value;
	next = n;
}

List::Node::Node(Node* n)
{
	data = Car();
	data.input();
	next = n;
}


List::List()
{
	size = 0;
	head = nullptr;
}


List::~List()
{
	clear();
}


void List::pushBack()
{
	if (head == nullptr)
		head = new Node();
	else
	{
		for (Node* current = head; ; current = current->next)
			if (current->next == nullptr)
			{
				current->next = new Node();
				break;
			}
	}
	size++;
}

void List::pushBack(Car& value)
{
	if (head == nullptr)
		head = new Node(value);
	else
	{
		for (Node* current = head; ; current = current->next)
			if (current->next == nullptr)
			{
				current->next = new Node(value);
				break;
			}
	}
	size++;
}

void List::pushFront(Car& value)
{
	head = new Node(value, head);
	size++;
}


int List::getSize() const
{
	return size;
}


void List::popFront()
{
	if (size <= 0) return;
	Node* temp = head;
	if (head != nullptr) head = head->next;
	delete temp;
	size--;
}


void List::popBack()
{
	removeAt(size - 1);
}


void List::clear()
{
	while (size) popFront();
}


void List::insert(int index, Car& value)
{
	if (index > size || index < 0)
	{
		string message = "Недопустимый индекс ";
		message.append(to_string(index));
		throw out_of_range(message);
	}
	if (index == 0) pushFront(value);
	else
	{
		Node* previous = head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->next;
		previous->next = new Node(value, previous->next);
		size++;
	}
}


void List::removeAt(int index)
{
	if (index > size - 1 || index < 0)
	{
		string message = "Недопустимый индекс ";
		message.append(to_string(index));
		throw out_of_range(message);
	}
	if (index == 0) popFront();
	else
	{
		Node* previous = head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->next;
		Node* temp = previous->next;
		previous->next = temp->next;
		delete temp;
		size--;
	}
}

void List::show() const
{
	system("CLS");
	showHeaders();
	Node* current = head;
	int counter = 1;
	while (current != nullptr)
	{
		cout << setw(3) << counter;
		current->data.show();
		current = current->next;
		counter++;
	}
}

void List::show(float volume) const
{
	showHeaders();
	Node* current = head;
	int counter = 1;
	while (current != nullptr)
	{
		if (current->data.volume == volume)
		{
			cout << setw(3) << counter;
			current->data.show();
			counter++;
		}
		current = current->next;
	}
}

void List::save()
{
	ofstream fout;
	fout.open("data.txt");
	fout.close();
	try
	{
		fout.open("data.txt", ofstream::app);
		Node* tmp;
		tmp = this->head;
		while (tmp != nullptr)
		{
			fout.write((char*)&tmp->data, sizeof(Car));  // Записать объект класса автомобиля в текстовый файл
			tmp = tmp->next;
		}
	}
	catch (const std::exception&)
	{
		cerr << "Ошибка записи файла.\n";
		system("pause");
	}
	fout.close();
	system("CLS");
	cout << "База данных успешно сохранена!\n";
}

void List::load()
{
	ifstream fin;
	Car current;
	try
	{
		fin.open("data.txt");
		this->clear();
		while (fin.read((char*)&current, sizeof(Car)))  // Считывать объекты классов, пока файл не закончится
		{
			this->pushBack(current);
		}
		fin.close();
	}
	catch (const std::exception&)
	{
		cerr << "Ошибка записи файла.\n";
	}
	system("CLS");
	cout << "База данных успешно загружена!\n";
}

void List::edit()
{
	show();
	int number;
	cout << "Введите номер строки для редактирования: ";
	cin >> number;
	number--;
	int counter = 0;

	Node* current = this->head;

	while (current != nullptr)
	{
		if (counter == number)
		{
			current->data.input();
		}
		current = current->next;
		counter++;
	}
}

void List::filter()
{
	show();
	cout << "Введите объем двигателя: ";
	float volume;
	cin >> volume;
	system("CLS");
	this->show(volume);
}

void List::showMin()
{
	float min = numeric_limits<float>::max();  // Максимальное значение для типа float
	Node* current = this->head;
	while (current != nullptr)
	{
		if (current->data.gasMileage < min) min = current->data.gasMileage;
		current = current->next;
	}
	if (min == numeric_limits<float>::max()) return;  // Если минимум не обновился, выходим из функции
	current = this->head;
	system("CLS");
	cout << "Автомобиль(и) с наименьшим расходом топлива:\n";
	while (current != nullptr)
	{
		if (current->data.gasMileage == min) current->data.show();
		current = current->next;
	}
}

void List::showHeaders() const
{
	cout << setw(3) << left << "№"
		<< setw(14) << "Цена"
		<< setw(14) << "Количество"
		<< setw(18) << "Марка"
		<< setw(14) << "Страна"
		<< setw(6) << "Год"
		<< setw(7) << "Объем"
		<< setw(18) << "Расход бензина"
		<< "\n";
}

void List::add()
{
	Node* tmp = new Node();
	Node* current = this->head;
	int counter = 0;
	while (current != nullptr)
	{
		if (current->data.price > tmp->data.price) break;
		counter++;
		current = current->next;
	}
	insert(counter, tmp->data);
}

void List::remove()
{
	system("CLS");
	show();
	cout << "Введите номер строки для удаления (0 - вернуться): ";
	int number;
	cin >> number;
	if (!number) return;
	removeAt(number - 1);
	system("CLS");
	cout << "Строка №" << number << " удалена.\n";
}
