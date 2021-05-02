#pragma once

class Storage
{
private:
	char* name; // Наименование 
	char* category; // Категория 
	char* quantity; // Кол-во 
	char* data; // Дата поступления
	char* price; // Цена
	char* increase; // Надбавка

public:
	Storage(); // Конструктор по умолчанию
	Storage(int q); // Конструктор с параметрами
	~Storage(); // Деструктор

	void ShowName()
	{
		cout << *name << endl;
	}
};

