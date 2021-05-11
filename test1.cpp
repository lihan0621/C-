#include<iostream>
using namespace std;
class BinInsert
{
public:
	int bininsert(int n, int m, int j, int i)
	{
		//方法一 :
		//for (int k = 0; k <= i - j; k++) {
		//	n |= ((m >> k) & 1) << (j + k);
		//}
		//cout << n << endl;
		//return n;
		//方法二 :
		return n | (m << j);
	}
};
int main()
{
	BinInsert a;
	int ret = a.bininsert(1024, 19, 2, 6);
	cout << ret << endl;
	return 0;
}