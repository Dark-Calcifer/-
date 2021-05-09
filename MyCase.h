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
			throw exception("Попытка обращения к неинициализированной памяти");
		}
		else
		{
			return this->arr[index];
		}
	}

	int size() { return this->arrSize; }

	void sort(const char type[]);

};

template<typename T>
inline void MyCase<T>::sort(const char type[])
{
	char* tempname1;
	char* tempname2;
	T temparr;
	//for (int i1 = 0; i1 < arrSize - 1; i1++)
	//{
	//	tempname1 = (*arr[i1]).getname();
	//	tempname2 = (*arr[i1 + 1]).getname();
	//	if (tempname1[0] > tempname2[0])
	//	{
	//		temparr = arr[i1];
	//		arr[i1] = arr[i1 + 1];
	//		arr[i1 + 1] = temparr;
	//	}
	//}
	if (type == "1")
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



}



void sort_p(char** ptr, int size) 
{
	for (int i = 0; i < size - 1; i++) 
	{
		for (int j = i + 1; j < size; j++) 
		{
			if (*ptr[j] < *ptr[i]) 
			{
				char* tmp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = tmp;
			}
		}
	}
}

void selectionSort(int arr[], int arrSize)
{
	int j = 0;
	int tmp = 0;
	for (int i = 0; i < arrSize; i++)
	{
		j = i;
		for (int k = i; k < arrSize; k++)
		{
			if (arr[j] > arr[k]) {
				j = k;
			}
		}
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}
