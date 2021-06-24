#pragma once

#include<iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

class Storage
{
private:
	char* name; // ������������ 
	char* category; // ��������� 
	char* data; // ���� �����������
	int* quantity; // ���-�� 
	int* price; // ����
	int* increase; // ��������
	int ID;

public:
	Storage(); // ����������� �� ���������
	Storage(char* name, char* category, char* data, int quantity, int price, int increase); // ����������� � �����������
	Storage(const char name[], const char category[], const char data[], const int quantity, const int prise, const int increase); // ����������� � �����������
	Storage(const Storage& Object); // ����������� �����������
	
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

	void setID(int id) { this->ID = id; }

	char* getname() { return this->name; };
	char* getcategory() { return this->category; };
	char* getdata() { return this->data; };
	int getquantity() { return *(this->quantity); };
	int getprice() { return *(this->price); };
	int getincrease() { return *(this->increase); };

	int getID() { return ID; };

	void operator= (Storage& Object);

	bool checkdestr = true;

	~Storage(); // ����������

	void ShowInfo()
	{
		cout << "ID: " << ID << endl;
		cout << "������������: " << name << endl;
		cout << "���������: " << category << endl;
		cout << "���� �����������: " << data << endl;
		cout << "���-��: " << *quantity << endl;
		cout << "����: " << *price << endl;
		cout << "��������: " << *increase << endl;
	}
	void AddToBinary(Storage& Object)
	{
		ofstream emp_file;
		emp_file.open("Storage.dat", ios::binary);
		if (emp_file.is_open())
		{
		emp_file.write((char*)Object.name, sizeof(Object.name));
		emp_file.write((char*)Object.category, sizeof(Object.category));
		emp_file.write((char*)Object.data, 9);
		emp_file.write((char*)Object.quantity, sizeof(Object.quantity));
		emp_file.write((char*)Object.price, sizeof(Object.price));
		emp_file.write((char*)Object.increase, sizeof(Object.increase));
		emp_file.close();
		}
		else
		{
			cout << "���� �� ��� �������." << endl;
		}
	}

	void FromFile(Storage& Object)
	{
		ifstream emp_file("Storage.dat");
		if (emp_file.is_open())
		{
			emp_file.read((char*)Object.name, sizeof(Object.name));
			emp_file.read((char*)Object.category, sizeof(Object.category));
			emp_file.read((char*)(Object.data), 9);
			emp_file.read((char*)Object.quantity, sizeof(Object.quantity));
			emp_file.read((char*)Object.price, sizeof(Object.price));
			emp_file.read((char*)Object.increase, sizeof(Object.increase));
			emp_file.close();
			Object.ShowInfo();
			Object.checkdestr = false;
		}
		else
		{
			cout << "���� �� ��� �������." << endl;
		}
	}
};

