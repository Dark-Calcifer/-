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
	//vector<Storage*> MC;
	int choose;
	bool a = true;
	int count = 1;
	while (a)
	{
		cout << "choose: " << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			const char A[] = { char((rand() % 10) + 48),char((rand() % 10) + 48),char((rand() % 10) + 48), '\0' };
			Storage* storage = new Storage("1", A , "3", 4, 5, count);
			MC.push_back(storage);
			count++;
			break;
		}
		case 2:
		{
			MC.sort(2);
			break;
		}
		case 3:
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
					break;
				}
			}
			break;
		}
		case 0:
		{
			a = false;
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