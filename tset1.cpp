//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	int count = 0;
//	cin >> n;
//	while (n > 1) {
//		count++;
//		n = n / 3 + (n % 3 == 0);
//	}
//	cout << count << endl;
//	return 0;
//}
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int getFirstUnFormedNum(std::vector<int>& arr, int length) {
		int sum = 0, min = arr[0];
		int i, j;
		for (int i = 0; i < length; i++)
		{
			sum += arr[i];
			min = arr[i] < min ? arr[i] : min;
		} 
		std::vector<int> dp(sum + 1, 0);
		for (i = 0; i < length; i++) {//有length个数据--有length个阶段
		//{2， 3， 5}
		//i=0--d[10]=2 d[9]=2 d[8]=2 d[7]=2...d[2]=2
		//i=1--d[10]=5 d[9]=5...d[5]=5 d[4]=3 d[3]=3
		//i=2--d[10]=10 d[9]=8 d[8]=8 d[7]=7 d[6]=5 d[5]=5
			for (j = sum; j >= arr[i]; j--) {
				//逆序判断背包承重中能够放入的数据
				//当数组中只有2的时候，背包承重从2-10都可以放入2的数值
				//当数组中放入2和3的时候，背包承重从5-10可以放入5，3-4放入3，2只能放入2
				//当数组中放入2，3，5时，背包承重10放入10，8-9放入8，7放入7，5-6放入5...
				//dp[j-arr[i]]意思是背包承重为j时，如果已经放置了arr[i]的重量后还能放置的最大重量
					if (dp[j] < dp[j - arr[i]] + arr[i])//对每个承重计算当前最大能放置重量
						dp[j] = dp[j - arr[i]] + arr[i];//更新背包中能够放入的最大值
					else
						dp[j] = dp[j];
			}
		} //最后当承重为n时，放入的重量不为n则认为是最大不可求和
			for (i = min; i <= sum; i++)
			{
				if (i != dp[i])
					return i;
			} 
			return sum + 1;
	}
};
int main()
{
	return 0;
}