#include "Storage.h"

Storage::Storage()
{
	name = new char('\0');
	category = new char('\0');
	data = new char('\0');
	quantity = new int(0);
	price = new int(0);
	increase = new int(0);
}

Storage::Storage(char* name, char* category, char* data, int quantity, int price, int increase)
{
	setname(name);
	setcategory(category);
	setdata(data);
	setquantity(quantity);
	setprice(price);
	setincrease(increase);
}

Storage::Storage(const char name[], const char category[], const char data[], const int quantity, const int price, const int increase)
{
	setname(name);
	setcategory(category);
	setdata(data);
	setquantity(quantity);
	setprice(price);
	setincrease(increase);
}

Storage::Storage(const Storage& Object)
{
	name = new char[strlen(Object.name) + 1];
	memcpy(this->name, Object.name, strlen(Object.name) + 1);

	category = new char[strlen(Object.category) + 1];
	memcpy(this->category, Object.category, strlen(Object.category) + 1);

	data = new char[strlen(Object.data) + 1];
	memcpy(this->data, Object.data, strlen(Object.data) + 1);

	this->quantity = new int(*Object.quantity);
	this->price = new int(*Object.price);
	this->increase = new int(*Object.increase);

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


void Storage::setquantity(int* quantity)
{
	this->quantity = new int(*quantity);
}
void Storage::setquantity(const int quantity)
{
	this->quantity = new int(quantity);
}


void Storage::setprice(int* price)
{
	this->price = new int(*price);
}
void Storage::setprice(const int price)
{
	this->price = new int(price);
}


void Storage::setincrease(int* increase)
{
	this->increase = new int(*increase);
}
void Storage::setincrease(const int increase)
{
	this->increase = new int(increase);
}


char* Storage::getname()
{
	return this->name;
}

char* Storage::getcategory()
{
	return this->category;
}

char* Storage::getdata()
{
	return this->data;
}

int Storage::getquantity()
{
	return *(this->quantity);
}

int Storage::getprice()
{
	return *(this->price);
}

int Storage::getincrease()
{
	return *(this->increase);
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

