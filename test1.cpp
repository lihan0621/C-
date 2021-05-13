#include<iostream>
using namespace std;
//判断闰年
bool isLeap(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
//根据年和月获取相应月份对应的天数
int getDaysByYM(int year, int month)
{
	int days[13] = { 29,31,28, 31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && isLeap(year)) {
		month = 0;
	}
	return days[month];
}
//根据年月日获取相应的这一年的第几天
int getDaysByYMD(int year, int month, int day)
{
	int days = 0;
	for (int i = 1; i < month; ++i) {
		days += getDaysByYM(year, i);
	}
	days += day;
	return days;
}
int main()
{
	int year, month, day;
	int days = 0;
	cin >> year >> month >> day;
	days = getDaysByYMD(year, month, day);
	cout << days << endl;
	return 0;
}