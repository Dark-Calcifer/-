#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif  // ��� ������ ������������ ������� ("������������"!_s)

#include<iostream>
#include <Windows.h>
#include "Storage.h"
#include "MyCase.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	MyCase<Storage*> MC;
	for (int i = 0; i < 1; i++)
	{
		Storage storage("1", "2", "3", 4, 5, 6);
		MC.push_back(&storage);
		storage.checkdestr = false;
		MC[0]->ShowInfo();
	}
	MC[0]->ShowInfo();



	return 0;
}