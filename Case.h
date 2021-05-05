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

	T operator[] (int index) 
	{ 
		return this->arr[index];
	}

	int size() { return this->arrSize; }

};