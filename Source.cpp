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

	//int A[11] = { 12,125,54,4,698,979,654,65834,358, 124,126 };
	//int q = 0;
	//selectionSort(A, 11);
	//while (q != 11)
	//{
	//	cout << A[q] << endl;
	//	q++;
	//}

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
			Storage* storage = new Storage(A, "2", "3", 4, 5, count);
			MC.push_back(storage);
			count++;
			break;
		}
		case 2:
		{
			MC.sort(1);
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

	//for (int i = 0; i < 3; i++)
	//{
	//	try
	//	{
	//		MC[i]->ShowInfo();
	//	}
	//	catch(exception ex)
	//	{
	//		cout << ex.what() << endl;
	//	}
	//}

	cout << endl << "return 0" << endl;
	return 0;
}