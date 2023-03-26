#pragma once
#include<iostream>
#include "clsDynamicArray.h"

template<class T> 
class clsMyQueueArr
{
protected:
	clsDaynamicArray<T> _Array;
public:

	int Size()
	{
		
		return _Array.Size();
	}

	void push(T value)
	{
		_Array.InsertAtEnd(value);
	}

	bool IsEmpty()
	{
		return _Array.isEmpty();
	}
	void pop()
	{
		_Array.DeleteFirstItem();
	}

	T front()
	{
		return _Array.GetItem(0);
	}

	T back()
	{
		return _Array.GetItem(Size() - 1);

	}
	void Print()
	{
		_Array.PrintList();
	}

	T GetItem(int index)
	{

		return _Array.GetItem(index);
	}
	void Reverse()
	{
		_Array.Revers();
	}

	void Clear()
	{
		_Array.Clear();
	}
	void InsertAtFront(T value)
	{
		_Array.InsertAtBeginning(value);
	}

	void InsertAtBack(T value)
	{
		_Array.InsertAtEnd(value);
	}

	bool InsertAfter(int index, T value)
	{
		return _Array.InsertAfter(index,value);
	}
	
	void UpdateItem(int index, T value)
	{
		_Array.UpdateItem(index, value);
	}
};


