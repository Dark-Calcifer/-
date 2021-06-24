#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif  // для работы классических функций ("НЕБЕЗОПАСНЫХ" _s)

//12.	Справочник склада.Наименование товара, категория товара, количество, дата поступления, 
//цена и процент торговой надбавки.Сортировка по всем параметрам.Составление фактуры : 
//выбор нескольких товаров, количества(с уменьшением его на складе), 
//подсчет общей суммы и торговой надбавки.
//3. Расширяемый массив указателей на объекты.

#include<iostream>
#include <fstream>
#include <Windows.h>
#include "Storage.h"
#include <regex>

using namespace std;

void PrintLine();
bool IsItInt(char const* A1);
bool true_cin(int& num);

#include "MyCase.h"

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
		cout << "6) Добавить в двоичный файл " << endl;
		cout << "7) Считать из двоичного файла " << endl;
		cout << "8) Включение по номеру " << endl;
		cout << "9) Проверка с типом int " << endl;
		cout << "10) Поиск" << endl;
		cout << "0) Выход\n";
		//cin >> choose;
		if (!true_cin(choose)) { check_pause = true; continue; }
		switch (choose)
		{
		case 1: // Добавить товар
		{
			system("cls");
			{
				const char A1[] = { char((rand() % 25) + 65), char((rand() % 25) + 65),char((rand() % 25) + 65), '\0' };
				const char A2[] = { char((rand() % 25) + 65), char((rand() % 25) + 65),char((rand() % 25) + 65), '\0' };
				const char A3[] = 
				{ char((rand() % 2) + 48),char((rand() % 9) + 48),'.',
				char((rand() % 2) + 48),char((rand() % 9) + 48), '.',
				char((rand() % 2) + 48), char((rand() % 2) + 48), '\0' };
				int count1 = rand() % 100;
				int count2 = rand() % 100;
				int count3 = rand() % 100;
				Storage* storage = new Storage(A1, A2, A3, count1, count2, count3);
				MC.push_back(storage);
				storage->setID(MC.getcounter());
				PrintLine();
				cout << "Добавлено" << endl;
				PrintLine();
				check_pause = true;
			}
			break;
		}
		case 2: // Вывести информацию о товарах
		{
			if (MC.size() != 0)
			{
			system("cls");
			for (int i = 0; i < MC.size(); i++)
			{
				try
				{
					PrintLine();
					MC[i]->ShowInfo();
				}
				catch (exception ex)
				{
					cout << ex.what() << endl;
					check_pause = true;
					break;
				}
			}
			PrintLine();
			check_pause = true;
			}
			else
			{
				system("cls");
				PrintLine();
				cout << "Пусто\n";
				PrintLine();
				check_pause = true;
			}
			break;
		}
		case 3: // Удалить товар
		{
			system("cls");
			for (int i = 0; i < MC.size(); i++)
			{
				try
				{
					PrintLine();
					MC[i]->ShowInfo();
				}
				catch (exception ex)
				{
					cout << ex.what() << endl;
					check_pause = true;
					continue;
				}
			}
			PrintLine();
			if (MC.size() != 0)
			{
				cout << "Введите номер товара (0 - последний)\n";
				int NumToDel;
				if (!true_cin(NumToDel)) { check_pause = true; continue; }
				if (NumToDel == 0)
				{
					system("cls");
					MC.pop_back();
					PrintLine();
					cout << "Последний в списке товар был удален. " << endl;
					PrintLine();
				}
				else
				{
					if (NumToDel > MC.size())
					{
						check_pause = true;
						cout << "Товара с таким номером нет\n";
						break;
					}
					else
					{
						system("cls");
						MC.pop_back(NumToDel);
						PrintLine();
						cout << "Товар под номером " << NumToDel<< " был удален." << endl;
						PrintLine();
					}
				}
				check_pause = true;
			}
			else
			{
				system("cls");
				PrintLine();
				cout << "Нечего удалять\n";
				PrintLine();
				check_pause = true;
			}
			break;
		}
		case 4: // Отстортировать по параметрам
		{
			if(MC.size()!=0)
			{
				system("cls");
				cout << "1) По наименованию" << endl;
				cout << "2) По категории" << endl;
				cout << "3) По дате поступления" << endl;
				cout << "4) По кол-ву" << endl;
				cout << "5) По цене" << endl;
				cout << "6) По надбавке" << endl << endl;

				int typeofsort = 0;
				//cin >> typeofsort;
				if (!true_cin(typeofsort)) { check_pause = true; continue; }
				// СЮДА проверку на [1;6]
				if (typeofsort > 6 || typeofsort < 0)
				{
					cout << "Пункта с таким номером нет, попробуйте еще раз" << endl << endl;
					check_pause = true;
					continue;
				}
				else
				{
					MC.sort(typeofsort);
					system("cls");
					PrintLine();
					cout << "Отсортировано. " << endl;
					PrintLine();
					check_pause = true;
				}
			}
			else
			{
				system("cls");
				PrintLine();
				cout << "Нечего сортировать\n";
				PrintLine();
				check_pause = true;
			}
			break;
		}
		case 5: // Выбрать товар
		{
			if (MC.size() != 0)
			{
				bool checkbuy = true;
				int buy_counter = 0;
				int buy_ID[100];
				int buy_quant[100];
				int overallprice = 0;
				Storage* Object;
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
							PrintLine();
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
						PrintLine();
						cout << "Введите ID товара: " << endl;
						//cin >> buy_ID[buy_counter];
						if (!true_cin(buy_ID[buy_counter])) { check_pause = true; continue; }
						Object = MC(buy_ID[buy_counter]);
						system("cls");

						cout << "Введите колличество (Всего: " << Object->getquantity() << " ):" << endl;
						//cin >> buy_quant[buy_counter];
						if (!true_cin(buy_quant[buy_counter])) { check_pause = true; continue; }

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
						PrintLine();
						cout << ex.what() << endl;
						buy_counter--;
					}

					buy_counter++;

					if (checkbuy == true)
					{
						bool cc = true;
						while (cc)
						{
							PrintLine();
							cout << "Продолжить покупки? (Y/N)" << endl;
							char buy_continue = '0';
							cin >> buy_continue;
							cin.ignore();
							if (buy_continue == 'Y' || buy_continue == 'y')
							{
								cc = false;
								break;
							}
							else if (buy_continue == 'N' || buy_continue == 'n')
							{
								cc = false;
								checkbuy = false;
								break;
							}
							else
							{
								cout << "Введено неверное значение " << endl;
							}
							continue;
						}
					}
				}
				if (checkbuy == false)
				{
					try
					{
						system("cls");
						cout << "Итого: " << endl;
						for (int i = 0; i < buy_counter; i++)
						{
							cout << "-------------------------------------------------------------------" << endl;
							Object = MC(buy_ID[i]);
							cout << "ID: " << Object->getID() << "\tНаименование: " << Object->getname() << "\t" << Object->getprice() << "x" << buy_quant[i] << endl;;
						}
						cout << "-------------------------------------------------------------------" << endl;
						cout << "Общая сумма: " << overallprice << endl;
						check_pause = true;
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
			else
			{
			system("cls");
			PrintLine();
			cout << "Пусто\n";
			PrintLine();
			check_pause = true;
			}
			break;
		}
		case 6: // Добавить в бинарный файл
		{
			if (MC.size() > 0)
			{
				for (int i = 0; i < MC.size(); i++)
				{
					MC[i]->AddToBinary(*MC[i]);
				}
				cout << "\nДобавлено\n";
			}
			else
			{
				cout << "\nНечего добавлять\n";
			}
			check_pause = true;
			break;
		}
		case 7: // Загрузить из бинарного файла
		{		
			Storage Object;
			Object.FromFile(Object);
			check_pause = true;
			break;
		}
		case 8: // Включение по номеру
		{
			system("cls");
			for (int i = 0; i < MC.size(); i++)
			{
				try
				{
					PrintLine();
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
				PrintLine();
				cout << "Введите номер товара:\n";
				int NumToInclude;
				if (!true_cin(NumToInclude)) { check_pause = true; continue; }
				Storage storage;
				*(MC[NumToInclude - 1]) = storage;
				system("cls");
				PrintLine();
				cout << "Новый товар был включен под номером " << NumToInclude << endl;
				PrintLine();
			}
			catch (exception ex)
			{
				cout << ex.what() << endl;
			}
			check_pause = true;
			break;
		}
		case 9: // Проверка типом int
		{
			system("cls");
			MyCase<int> Mint;
			try
			{
				int TEMP_ARR[10];
				PrintLine();
				cout << "Проверка с типом int: " << endl;
				PrintLine();
				for (int i = 0; i < 10; i++)
				{
					TEMP_ARR[i] = rand();
					Mint.push_back(TEMP_ARR[i]);
					cout << "Добавлено: " << Mint[i] << endl;
				}
				PrintLine();
				for (int i = 10; i > 0; i--)
				{
					cout << Mint[i - 1];
					Mint.pop_back();
					cout << " Удалено." << endl;
				}
				PrintLine();

				system("pause");
				system("cls");
			}
			catch (exception ex) { break; }
			break;
		}
		case 10:
		{
			system("cls");
			try
			{
				cout << "По какому критерию найти?" << endl;
				int search_type;
				cout << "1) Поиск по ID" << endl;
				cout << "2) Поиск по названию" << endl;
				if (!true_cin(search_type)) { check_pause = true; continue; }
				if (search_type == 1)
				{
					cout << "Введите ID:" << endl;
					int search_ID;
					if (!true_cin(search_ID)) { check_pause = true; continue; }
					PrintLine();
					(*MC.search(search_ID)).ShowInfo();
					PrintLine();
				}
				if (search_type == 2)
				{
					cout << "Введите название:" << endl;
					char A[100] = "";
					cin.getline(A, 100);
					PrintLine();
					(*MC.search(A)).ShowInfo();
					PrintLine();
				}
			}
			catch (exception ex)
			{
				cout << ex.what() << endl;
			}
			check_pause = true;
			break;
		}
		case 0:
		{
			check = false;
			break;
		}
		default:
			cout << endl << "Такого пункта нет, повторите ввод";
			check_pause = true;
			break;
		}
	}


	cout << endl << "return 0;" << endl;
	return 0;
}

bool IsItInt(char const* A1)
{
	return regex_match(A1, regex("([0-9]*)"));
}

bool true_cin(int& num)
{
	char A1[1000] = "\0";
	cin.getline(A1, 1000);
	cin.clear();
	try
	{
		if (A1[0] == '\0')
		{
			throw exception("Ничего не введено");
		}
		if (IsItInt(A1))
		{
			num = atoi(A1);
			return true;
		}
		else
		{
			throw exception("Введенное значение не является числом");
		}
	}
	catch (exception ex)
	{
		PrintLine();
		cout << ex.what() << endl;
		PrintLine();
		return false;
	}
}

void PrintLine()
{
	cout << "-------------------------------------------------------------------" << endl;
}