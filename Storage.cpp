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

Storage::Storage(int q)
{
	name = new char[100];
	*name = q;
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
