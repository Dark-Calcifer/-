#pragma once

class Storage
{
private:
	char* name; // ������������ 
	char* category; // ��������� 
	char* quantity; // ���-�� 
	char* data; // ���� �����������
	char* price; // ����
	char* increase; // ��������

public:
	Storage(); // ����������� �� ���������
	Storage(int q); // ����������� � �����������
	~Storage(); // ����������

	void ShowName()
	{
		cout << *name << endl;
	}
};

