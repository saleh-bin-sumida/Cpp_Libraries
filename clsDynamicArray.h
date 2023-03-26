#pragma once
#include <iostream>
#include "clsDblLinkedList.h" 
using namespace std;

template <class T> 
class clsDaynamicArray
{
protected:
	int _Size;
	T* _TempArray;
public:
	T* OriginalArray ;

	clsDaynamicArray(int Size = 0)	
	{
		if (Size < 0)
			_Size = 0;


		_Size = Size;
		OriginalArray = new T[_Size];
	}

	~clsDaynamicArray()
	{
		delete[] OriginalArray;
	}

	bool SetItem(int index, T value)
	{
		if (index > _Size || index < 0)
			return false;

		OriginalArray[index] = value;
	}

	int Size()
	{
		return _Size;
	}

	bool isEmpty()
	{
		return _Size == 0;
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << "  ";
		}
		cout << "\n";
	}


	void ReSize(int NewSize)
	{
		if (NewSize < 0)
			NewSize = 0;

		_TempArray = new T[NewSize];
		if (NewSize < _Size)
			_Size = NewSize;


		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_Size = NewSize;

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	T GetItem(int index)
	{
		return OriginalArray[index];
	}

	void Revers()
	{
		_TempArray = new T[_Size];
		int counter = 0;
		for (int i = (_Size - 1) ; i >= 0; i--)
		{
			_TempArray[counter] = OriginalArray[i];
			counter ++ ;
		}
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		
	}


	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArray;


	}

	void DeleteItemAt(int index)
	{
		if (index > _Size - 1 || index < 0)
			return ;

		_TempArray = new T[_Size-1];

		for (int i = 0; i < (_Size - 1); i++)
		{
	
			if (i == index || i > index)
			{
				_TempArray[i] = OriginalArray[i+1];

			}
			else
			{
				_TempArray[i] = OriginalArray[i];
			}
		}
		delete[] OriginalArray;
		_Size--;
		OriginalArray = _TempArray;

		// tow loops the first copy the prev value ,
		//the second copy the next values, the deleted element exception;
	
	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size-1);
	}

	int Find(T value)
	{
		for (int i = 0; i < _Size; i++)
		{
			
			if (OriginalArray[i] == value)
				return i;
		}
			return -1;	
	}

	bool DeleteItem(T value)
	{
		int index = Find(value);
		if (index == -1)
			return false;
		DeleteItemAt(Find(value));
		return true;
	}

	bool InsertAt(int index, T value)
	{
		if (index > _Size || index < 0)
			return false;

		_Size++;
		_TempArray = new T[_Size];

		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_TempArray[index] = value;

		for (int i = (index); i < (_Size-1 ); i++)
		{
			_TempArray[i+1] = OriginalArray[i];

		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	void InsertAtBeginning(T value)
	{
		InsertAt(0, value);
	}

	void InsertBefore(int index, T value)
	{
		if (index < 1)
		{
			InsertAt(0, value);
			return;
		}

		InsertAt(index - 1, value);
	}

	bool  InsertAfter(int index, T value)
	{
		if (index >= _Size)
			return InsertAt(_Size , value);
		else
			return InsertAt(index + 1, value);
	}

	void InsertAtEnd(T value)
	{
		InsertAt(_Size, value);
	}

	void UpdateItem(int index, T value)
	{
		SetItem(index, value);
	}
};
	