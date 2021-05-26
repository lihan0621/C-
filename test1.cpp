#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> f_arr = { 0, 1, 2 };
    for (int i = 3; i < 10001; ++i) {
        f_arr.push_back((f_arr[i - 1] + f_arr[i - 2]) % 10000);
    }
    int n = 0;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            printf("%04d", f_arr[t]);
        }
        printf("\n");
    }
    return 0;
}