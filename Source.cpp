#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif  // для работы классических функций ("НЕБЕЗОПАСНЫХ"!_s)

#include<iostream>
#include"Storage.h"

using namespace std;

int main()
{
	Storage storage;
	storage.setname("qweqw");
	storage.ShowName();

	return 0;
}