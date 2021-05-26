#include<iostream>
#include<string>
using namespace std;
int GetRoot(int num)
{
    int sum = 0;
    while (num) {
        sum += num % 10;
        num = num / 10;
        if (num == 0 && sum / 10 != 0) {
            num = sum;
            sum = 0;
        }
    }
    return sum;
}
int main()
{
    string str;
    while (cin >> str) {
        int num = 0;
        for (int i = 0; i < str.size(); ++i) {
            num += str[i] - '0';
        }
        int ret = GetRoot(num);
        cout << ret << endl;
    }
    return 0;
}