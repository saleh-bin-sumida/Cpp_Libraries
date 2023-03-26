#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList <T> _MyList;

public:
	 int Size()
	{
		return _MyList.Size();
	}

	void Push(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	void Pop()
	{
		_MyList.DeleteFirstNode();
	}

	T Front()
	{
		return _MyList.GetItem(0);
	}

	T Back()
	{
		return _MyList.GetItem(Size() - 1);

	}

	void PrintList()
	{
		_MyList.PrintList();
	}

	T GetItem(int index)
	{

		return _MyList.GetItem(index);
	}

	void InsertAtFront(T value)
	{
		_MyList.InsertAtBeginning(value);
	}

	void InsertAtBack(T value)
	{
		_MyList.InsertAtEnd();
	}

	bool InsertAfter(int index, T value)
	{
		return _MyList.InsertAfter(value);
	}

	void DeleteAtEnd()
	{
		_MyList.DeleteLastNode();
	}

	void UpdateItem(int index,T value)
	{

		_MyList.UpdateItem(index, value);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void Clear()
	{
		_MyList.Clear();
	}
};	