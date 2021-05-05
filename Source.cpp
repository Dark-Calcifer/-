#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif  // для работы классических функций ("НЕБЕЗОПАСНЫХ"!_s)

#include<iostream>
#include <Windows.h>
#include"Storage.h"

using namespace std;

void Foo(Storage& A)
{
	A.ShowInfo();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Storage storage("1", "2", "3", 4, 5, 6);



	return 0;
}