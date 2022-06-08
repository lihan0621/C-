#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <assert.h>
#include <unordered_map>
using namespace std;


int BinaryFindValue(const int* ar, int n, int val)
{
	assert(ar != nullptr);
	int pos = -1;
	int left = 0, right = n - 1;
	while (left <= right)
	{
		//int mid = (left + right) / 2;
		int mid = (right - left) / 2 + left;//Ïà¶ÔÎ»ÖÃ
		if (val < ar[mid])
		{
			right = mid - 1;
		}
		else if (val > ar[mid])
		{
			left = mid + 1;
		}
		else
		{
			/*
			while (mid > left && ar[mid - 1] == val)
			{
				mid = mid - 1;
			}
			pos = mid;
			break;
			*/
			if (ar[mid - 1] != val)
			{
				pos = mid;
				break;
			}
			right = mid - 1;
		}
	}
	return pos;
}


int FindValue(const int* ar, int left, int right, int val)
{
	assert(ar != nullptr);
	int pos = -1;
	if (left <= right)
	{
		int mid = (right - left) / 2 + left;
		if (val < ar[mid])
		{
			pos = FindValue(ar, left, mid - 1, val);
		}
		else if (val > ar[mid])
		{
			pos = FindValue(ar, mid + 1, right, val);
		}
		else
			pos = mid;
	}
	return pos;
}

int BinFindValue(const int* ar, int n, int val)
{
	assert(ar != nullptr);
	return FindValue(ar, 0, n - 1, val);
}

int main()
{
	int ar[] = { 12,23,34,34,34,34,34,45,56,67,78,89,90,100 };
	int n = sizeof(ar) / sizeof(ar[0]);
	int val;
	cin >> val;
	int pos = BinaryFindValue(ar, n, val);
	//int pos = BinFindValue(ar, n, val);
	cout << pos << endl;
	system("pause");
	return 0;
}