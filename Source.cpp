#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif  // для работы классических функций ("НЕБЕЗОПАСНЫХ"!_s)

using namespace std;

#include<iostream>
#include"Storage.h"

int main()
{
	Storage Temp(9);
	Temp.ShowName();

	return 0;
}