#include<iostream>
using namespace std;
class Date
{
public:
	Date(int y = 1, int m = 1, int d = 1)
	{
		//�ж������Ƿ���Ч
		if (y <= 0 || m <= 0 || m > 12 || d <= 0 || d > getDay(y, m))
		{
			_y = 1;
			_m = 1;
			_d = 1;
			cout << "������Ч,Ĭ��Ϊ1-1-1" << endl;
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
		//����Ƕ���,��Ϊ����,�޸�����
		if ((m == 2) && ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0)))
		{
			day += 1;
			return day;
		}
	}
	//��������
	//Date + int    int a,int b,a += b;
	//������� += �Ҳ����� :������������ݷ����仯,����ֵ:���֮���ֵ
	Date& operator+=(int day)
	{
		//�ж������Ƿ�Ϊ��
		if (day<0)
		{
			return *this -= -day;
		}
		//�������
		_d += day;
		//�ж������Ƿ����
		while (_d > getDay(_y, _m))
		{
			//��ȥ���µ�����
			_d -= getDay(_y, _m);
			//�·ݽ�λ
			++_m;
			//�ж��·��Ƿ����
			if (_m == 13)
			{
				//��ݽ�λ
				++_y;
				_m = 1;
			}
		}
		//�������֮��Ľ��
		return *this;
	}
	//�������֮��Ľ��
	//Date + int
	Date operator+(int day)
	{
		Date copy(*this);
		//Data copy = *this
		copy += day;
		return copy;
	}
	//ǰ��++
	//++Date
	Date& operator++()
	{
		return *this += 1;
	}
	//����++
	//Date++
	//int����������:ֻ��Ϊ�˺�ǰ��++��������,�����ڲ������õ�
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
			//����һ�µ������ز�
			--_m;
			//�ж��·��Ƿ����(����)
			if (_m == 0)
			{
				//��Ҫ�˻���һ���12�·�
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
	//�������:Date - Data
	int operator-(const Date& d)
	{
		//����Ƚ�С�����ھ������ٴε��Լ�������Ժͽϴ��������
		//�Լӵ�������������������������
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
