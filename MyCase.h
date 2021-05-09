#pragma once

template <typename T>
class MyCase
{
private:
	T* arr;
	int arrSize;

public:

	MyCase()
	{
		this->arrSize = 0;
		this->arr = new T[this->arrSize];
	}
	~MyCase()
	{
		for (int i = 0; i < arrSize; i++)
		{
			arr[i]->~Storage();
		}
		delete[] this->arr;
	}

	void push_back(T data)
	{
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

	void pop_back()
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

	T operator[] (int index)
	{
		if (index > (arrSize - 1))
		{
			throw exception("������� ��������� � �������������������� ������");
		}
		else
		{
			return this->arr[index];
		}
	}

	int size() { return this->arrSize; }

	void sort(int choose);

};

template<typename T>
inline void MyCase<T>::sort(int choose)
{
	char* tempname1;
	char* tempname2;
	T temparr;
	switch (choose)
	{
	case 1: // name
		{
			for (int i = 0; i < arrSize - 1; i++)
			{
				for (int j = i; j < arrSize - 1; j++)
				{
					tempname1 = (*arr[j]).getname();
					tempname2 = (*arr[j + 1]).getname();
					if (strcmp(tempname1, tempname2) > 0)
					{
						temparr = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temparr;
					}
				}
			}
		}
	case 2: // category
	{
		for (int i = 0; i < arrSize - 1; i++)
		{
			for (int j = i; j < arrSize - 1; j++)
			{
				tempname1 = (*arr[j]).getcategory();
				tempname2 = (*arr[j + 1]).getcategory();
				if (strcmp(tempname1, tempname2) > 0)
				{
					temparr = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temparr;
				}
			}
		}
	}
	case 3: // data
	{
		for (int i = 0; i < arrSize - 1; i++)
		{
			for (int j = i; j < arrSize - 1; j++)
			{
				tempname1 = (*arr[j]).getdata();
				tempname2 = (*arr[j + 1]).getdata();
				if (strcmp(tempname1, tempname2) > 0)
				{
					temparr = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temparr;
				}
			}
		}
	}
	default:
	{
		cout << "(Sort): ������� �������� �����. " << endl;
		break;
	}
		break;
	}



}

