#include<stdio.h>
#include<stdlib.h>
//int countBit(int num)
//{
//	//依次取1,10，100...这些数字和num进行按位与
//	//取1运算时，相当于把num的最后一位取出来了
//	//取10运算时，相当于把num的倒数第二位取出来了
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (num & (1 << i))
//		{
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int num = 0;
//	scanf_s(" %d", &num);
//	int ret = countBit(num);
//	printf(" %d \n", ret);
//	system("pause");
//	return 0;
//}
﻿int    main()

{

	string a = "hello world";

	string b = a;

	if (a.c_str() == b.c_str())

	{

		cout << "true" << endl;

	}

	else cout << "false" << endl;

	string c = b;

	c = "";

	if (a.c_str() == b.c_str())

	{

		cout << "true" << endl;

	}

	else cout << "false" << endl;

	a = "";

	if (a.c_str() == b.c_str())

	{

		cout << "true" << endl;

	}

	else cout << "false" << endl;
	system("pause");
	return 0;

}