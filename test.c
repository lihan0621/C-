#include <stdio.h>
#include <stdlib.h>

//假设小堆
typedef int HDataType;

typedef struct heap
{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;

//堆的初始化
void heapInit(heap* hp)
{
	if (hp == NULL)
		return;
	hp->_data = NULL;
	hp->_size = hp->_capacity = 0;
}

//检查容量
void checkCapacity(heap* hp)
{
	if (hp->_size == hp->_capacity)
	{
		int newC = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType) * newC);
		hp->_capacity = newC;
	}
}

//交换
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//堆的插入
void heapPush(heap* hp, HDataType val)
{
	if (hp == NULL)
		return;
	//检查容量
	checkCapacity(hp);
	//尾插
	hp->_data[hp->_size++] = val;
	//向上调整
	shiftUp(hp->_data, hp->_size, hp->_size - 1);
}

//堆的删除
void heapPop(heap* hp)
{
	if (hp->_size > 0)
	{
		//交换
		Swap(&hp->_data[0], &hp->_data[hp->_size - 1]);
		//尾删
		hp->_size--;
		//从堆顶位置开始向下调整
		shiftDown(hp->_data, hp->_size, 0);
	}
}

//获取堆顶元素
HDataType heapTop(heap* hp)
{
	return hp->_data[0];
}

//堆的判空
int heapEmpty(heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return 1;
	else
		return 0;
}

//向下调整
void shiftDown(int* arr, int n, int cur)
{
	//找到孩子的位置
	//左孩子
	int child = 2 * cur + 1;
	while (child < n)
	{
		//从左右孩子中找一个最小的
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		//和当前数据比较
		//1.调整: 孩子 < 当前
		if (arr[child] < arr[cur])
		{
			int tmp = arr[child];
			arr[child] = arr[cur];
			arr[cur] = tmp;
		}
		else
			//2.不调整: 孩子 >= 当前
			break;
	}
}

//向上调整
void shiftUp(int* arr, int n, int cur)
{
	//和父节点进行比较
	int parent = (cur - 1) / 2;
	while (cur > 0)
	{
		if (arr[cur] < arr[parent])
		{
			int tmp = arr[cur];
			arr[cur] = arr[parent];
			arr[parent] = tmp;
			//更新位置
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
	//建堆: 从最后一个非叶子节点开始: 向下调整
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