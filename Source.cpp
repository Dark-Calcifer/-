#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif  // для работы классических функций ("НЕБЕЗОПАСНЫХ"!_s)

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
	while (check)
	{
		if (check_pause)
		{
			cout << endl;
			system("pause");
			system("cls");
			check_pause = false;
		}
		cout << "Количество товаров на складе: " << MC.size() << endl << endl;
		cout << "1) Добавить товар " << endl;
		cout << "2) Вывести информацию о товарах " << endl;
		cout << "3) Удалить товар" << endl;
		cout << "4) Отстортировать по параметрам " << endl;
		cout << "0) Выход\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			system("cls");
			const char A1[] = { char((rand() % 10) + 48),char((rand() % 10) + 48),char((rand() % 10) + 48), '\0' };
			const char A2[] = { char((rand() % 10) + 48),char((rand() % 10) + 48),char((rand() % 10) + 48), '\0' };
			const char A3[] = { char((rand() % 10) + 48),char((rand() % 10) + 48),char((rand() % 10) + 48), '\0' };
			int count1 = rand() % 100;
			int count2 = rand() % 100;
			int count3 = rand() % 100;
			Storage* storage = new Storage(A1, A2, A3, count1, count2, count3);
			MC.push_back(storage);
			cout << "Добавлено" << endl;
			check_pause = true;
			break;
		}
		case 2:
		{
			system("cls");
			for (int i = 0; i < MC.size(); i++)
			{
				try
				{
					cout << "-------------------------------------------------------------------" << endl;
					MC[i]->ShowInfo();
				}
				catch (exception ex)
				{
					cout << ex.what() << endl;
					check_pause = true;
					break;
				}
			}
			cout << "-------------------------------------------------------------------" << endl;
			check_pause = true;
			break;
		}
		case 3:
		{
			system("cls");
			MC.pop_back();
			cout << "Последний в списке товар был удален. " << endl;
			check_pause = true;
			break;
		}
		case 4:
		{
			system("cls");
			cout << "1) По наименованию" << endl;
			cout << "2) По категории" << endl;
			cout << "3) По дате поступления" << endl;
			cout << "4) По кол-ву" << endl;
			cout << "5) По цене" << endl;
			cout << "6) По надбавке" << endl;

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