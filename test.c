#include <stdio.h>
#include <stdlib.h>

//����С��
typedef int HDataType;

typedef struct heap
{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;

//�ѵĳ�ʼ��
void heapInit(heap* hp)
{
	if (hp == NULL)
		return;
	hp->_data = NULL;
	hp->_size = hp->_capacity = 0;
}

//�������
void checkCapacity(heap* hp)
{
	if (hp->_size == hp->_capacity)
	{
		int newC = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType) * newC);
		hp->_capacity = newC;
	}
}

//����
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//�ѵĲ���
void heapPush(heap* hp, HDataType val)
{
	if (hp == NULL)
		return;
	//�������
	checkCapacity(hp);
	//β��
	hp->_data[hp->_size++] = val;
	//���ϵ���
	shiftUp(hp->_data, hp->_size, hp->_size - 1);
}

//�ѵ�ɾ��
void heapPop(heap* hp)
{
	if (hp->_size > 0)
	{
		//����
		Swap(&hp->_data[0], &hp->_data[hp->_size - 1]);
		//βɾ
		hp->_size--;
		//�ӶѶ�λ�ÿ�ʼ���µ���
		shiftDown(hp->_data, hp->_size, 0);
	}
}

//��ȡ�Ѷ�Ԫ��
HDataType heapTop(heap* hp)
{
	return hp->_data[0];
}

//�ѵ��п�
int heapEmpty(heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return 1;
	else
		return 0;
}

//���µ���
void shiftDown(int* arr, int n, int cur)
{
	//�ҵ����ӵ�λ��
	//����
	int child = 2 * cur + 1;
	while (child < n)
	{
		//�����Һ�������һ����С��
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		//�͵�ǰ���ݱȽ�
		//1.����: ���� < ��ǰ
		if (arr[child] < arr[cur])
		{
			int tmp = arr[child];
			arr[child] = arr[cur];
			arr[cur] = tmp;
		}
		else
			//2.������: ���� >= ��ǰ
			break;
	}
}

//���ϵ���
void shiftUp(int* arr, int n, int cur)
{
	//�͸��ڵ���бȽ�
	int parent = (cur - 1) / 2;
	while (cur > 0)
	{
		if (arr[cur] < arr[parent])
		{
			int tmp = arr[cur];
			arr[cur] = arr[parent];
			arr[parent] = tmp;
			//����λ��
			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
			break;
	}
}

//void test()
//{
//	int arr[] = { 10, 5, 3, 8, 7, 6 };
//	shiftDown(arr, sizeof(arr) / sizeof(arr[0]), 0);
//}

void test()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//����: �����һ����Ҷ�ӽڵ㿪ʼ: ���µ���
	for (int i = ((n - 2) / 2); i >= 0; --i)
	{
		shiftDown(arr, n, i);
	}
}

int main()
{
	test();
	return 0;
}