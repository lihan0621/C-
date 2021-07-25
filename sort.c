#include <stdio.h>

//插入排序
void insertSort(int* arr, int n)
{
	//假设第一个数据有序
	//未插入的数据[1, n)
	for (int i = 1; i < n; ++i)
	{
		//从有序数据的最后一个位置向前遍历
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] >= data)
		{
			//大的数据向后移动
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = data;
	}
}

//希尔排序
void shellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//最后一趟排序, 间隔必须是1, 保证所有数据都在同一组
		//一趟希尔排序
		for (int i = gap; i < n; ++i)
		{
			//同一组数据, 最后一个有序数据的位置
			int end = gap - 1;
			//待插入的数据
			int data = arr[i];
			while (end >= 0 && arr[end] > data)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}

void Swap(int* arr, int pos1, int pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

//选择排序
void selectSort(int* arr, int n)
{
	//从未排序的序列中找最值存放到未排序的起始位置
	//未排序的区间: [start, end]
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		//找到最小值的位置
		int minidx = start;
		int i;
		for (i = start + 1; i <= end; ++i)
		{
			if (arr[i] < arr[minidx])
				minidx = i;
		}
		//把最小值放到最开始的位置
		Swap(arr, start, minidx);
		//剩余的未排序的空间[start + 1, end]
		++start;
	}
}

void selectSort2(int* arr, int n)
{
	int start = 0;
	int end = n - 1;
	//每次从未排序的区间找到一个最小值和一个最大值
	//最小值放在头部, 最大值放在尾部
	//遍历的次数减少一半
	while (start < end)
	{
		int minidx = start;
		int maxidx = start;
		for (int j = start + 1; j <= end; ++j)
		{
			if (arr[j] < arr[minidx])
				minidx = j;
			if (arr[j] > arr[maxidx])
				maxidx = j;
		}
		//最小值放在头部
		Swap(arr, start, minidx);
		//判断最大值的位置是否在起始位置
		if (maxidx == start)
			maxidx = minidx;
		//最大值放在尾部
	
		Swap(arr, end, maxidx);
		++start;
		--end;
	}
}

//冒泡排序
void bubbleSort(int* arr, int n)
{
	//相邻元素进行比较
	//每一次遍历范围: 0 -- 未排序数据的最后一个位置
	int end = n;
	while (end > 1)
	{
		//flag: 标记一轮冒泡排序中是否发生了交换操作
		int flag = 0;
		//一轮冒泡排序
		for (int i = 1; i < end; ++i)
		{
			if (arr[i - 1] < arr[i])
			{
				//大的向后移动
				Swap(arr, i - 1, i);
				flag = 1;
			}
		}
		//如果没有发生交换, 说明剩余元素全部有序
		if (!flag)
			break;
		--end;
	}
}

//快速排序性能的优化
//获取基准值: 三数取中法: 起始位置, 中间位置, 结束位置
int getMid(int* arr, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (arr[begin] > arr[end])
	{
		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])
			return end;
		else
			return begin;
	}
	else
	{
		if (arr[mid] < arr[end])
			return mid;
		else if (arr[begin] < arr[end])
			return end;
		else
			return begin;
	}
}
//返回划分之后,基准值所在的位置
int partion(int* arr, int begin, int end)
{
	//获取基准值的位置
	int mid = getMid(arr, begin, end);
	//把基准值放到起始位置
	Swap(arr, begin, mid);
	//选择基准值
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		//从后向前先找小于基准值的位置
		while (begin < end && arr[end] >= key)
			--end;
		//从前向后找大于基准值的位置
		while (begin < end && arr[begin] <= key)
			++begin;
		//交换
		Swap(arr, begin, end);
	}
	//交换基准值与相遇位置的数据
	Swap(arr, start, begin);
	return begin;
}

//快速排序
void quickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div: 第一次划分之后基准值的位置
	int div = partion(arr, begin, end);
	//左右两部分进行快速排序
	//[begin, div - 1]
	//[div + 1, end]
	partion(arr, begin, div - 1);
	partion(arr, div + 1, end);
}

//相邻子序列合并: begin	  end	end + 1   end2
// begin    mid    end2
//合并的过程
void merge(int* arr, int begin, int mid, int end, int* tmp)
{
	//递增
	//子区间: [begin, mid]  [mid, end]
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	//辅助空间的起始位置
	int idx = begin;
	//合并有序序列
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
			tmp[idx++] = arr[begin1++];
		else
			tmp[idx++] = arr[begin2++];
	}
	//判断是否有未合并的元素
	if (begin1 <= end1)
		memcpy(tmp + idx, arr + begin1, sizeof(int) * (end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int) * (end2 - begin2 + 1));
	//将合并后的序列拷贝到原始数组的对应区间
	memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

//归并排序
void mergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	//首先合并子序列
	mergeSort(arr, begin, mid, tmp);
	mergeSort(arr, mid + 1, end, tmp);
	//合并两个有序序列
	merge(arr, begin, mid, end, tmp);
}

//申请辅助空间
void _mergrSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	mergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}

//计数排序
void countSort(int* arr, int n)
{
	//找到最大值和最小值
	int max, min;
	min = max = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	//计算范围
	int range = max - min + 1;
	//创建一个计数数组, 初始化为0
	int* countArr = (int*)calloc(range, sizeof(int));
	//计数
	for (int i = 0; i < n; ++i)
	{
		countArr[arr[i] - min]++;
	}
	//遍历计数数组
	int idx = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr--)
		{
			arr[idx++] = i + min;
		}
	}
}

void printArr(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}

void test()
{
	int arr[] = { 9,5,2,7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	insertSort(arr, n);
	printArr(arr, n);
}

int main()
{
	test();
	return 0;
}
