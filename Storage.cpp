#include "Storage.h"

Storage::Storage()
{
	name = new char('\0');
	category = new char('\0');
	quantity = new char('\0');
	data = new char('\0');
	price = new char('\0');
	increase = new char('\0');
}


void Storage::setname(char* name)
{
	this->name = new char[strlen(name) + 1];
	memcpy(this->name, name, strlen(name) + 1);
}
void Storage::setname(const char name[])
{
	this->name = new char[strlen(name) + 1];
	memcpy(this->name, name, strlen(name) + 1);
}


void Storage::setcategory(char* category)
{
	this->category = new char[strlen(category) + 1];
	memcpy(this->category, category, strlen(category) + 1);
}
void Storage::setcategory(const char category[])
{
	this->category = new char[strlen(category) + 1];
	memcpy(this->category, category, strlen(category) + 1);
}


void Storage::setquantity(char* quantity)
{
	this->quantity = new char[strlen(quantity) + 1];
	memcpy(this->quantity, quantity, strlen(quantity) + 1);
}
void Storage::setquantity(const char quantity[])
{
	this->quantity = new char[strlen(quantity) + 1];
	memcpy(this->quantity, quantity, strlen(quantity) + 1);
}


void Storage::setdata(char* data)
{
	this->data = new char[strlen(data) + 1];
	memcpy(this->data, data, strlen(data) + 1);
}
void Storage::setdata(const char data[])
{
	this->data = new char[strlen(data) + 1];
	memcpy(this->data, data, strlen(data) + 1);
}


void Storage::setprice(char* price)
{
	this->price = new char[strlen(price) + 1];
	memcpy(this->price, price, strlen(price) + 1);
}
void Storage::setprice(const char price[])
{
	this->price = new char[strlen(price) + 1];
	memcpy(this->price, price, strlen(price) + 1);
}


void Storage::setincrease(char* increase)
{
	this->increase = new char[strlen(increase) + 1];
	memcpy(this->increase, increase, strlen(increase) + 1);
}
void Storage::setincrease(const char increase[])
{
	this->increase = new char[strlen(increase) + 1];
	memcpy(this->increase, increase, strlen(increase) + 1);
}


Storage::~Storage()
{
	delete[] name;
	delete[] category;
	delete[] quantity;
	delete[] data;
	delete[] price;
	delete[] increase;
}

