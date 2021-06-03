#include<iostream>
using namespace std;

bool IsLeepYear(int y) {
	return (y % 400 == 0 || y % 100 != 0 && y % 4 == 0);
}
int Days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//求解y,m,d这一年过了多少天了
int nDays(int y, int m, int d) {
	int n = d;
	for (int i = 0; i < m - 1; ++i) {
		n += Days[i];
	}
	if (m > 2 && IsLeepYear(y)) {
		n++;
	}
	return n;
}
//传入y,m,d计算从基准日期,到待计算日期过了多少天
//算出这个天数的 MOD 7 的同余数
int diff(int y, int m, int d) {
	return (y - 1) + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400 + nDays(y, m, d);
}
//传入y,m,d计算周几
int week(int y, int m, int d) {
	int w = diff(y, m, d) % 7;
	if (w == 0)
		w = 7;
	return w;
}
//已知当月1日是星期w,计算第n个星期e是几号
int m1(int w, int n, int e) {
	return 1 + (n - 1) * 7 + (7 - w + e) % 7;
}
//已知6月1日是w,计算5月的最后一个星期一
int m2(int w) {
	int d = (w == 1 ? 7 : w - 1);
	return 32 - d;
}

int main() {
	int y;
	while (cin >> y) {
		/*
		链接：https://www.nowcoder.com/questionTerminal/d95d98a2f96e49078cd7df84ba0c9d79
		来源：牛客网

		* 1月1日：元旦
		* 1月的第三个星期一：马丁·路德·金纪念日2014-01-01
		* 2月的第三个星期一：总统节
		* 5月的最后一个星期一：阵亡将士纪念日
		* 7月4日：美国国庆
		* 9月的第一个星期一：劳动节
		* 11月的第四个星期四：感恩节
		* 12月25日：圣诞节
		2014-01-01
		2014-01-20
		2014-02-17
		2014-05-26
		2014-07-04
		2014-09-01
		2014-11-27
		2014-12-25
		*/
		printf("%d-01-01\n", y);
		int w;
		w = week(y, 1, 1);
		printf("%d-01-%02d\n", y, m1(w, 3, 1));

		w = week(y, 2, 1);
		printf("%d-01-%02d\n", y, m1(w, 3, 1));

		w = week(y, 6, 1);
		printf("%d-05-%02d", y, m2(w));

		printf("%d-07-04\n", y);

		w = week(y, 9, 1);
		printf("%d-09-%02d\n", y, m1(w, 1, 1));

		w = week(y, 11, 1);
		printf("%d-11-%02d\n", y, m1(w, 4, 4));

		printf("%d-12-25\n", y);

	}
	return 0;
}