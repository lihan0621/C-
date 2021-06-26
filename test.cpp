#include<iostream>
using namespace std;
class Date
{
public:
	Date(int y = 1, int m = 1, int d = 1)
	{
		//判断日期是否有效
		if (y <= 0 || m <= 0 || m > 12 || d <= 0 || d > getDay(y, m))
		{
			_y = 1;
			_m = 1;
			_d = 1;
			cout << "日期无效,默认为1-1-1" << endl;
		}
		else
		{		
			_y = m;
			_m = m;
			_d = d;
		}

	}
	int getDay(int y, int m)
	{
		static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[m];
		//如果是二月,且为闰年,修改天数
		if ((m == 2) && ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0)))
		{
			day += 1;
			return day;
		}
	}
	//日期运算
	//Date + int    int a,int b,a += b;
	//左操作数 += 右操作数 :左操作数的内容发生变化,返回值:相加之后的值
	Date& operator+=(int day)
	{
		//判断日期是否为负
		if (day<0)
		{
			return *this -= -day;
		}
		//相加天数
		_d += day;
		//判断天数是否溢出
		while (_d > getDay(_y, _m))
		{
			//减去当月的天数
			_d -= getDay(_y, _m);
			//月份进位
			++_m;
			//判断月份是否溢出
			if (_m == 13)
			{
				//年份进位
				++_y;
				_m = 1;
			}
		}
		//返回相加之后的结果
		return *this;
	}
	//返回相加之后的结果
	//Date + int
	Date operator+(int day)
	{
		Date copy(*this);
		//Data copy = *this
		copy += day;
		return copy;
	}
	//前置++
	//++Date
	Date& operator++()
	{
		return *this += 1;
	}
	//后置++
	//Date++
	//int参数的作用:只是为了和前置++构成重载,函数内部不会用到
	Date operator++(int)
	{
		Date copy(*this);
		*this += 1;
		return copy;
	}
	Date& operator-=(int day)
	{
		_d -= day;
		while (_d <= 0)
		{
			//用上一月的天数回补
			--_m;
			//判断月份是否溢出(向下)
			if (_m == 0)
			{
				//需要退回上一年的12月份
				--_y;
				_m = 12;
			}
			_d += getDay(_y, _m);
		}
		return *this;
	}
	//Date - int
	Date operator-(int day)
	{
		Data copy(*this);
		copy -= day;
		return copy;
	}
	//--Date
	Data operator--()
	{
		return *this -= 1;
	}
	//Date--
	Date& operator--(int)
	{
		Date copy(*this);
		*this -= 1;
		return copy;
	}
	//==
	bool operator==(const Date& d)
	{
		return _y == d._y
			&& _m == d._m
			&& _d == d._d;
	}
	//!=
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	//>
	bool operator>(const Date& d)
	{
		if (_y > d._y)
		{
			return true;
		}
		else if (_y == d.y)
		{
			if (_m > d._m)
			{
				return true;
			}
			else if (_m == d._m)
			{
				if (_d > d._d)
				{
					return true;
				}
			}
		}
		return false;
	}
	//<
	bool operator>(const Date& d)
	{
		return !(*this >= d);
	}
	//>=
	bool operator>=(const Date& d)
	{
		return *this > d || *this == d;
	}
	//<=
	bool operator<=(const Date& d)
	{
		return !(*this > d);
	}
	//日期相减:Date - Data
	int operator-(const Date& d)
	{
		//计算比较小的日期经过多少次的自加运算可以和较大日期相等
		//自加的天数就是两个日期相差的天数
		Date max = *this;
		Date min = d;
		int flag = 1;
		if (d > *this)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min < max)
		{
			++min;
			++day;
		}
		return flag * day;
	}
private:
	int _y;
	int _m;
	int _d;
};
