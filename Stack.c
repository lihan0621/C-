#include <stdio.h>
#include <stdlib.h>

typedef int STDataType;

//˳��ṹʵ��
typedef struct stack
{
	STDataType* _data;
	int _size;
	int _capacity;
} stack;

//�������
void checkCapacity(stack* st)
{
	if (st->_size == st->_capacity)
	{
		int newCapacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (STDataType*)realloc(st->_data, sizeof(STDataType) * newCapacity);
		st->_capacity = newCapacity;
	}
}

//ջ�ĳ�ʼ��
void stackInit(stack* st)
{
	if (st == NULL)
		return;
	st->_data = NULL;
	st->_capacity = st->_size = 0;
}

//��ջ
void stackPush(stack* st, STDataType val)
{
	if (st == NULL)
		return;
	checkCapacity(&st);
	//β��
	st->_data[st->_size++] = val;
}

//��ջ
void stackPop(stack* st)
{
	if (st == NULL);
	//βɾ
	if (st->_size > 0)
		st->_size--;
}

//��ȡջ��Ԫ��
STDataType stackTop(stack* st)
{
	return st->_data[st->_size - 1];
}

//�ж�ջ�Ƿ�Ϊ��
int stackEmpty(stack* st)
{
	if (st == NULL || st->_size == 0)
		return 1;
	else
		return 0;
}