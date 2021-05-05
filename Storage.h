#pragma once

#include<iostream>
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

	char* getname() { return this->name; };
	char* getcategory() { return this->category; };
	char* getdata() { return this->data; };
	int getquantity() { return *(this->quantity); };
	int getprice() { return *(this->price); };
	int getincrease() { return *(this->increase); };


	~Storage(); // ����������


	void ShowInfo()
	{
		cout << "���: " << name << endl;
		cout << "���������: " << category << endl;
		cout << "���� �����������: " << data << endl;
		cout << "���-��: " << *quantity << endl;
		cout << "����: " << *price << endl;
		cout << "��������: " << *increase << endl << endl;
	}
};

