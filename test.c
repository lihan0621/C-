#include <stdio.h>

int main1()
{
	int i, j, k;
	int count=0;
	for(i=1; i<=9; i++) 
	{
		for(j=0; j<=9; j++) 
		{
			if(i==j) 
			{
				continue;
			}
			for(k=0; k<=9; k++) 
			{
				if(k!=i && k!=j) 
				{
					count++;
				}
			}
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}