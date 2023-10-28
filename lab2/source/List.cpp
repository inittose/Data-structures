#include "List.h"

using std::cout;
using std::endl;

/// <summary>
/// Конструктор списка
/// </summary>
List::List()
{
	_head = nullptr;
	_tail = nullptr;
}

/// <summary>
/// Деструктор
/// </summary>
List::~List()
{
	if (_head)
	{
		ListItem* next = _head;
		ListItem* current;
		while (next)
		{
			current = next;
			next = current->_next;
			delete current;
		}
	}
}

/// <summary>
/// Вставка в начало
/// </summary>
/// <param name="value"> - значение</param>
/// <returns>Этот же объект</returns>
List& List::InsertAtBeginning(const int& value)
{
	ListItem* newElement = new ListItem(value);

	if (_head)
	{
		_head->SetPrev(newElement);
	}
	newElement->SetNext(_head);
	_head = newElement;

	if (!_tail)
	{
		_tail = _head;
	}

	return *this;
}

/// <summary>
/// Вставка в конец
/// </summary>
/// <param name="value"> - значение</param>
/// <returns>Этот же объект</returns>
List& List::InsertAtEnd(const int& value)
{
	ListItem* newElement = new ListItem(value);

	if (_tail)
	{
		_tail->SetNext(newElement);
	}
	newElement->SetPrev(_tail);
	_tail = newElement;

	if (!_head)
	{
		_head = _tail;
	}

	return *this;
}

/// <summary>
/// Вставка после элемента
/// </summary>
/// <param name="value"> - значение</param>
/// <param name="leftValue"> - значение, после которого надо вставить элемент</param>
/// <returns>Этот же объект</returns>
List& List::InsertAfter(const int& value, const int& leftValue)
{
	ListItem* temp = _head;
	while (temp)
	{
		if (temp->_data == leftValue)
		{
			ListItem* newElement = new ListItem(value);
			ListItem* leftItem = temp;
			ListItem* rightItem = temp->_next;
			if (rightItem)
			{
				rightItem->SetPrev(newElement);
			}
			else
			{
				_tail = newElement;
			}
			leftItem->SetNext(newElement);
			newElement->SetPrev(leftItem)->SetNext(rightItem);
		}
		temp = temp->_next;
	}
	return *this;
}

/// <summary>
/// Вставка до элемента
/// </summary>
/// <param name="value"> - значение</param>
/// <param name="index"> - значение, до которого надо вставить элемент</param>
/// <returns>Этот же объект</returns>
List& List::InsertBefore(const int& value, const int& rightValue)
{
	ListItem* temp = _head;
	while (temp)
	{
		if (temp->_data == rightValue)
		{
			ListItem* newElement = new ListItem(value);
			ListItem* leftItem = temp->_prev;
			ListItem* rightItem = temp;
			if (leftItem)
			{
				leftItem->SetNext(newElement);
			}
			else
			{
				_head = newElement;
			}
			rightItem->SetPrev(newElement);
			newElement->SetPrev(leftItem)->SetNext(rightItem);
		}
		temp = temp->_next;
	}
	return *this;
}

/// <summary>
/// Удаление элемента
/// </summary>
/// <param name="index"> - значение</param>
/// <returns>Этот же объект</returns>
List& List::DeleteElement(const int& value)
{
	ListItem* run = _head;
	while (run)
	{
		if (run->_data == value)
		{
			ListItem* temp = run;
			ListItem* leftItem = temp->_prev;
			ListItem* rightItem = temp->_next;
			if (leftItem)
			{
				leftItem->SetNext(rightItem);
			}
			else
			{
				_head = rightItem;
			}
			if (rightItem)
			{
				rightItem->SetPrev(leftItem);
			}
			else
			{
				_tail = leftItem;
			}
			run = run->_next;
			delete temp;
		}
		else
		{
			run = run->_next;
		}
	}
	return *this;
}

