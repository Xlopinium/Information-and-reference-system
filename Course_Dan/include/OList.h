#pragma once
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
#include "Car.h"
using namespace std;

class List
{
	class Node
	{
	public:
		Car data;
		Node* next;

		Node(Car& value, Node* n = nullptr);
		Node(Node* n = nullptr);
	};
	Node* head;
	int size = 0;

public:
	List();
	~List();
	void pushBack();
	void pushBack(Car& value);
	void pushFront(Car& value);
	int getSize() const;
	void popFront();
	void popBack();
	void clear();
	void insert(int index, Car& value);
	void removeAt(int index);
	void show() const;
	void show(float volume) const;
	void save();
	void load();
	void edit();
	void filter();
	void showMin();
	void showHeaders() const;
	void add();
	void remove();
};