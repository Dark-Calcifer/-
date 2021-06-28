#pragma once

template <typename T>
class MyCase
{
private:
	T* arr;
	int arrSize;
	int counter = 0;

public:
	MyCase();
	~MyCase();

	void push_back(T data);
	void pop_back();
	void pop(int num);
	T operator[] (int index);
	T operator() (int index);
	int size() { return this->arrSize; }

	void sort(int choose);
	T search(int search_ID);
	T search(char* search_name);
	int getcounter() { return this->counter; }
};

template<typename T>
inline MyCase<T>::MyCase()
{
	this->arrSize = 0;
	this->arr = new T[this->arrSize];
}

template<typename T>
inline MyCase<T>::~MyCase()
{
	//for (int i = 0; i < arrSize; i++)
	//{
	//	arr[i]->~Storage();
	//}

	delete[] this->arr;
}

template<typename T>
inline void MyCase<T>::push_back(T data)
{
	counter++;
	arrSize++;

	T* temp = new T[this->arrSize];
	for (int i = 0; i < this->arrSize; i++)
	{
		if (i != this->arrSize - 1)
		{
			temp[i] = this->arr[i];
		}
		else
		{
			temp[i] = data;
			break;
		}
	}
	delete[] this->arr;
	this->arr = temp;
}

template<typename T>
inline void MyCase<T>::pop_back()
{
	arrSize--;
	T* temp = new T[this->arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		temp[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = temp;
}

template<typename T>
inline void MyCase<T>::pop(int num)
{
	arrSize--;
	T* temp = new T[this->arrSize];
	bool checkdel = true;
	for (int i = 0, j = 0; i < arrSize; i++, j++)
	{
		if (j == num - 1)
		{
			i--;
		}
		else
		{
			temp[i] = this->arr[j];
		}
	}
	delete[] this->arr;
	this->arr = temp;
}

template<typename T>
inline T MyCase<T>::operator[](int index)
{
	if (index > (arrSize - 1))
	{
		throw exception("Попытка обращения к неинициализированной памяти");
	}
	else
	{
		return this->arr[index];
	}
}

template<typename T>
inline T MyCase<T>::operator()(int index)
{
	for (int i = 0; i < arrSize; i++)
	{
		int tempID = (*arr[i]).getID();
		if (tempID == index)
		{
			return this->arr[i];
		}
	}
	throw exception("Такого ID нет");
}

template<typename T>
inline void MyCase<T>::sort(int choose)
{
	char* temp1;
	char* temp2;
	int temp3;
	int temp4;
	T temparr;
	switch (choose)
	{
	case 1: // name
	{
		for (int i = 0; i < arrSize - 1; i++)
		{
			for (int j = 0; j < arrSize - 1; j++)
			{
				temp1 = (*arr[j]).getname();
				temp2 = (*arr[j + 1]).getname();
				if (strcmp(temp1, temp2) > 0) // strcmp если 1 > 2, возвращает число больше 0, если меньше - меньше нуля, если равно 0
				{
					temparr = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temparr;
				}
			}
		}
		break;
	}
	case 2: // category
	{
		for (int i = 0; i < arrSize - 1; i++)
		{
			for (int j = 0; j < arrSize - 1; j++)
			{
				temp1 = (*arr[j]).getcategory();
				temp2 = (*arr[j + 1]).getcategory();
				if (strcmp(temp1, temp2) > 0)
				{
					temparr = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temparr;
				}
			}
		}
		break;
	}
	case 3: // data
	{
		for (int i = 0; i < arrSize - 1; i++)
		{
			for (int j = 0; j < arrSize - 1; j++)
			{
				temp1 = (*arr[j]).getdata();
				temp2 = (*arr[j + 1]).getdata();
				if (strcmp(temp1, temp2) > 0)
				{
					temparr = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temparr;
				}
			}
		}
		break;
	}
	case 4: // quantity
	{
		temp3 = 0;
		temp4 = 0;
		for (int i = 0; i < arrSize - 1; i++)
		{
			for (int j = 0; j < arrSize - 1; j++)
			{
				temp3 = (*arr[j]).getquantity();
				temp4 = (*arr[j + 1]).getquantity();
				if (temp3 > temp4)
				{
					temparr = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temparr;
				}
			}
		}
		break;
	}
	case 5: // price
	{
		temp3 = 0;
		temp4 = 0;
		for (int i = 0; i < arrSize - 1; i++)
		{
			for (int j = 0; j < arrSize - 1; j++)
			{
				temp3 = (*arr[j]).getprice();
				temp4 = (*arr[j + 1]).getprice();
				if (temp3 > temp4)
				{
					temparr = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temparr;
				}
			}
		}
		break;
	}
	case 6: // increase
	{
		temp3 = 0;
		temp4 = 0;
		for (int i = 0; i < arrSize - 1; i++)
		{
			for (int j = 0; j < arrSize - 1; j++)
			{
				temp3 = (*arr[j]).getincrease();
				temp4 = (*arr[j + 1]).getincrease();
				if (temp3 > temp4)
				{
					temparr = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temparr;
				}
			}
		}
		break;
	}
	default:
	{
		cout << "(Sort): Введено неверное число. " << endl;
		break;
	}
	break;
	}



}

template<typename T>
inline T MyCase<T>::search(int search_ID)
{
	if (arrSize == 0)
	{
		throw exception("Контейнер пуст.");
	}
	for (int i = 0; i < arrSize - 1; i++)
	{
		if ((*arr[i]).getID() == search_ID)
		{
			return arr[i];
		}
		else
		{
			if (i == arrSize - 1)
			{
				throw exception("Совпадений нет.");
			}
		}
	}
}

template<typename T>
inline T MyCase<T>::search(char* search_name)
{
	if (arrSize == 0)
	{
		throw exception("Контейнер пуст.");
	}
	for (int i = 0; i < arrSize; i++)
	{
		char* A = (*arr[i]).getname();
		string A1 = (*arr[i]).getname();
		string A2 = search_name;
		if (A1 == A2)
		{
			return arr[i];
		}
		else
		{
			if (i == arrSize - 1)
			{
				throw exception("Совпадений нет.");
			}
		}
	}
}

