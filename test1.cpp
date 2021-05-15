#include<iostream>
using namespace std;
/*
int Count(size_t val)
{
	int count = 0;
	for (int i = 0; i < 32; i++) {
		if (val % 2 == 1) {
			count++;
		}
		val /= 2;
	}
	return count;
}
*/
/*
int Count(size_t val)
{
	int count = 0;
	while(val) {
		if (val &1==1) {
			count++;
		}
		val >>= 1;
	}
	return count;
}
*/
int Count(size_t val)
{
	int count = 0;
	while (val) {
		val = val & val - 1;
		count++;
	}
	return count;
}
int main()
{
	size_t val;
	cin >> val;
	int one_count = Count(val);
	cout << one_count << endl;
	return 0;
}