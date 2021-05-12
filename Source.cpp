#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif  // для работы классических функций ("НЕБЕЗОПАСНЫХ"!_s)

#include<iostream>
#include <Windows.h>
#include "Storage.h"
#include "MyCase.h"
#include <regex>

using namespace std;

bool IsItInt(char const* A1);

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
		cout << "5) Выбрать товар " << endl;
		cout << "0) Выход\n";
		//cin >> choose;
		char A1[100] = "\0";
		cin.getline(A1, 100);
		try
		{
			if (IsItInt(A1))
			{
				choose = atoi(A1);
			}
			else
			{
				throw exception("Введенное значение не является числом");
				break;
			}
		}
		catch (exception ex)
		{
			cout << ex.what() << endl;
			check_pause = true;
			break;
		}

		switch (choose)
		{
		case 1:
		{
			system("cls");
			const char A1[] = { char((rand() % 25) + 65), char((rand() % 25) + 65),char((rand() % 25) + 65), '\0' };
			const char A2[] = { char((rand() % 25) + 65), char((rand() % 25) + 65),char((rand() % 25) + 65), '\0' };
			const char A3[] = { char((rand() % 2) + 48),char((rand() % 9) + 48), '.' ,char((rand() % 2) + 48),char((rand() % 9) + 48), '.' ,char((rand() % 2) + 48),char((rand() % 10) + 48), '\0' };
			int count1 = rand() % 100;
			int count2 = rand() % 100;
			int count3 = rand() % 100;
			Storage* storage = new Storage(A1, A2, A3, count1, count2, count3);
			MC.push_back(storage);
			cout << "-------------------------------------------------------------------" << endl;
			cout << "Добавлено" << endl;
			cout << "-------------------------------------------------------------------" << endl;
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
			cout << "-------------------------------------------------------------------" << endl;
			cout << "Последний в списке товар был удален. " << endl;
			cout << "-------------------------------------------------------------------" << endl;
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
			//cin >> typeofsort;
			char A1[100] = "\0";
			cin.getline(A1, 100);
			try
			{
				if (IsItInt(A1))
				{
					typeofsort = atoi(A1);
				}
				else
				{
					throw exception("Введенное значение не является числом");
					break;
				}
			}
			catch (exception ex)
			{
				cout << ex.what() << endl;
				check_pause = true;
				break;
			}

			MC.sort(typeofsort);
			check_pause = true;
			break;
		}
		case 5:
		{
			bool checkbuy = true;
			int buy_counter = 0;
			int buy_ID[100];
			int buy_quant[100];
			int overallprice = 0;
			auto Object = MC[0];
			while (checkbuy)
			{
				if (check_pause)
				{
					cout << endl;
					system("pause");
					system("cls");
					check_pause = false;
				}
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
						continue;
					}
				}
				try
				{
					cout << "-------------------------------------------------------------------" << endl;
					cout << "Введите ID товара: " << endl;
					cin >> buy_ID[buy_counter];
					Object = MC(buy_ID[buy_counter]);
					system("cls");
					cout << "Введите колличество (Всего: " << Object->getquantity() << " ):" << endl;
					cin >> buy_quant[buy_counter];
					//проверка на кол-во
					int tempquantity = Object->getquantity();
					if (tempquantity >= buy_quant[buy_counter])
					{
						overallprice = overallprice + (Object->getprice() * buy_quant[buy_counter]);
						system("cls");
						cout << "Вы выбрали: " << Object->getname() << endl;;
						cout << "Кол-во: " << buy_quant[buy_counter] << endl;;
						cout << "Общая стоймость: " << overallprice << endl;
						Object->setquantity(tempquantity - buy_quant[buy_counter]);
					}
					else
					{
						throw exception("Недостаточно товара на складе");
					}
				}
				catch (exception ex)
				{
					cout << ex.what() << endl;
					cout << "Продолжить покупки?" << endl;
					cout << "1) Да" << endl;
					cout << "2) Нет" << endl;
					int extemp = 0;
					cin >> extemp;
					if (extemp == 2)
					{
						continue;
					}
					else if (extemp == 1)
					{
						continue;
					}
				}
				buy_counter++;
				cout << "Продолжить покупки?" << endl;
				cout << "1) Да" << endl;
				cout << "2) Нет" << endl;
				int buy_continue = 0;
				cin >> buy_continue;
				if (buy_continue == 2)
				{
					checkbuy = false;
					continue;
				}
				else if (buy_continue == 1)
				{
					continue;
				}
				continue;
			}
			if (checkbuy == false)
			{
				try
				{
					cout << "Итого: " << endl;
					for (int i = 0; i < buy_counter; i++)
					{
						cout << "-------------------------------------------------------------------" << endl;
						Object = MC(buy_ID[i]);
						cout << "ID: " << Object->getID()<< "\tНаименование: " << Object->getname() << "\t"<< Object->getprice() <<"x" << buy_quant[i] << endl;;
					}
					cout << "-------------------------------------------------------------------" << endl;
					cout << "Общая сумма: " << overallprice << endl;
					break;
				}
				catch (exception ex)
				{
					cout << ex.what() << endl;
					check_pause = true;
					continue;
				}
			}
			else
			{
				check_pause = true;
				break;
			}
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

bool IsItInt(char const* A1)
{
	return regex_match(A1, regex("([0-9]*)"));
}