/// <summary>
/// Обмен элементами
/// </summary>
/// <param name="fItem"> - Первый элемент</param>
/// <param name="sItem"> - Второй элемент</param>
/// <returns>Этот же объект</returns>
List& List::Swap(ListItem* fItem, ListItem* sItem)
{
	if (fItem == sItem)
	{
		return *this;
	}

	ListItem* fNext = fItem->_next;
	ListItem* fPrev = fItem->_prev;

	ListItem* sNext = sItem->_next;
	ListItem* sPrev = sItem->_prev;

	if (sItem == fNext)
	{
		sItem->SetNext(fItem)->SetPrev(fPrev);
		fItem->SetNext(sNext)->SetPrev(sItem);
		if (fPrev)
		{
			fPrev->SetNext(sItem);
		}
		else
		{
			_head = sItem;
		}
		if (sNext)
		{
			sNext->SetPrev(fItem);
		}
		else
		{
			_tail = fItem;
		}
	}
	else if (fItem == sNext)
	{
		sItem->SetNext(fNext)->SetPrev(fItem);
		fItem->SetNext(sItem)->SetPrev(sPrev);
		if (sPrev)
		{
			sPrev->SetNext(fItem);
		}
		else
		{
			_head = fItem;
		}
		if (fNext)
		{
			fNext->SetPrev(sItem);
		}
		else
		{
			_tail = sItem;
		}
	}
	else
	{
		sItem->SetNext(fNext)->SetPrev(fPrev);
		fItem->SetNext(sNext)->SetPrev(sPrev);
		if (fPrev)
		{
			fPrev->SetNext(sItem);
		}
		else
		{
			_head = sItem;
		}

		if (fNext)
		{
			fNext->SetPrev(sItem);
		}
		else
		{
			_tail = sItem;
		}

		if (sPrev)
		{
			sPrev->SetNext(fItem);
		}
		else
		{
			_head = fItem;
		}

		if (sNext)
		{
			sNext->SetPrev(fItem);
		}
		else
		{
			_tail = fItem;
		}
	}
	return *this;
}

/*

/// <summary>
/// Обмен элементами
/// </summary>
/// <param name="fIndex"> - </param>
/// <param name="sIndex"> - </param>
/// <returns>Этот же объект</returns>
List& List::Swap(const int& fIndex, const int& sIndex)
{
	if (fIndex < 0 || fIndex >= _length || sIndex < 0 || sIndex >= _length)
	{
		cout << "SWAP_EXCEPTION: index out of range\n";
		return *this;
	}
	ListItem* fItem = _head;
	ListItem* sItem = _head;

	for (int i = 0; i < fIndex; i++)
	{
		fItem = fItem->_next;
	}

	for (int i = 0; i < sIndex; i++)
	{
		sItem = sItem->_next;
	}

	return Swap(fItem, sItem);
}

/// <summary>
/// Сортировка
/// </summary>
/// <returns>Этот же объект</returns>
List& List::Sort()
{
	if (!_head)
	{
		cout << "There are no elements!\n";
		return *this;
	}

	for (int i = 0; i < _length; i++)
	{
		for (int j = i; j < _length; j++)
		{
			if ((*this)[i]->_data > (*this)[j]->_data)
			{
				Swap((*this)[i], (*this)[j]);
			}
		}
	}
	return *this;
}

/// <summary>
/// �������� �����
/// </summary>
/// <param name="value"> - ���</param>
/// <returns>������</returns>
int List::LinearSearch(const int& value)
{
	for (int i = 0; i < _length; i++)
	{
		if ((*this)[i]->_data == value)
		{
			return i;
		}
	}

	return -1;
}
*/

/// <summary>
/// Перегрузка оператора потокового вывода
/// </summary>
/// <param name="os"> - объект потокового вывода</param>
/// <param name="list"> - список</param>
/// <returns>Объект потокового вывода</returns>
ostream& operator<<(ostream& os, const List& list)
{
	cout << "Current list: [ ";
	ListItem* temp = list._head;
	int lenght = 0;
	while(temp)
	{
		os << temp->_data << " ";
		temp = temp->_next;
		lenght++;
	}
	os << "]\nLength: " << lenght << endl;
	return os;
}