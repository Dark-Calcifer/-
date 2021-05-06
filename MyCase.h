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
		return this->arr[index];
	}

	int size() { return this->arrSize; }

};