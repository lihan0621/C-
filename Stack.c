#include <stdio.h>
#include <stdlib.h>

typedef int STDataType;

//顺序结构实现
typedef struct stack
{
	STDataType* _data;
	int _size;
	int _capacity;
} stack;

//检查容量
void checkCapacity(stack* st)
{
	if (st->_size == st->_capacity)
	{
		int newCapacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (STDataType*)realloc(st->_data, sizeof(STDataType) * newCapacity);
		st->_capacity = newCapacity;
	}
}

//栈的初始化
void stackInit(stack* st)
{
	if (st == NULL)
		return;
	st->_data = NULL;
	st->_capacity = st->_size = 0;
}

//入栈
void stackPush(stack* st, STDataType val)
{
	if (st == NULL)
		return;
	checkCapacity(&st);
	//尾插
	st->_data[st->_size++] = val;
}

//出栈
void stackPop(stack* st)
{
	if (st == NULL);
	//尾删
	if (st->_size > 0)
		st->_size--;
}

//获取栈顶元素
STDataType stackTop(stack* st)
{
	return st->_data[st->_size - 1];
}

//判断栈是否为空
int stackEmpty(stack* st)
{
	if (st == NULL || st->_size == 0)
		return 1;
	else
		return 0;
}