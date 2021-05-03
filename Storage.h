#pragma once

#include<iostream>
using namespace std;

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
	
	void setname(char* name);
	void setname(const char name[]);

	void setcategory(char* category);
	void setcategory(const char category[]);

	void setquantity(char* quantity);
	void setquantity(const char quantity[]);

	void setdata(char* data);
	void setdata(const char data[]);

	void setprice(char* price);
	void setprice(const char price[]);

	void setincrease(char* increase);
	void setincrease(const char increase[]);


	~Storage(); // Деструктор



	void ShowName()
	{
		cout << name << endl;
	}
};

