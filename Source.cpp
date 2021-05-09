#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif  // ��� ������ ������������ ������� ("������������"!_s)

#include<iostream>
#include <Windows.h>
#include "Storage.h"
#include "MyCase.h"
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(3);
	MyCase<Storage*> MC;
	int choose;
	bool check = true;
	bool check_pause = false;
	int count = rand();
	while (check)
	{
		if (check_pause)
		{
			system("pause");
			system("cls");
			check_pause = false;
		}
		cout << "���������� ������� �� ������: " << MC.size() << endl << endl;
		cout << "1) �������� ����� " << endl;
		cout << "2) ������� ���������� � ������� " << endl;
		cout << "3) ������� �����" << endl;
		cout << "4) �������������� �� ���������� " << endl;
		cout << "0) �����\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			const char A[] = { char((rand() % 10) + 48),char((rand() % 10) + 48),char((rand() % 10) + 48), '\0' };
			Storage* storage = new Storage("1", "2" , "3", 4, 5, count);
			MC.push_back(storage);
			count = rand()%100;
			cout << "���������" << endl;
			check_pause = true;
			break;
		}
		case 2:
		{
			for (int i = 0; i < MC.size(); i++)
			{
				try
				{
					MC[i]->ShowInfo();
				}
				catch (exception ex)
				{
					cout << ex.what() << endl;
					check_pause = true;
					break;
				}
			}
			check_pause = true;
			break;
		}
		case 3:
		{
			MC.pop_back();
			cout << "��������� � ������ ����� ��� ������. " << endl;
			check_pause = true;
		}
		case 4:
		{
			cout << "1) �� ������������" << endl;
			cout << "2) �� ���������" << endl;
			cout << "3) �� ���� �����������" << endl;
			cout << "4) �� ���-��" << endl;
			cout << "5) �� ����" << endl;
			cout << "6) �� ��������" << endl;

			int typeofsort = 0;
			cin >> typeofsort;
			MC.sort(typeofsort);
			check_pause = true;
			break;
		}
		case 0:
		{
			check = false;
			break;
		}
		default:
			break;
		}
	}
	//MC.pop_back();

	cout << endl << "return 0" << endl;
	return 0;
}