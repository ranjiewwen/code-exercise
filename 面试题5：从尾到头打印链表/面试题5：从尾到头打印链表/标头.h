#pragma once
#include<iostream>
using namespace std;

typedef int DataType;
struct ListNode
{
	DataType _data;
	struct ListNode *_next;

	ListNode(const DataType& x)
		:_data(x)
		, _next(NULL)
	{
	}
};

class List
{
public:
	List()
		:_head(NULL)
		, _tail(NULL)
	{

	}
	List(const List& l)
	{
		_head = new struct ListNode(l._head->_data);
		_tail = _head;
		struct ListNode *cur = l._head->_next;
		while (cur)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}//拷贝构造
	~List()
	{
		struct ListNode *del = _head;
		ListNode *begin = _head;
		while (begin)
		{
			del = begin;
			begin = begin->_next;
			delete del;
		}
	}
	void PushBack(DataType x)
	{
		struct ListNode *tmp = new ListNode(x);
		if (_head)
		{
			_tail->_next = tmp;
			_tail = _tail->_next;
		}
		else
		{
			_head = tmp;
			_tail = _head;
		}
	}
	void display()
	{
		struct ListNode *cur = _head;
		while (cur)
		{
			cout << cur->_data << "->";
			cur = cur->_next;
		}
		cout << endl;
	}
	void PopBack()
	{
		//1.没有节点
		if (_head == NULL)
		{
			cout << "已经没有数据了" << endl;
			return ;
		}
		//2.只有一个节点
		if (_head->_next == NULL)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
		}
		//3.一个或者以上节点
		ListNode *tmp = _tail;

	}
	ListNode &Find()
	{

	}
	void Insert(ListNode *pos, const DataType x)
	{

	}
	void Erase(ListNode *pos)
	{

	}
	void Swap(List &l)
	{
		swap(_head, l._head);
		swap(_tail, l._tail);
	}

	List&  operator=(List l)
	{
		//可以调用clear 或者是用swap 或 者是这么写
		Swap(l);
		return *this;
	}


	void Clear()
	{
		struct ListNode* begin = _head;
		while (begin)
		{
			_head = _head->_next;
			delete begin;
		}
		_head = _tail = NULL;
	}

	void merge()//接合
	{

	}
	void Reverse()
	{
		ListNode *newhead = NULL;
		ListNode *cur = _head;
		while (cur)
		{
			ListNode *tmp = cur;
			cur = cur->_next;
			tmp->_next = newhead;
			newhead = tmp;
		}
		_head = newhead;
	}
private:
	struct ListNode *_head;
	struct ListNode *_tail;
};



void test()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	l.display();
	l.Reverse();
	l.display();
}