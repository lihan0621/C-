#include <stdio.h>

//��������
void insertSort(int* arr, int n)
{
	//�����һ����������
	//δ���������[1, n)
	for (int i = 1; i < n; ++i)
	{
		//���������ݵ����һ��λ����ǰ����
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] >= data)
		{
			//�����������ƶ�
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = data;
	}
}

//ϣ������
void shellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//���һ������, ���������1, ��֤�������ݶ���ͬһ��
		//һ��ϣ������
		for (int i = gap; i < n; ++i)
		{
			//ͬһ������, ���һ���������ݵ�λ��
			int end = gap - 1;
			//�����������
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

//ѡ������
void selectSort(int* arr, int n)
{
	//��δ���������������ֵ��ŵ�δ�������ʼλ��
	//δ���������: [start, end]
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		//�ҵ���Сֵ��λ��
		int minidx = start;
		int i;
		for (i = start + 1; i <= end; ++i)
		{
			if (arr[i] < arr[minidx])
				minidx = i;
		}
		//����Сֵ�ŵ��ʼ��λ��
		Swap(arr, start, minidx);
		//ʣ���δ����Ŀռ�[start + 1, end]
		++start;
	}
}

void selectSort2(int* arr, int n)
{
	int start = 0;
	int end = n - 1;
	//ÿ�δ�δ����������ҵ�һ����Сֵ��һ�����ֵ
	//��Сֵ����ͷ��, ���ֵ����β��
	//�����Ĵ�������һ��
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
		//��Сֵ����ͷ��
		Swap(arr, start, minidx);
		//�ж����ֵ��λ���Ƿ�����ʼλ��
		if (maxidx == start)
			maxidx = minidx;
		//���ֵ����β��
	
		Swap(arr, end, maxidx);
		++start;
		--end;
	}
}

//ð������
void bubbleSort(int* arr, int n)
{
	//����Ԫ�ؽ��бȽ�
	//ÿһ�α�����Χ: 0 -- δ�������ݵ����һ��λ��
	int end = n;
	while (end > 1)
	{
		//flag: ���һ��ð���������Ƿ����˽�������
		int flag = 0;
		//һ��ð������
		for (int i = 1; i < end; ++i)
		{
			if (arr[i - 1] < arr[i])
			{
				//�������ƶ�
				Swap(arr, i - 1, i);
				flag = 1;
			}
		}
		//���û�з�������, ˵��ʣ��Ԫ��ȫ������
		if (!flag)
			break;
		--end;
	}
}

//�����������ܵ��Ż�
//��ȡ��׼ֵ: ����ȡ�з�: ��ʼλ��, �м�λ��, ����λ��
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
//���ػ���֮��,��׼ֵ���ڵ�λ��
int partion(int* arr, int begin, int end)
{
	//��ȡ��׼ֵ��λ��
	int mid = getMid(arr, begin, end);
	//�ѻ�׼ֵ�ŵ���ʼλ��
	Swap(arr, begin, mid);
	//ѡ���׼ֵ
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		//�Ӻ���ǰ����С�ڻ�׼ֵ��λ��
		while (begin < end && arr[end] >= key)
			--end;
		//��ǰ����Ҵ��ڻ�׼ֵ��λ��
		while (begin < end && arr[begin] <= key)
			++begin;
		//����
		Swap(arr, begin, end);
	}
	//������׼ֵ������λ�õ�����
	Swap(arr, start, begin);
	return begin;
}

//��������
void quickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div: ��һ�λ���֮���׼ֵ��λ��
	int div = partion(arr, begin, end);
	//���������ֽ��п�������
	//[begin, div - 1]
	//[div + 1, end]
	partion(arr, begin, div - 1);
	partion(arr, div + 1, end);
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
