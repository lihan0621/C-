#include <iostream>
using namespace std;

void Sort(int arr[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=1; j<n-i; j++)
		{
			if(arr[j]<arr[j-1])
			{
				int tmp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=tmp;
			}
		}
	}
}

int main()
{
	int arr[]={ 9,5,2,7 };
	int n=sizeof(arr)/sizeof(arr[0]);
	Sort(arr, n);
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}