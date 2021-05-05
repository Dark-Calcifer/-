#pragma once

#include<iostream>
using namespace std;

class Storage
{
private:
	char* name; // Наименование 
	char* category; // Категория 
	char* data; // Дата поступления
	int* quantity; // Кол-во 
	int* price; // Цена
	int* increase; // Надбавка

public:
	Storage(); // Конструктор по умолчанию
	Storage(char* name, char* category, char* data, int quantity, int price, int increase); // Конструктор с параметрами
	Storage(const char name[], const char category[], const char data[], const int quantity, const int prise, const int increase); // Конструктор с параметрами
	Storage(const Storage& Object); // Конструктор копирования
	
	void setname(char* name);
	void setname(const char name[]);

	void setcategory(char* category);
	void setcategory(const char category[]);

	void setdata(char* data);
	void setdata(const char data[]);

	void setquantity(int* quantity);
	void setquantity(const int quantity);

	void setprice(int* price);
	void setprice(const int price);

	void setincrease(int* increase);
	void setincrease(const int increase);

	char* getname() { return this->name; };
	char* getcategory() { return this->category; };
	char* getdata() { return this->data; };
	int getquantity() { return *(this->quantity); };
	int getprice() { return *(this->price); };
	int getincrease() { return *(this->increase); };


	~Storage(); // Деструктор


	void ShowInfo()
	{
		cout << "Имя: " << name << endl;
		cout << "Категория: " << category << endl;
		cout << "Дата поступления: " << data << endl;
		cout << "Кол-во: " << *quantity << endl;
		cout << "Цена: " << *price << endl;
		cout << "Надбавка: " << *increase << endl << endl;
	}
};

