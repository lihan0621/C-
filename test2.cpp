#include<iostream>
using namespace std;

bool IsLeepYear(int y) {
	return (y % 400 == 0 || y % 100 != 0 && y % 4 == 0);
}
int Days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//���y,m,d��һ����˶�������
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
//����y,m,d����ӻ�׼����,�����������ڹ��˶�����
//������������ MOD 7 ��ͬ����
int diff(int y, int m, int d) {
	return (y - 1) + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400 + nDays(y, m, d);
}
//����y,m,d�����ܼ�
int week(int y, int m, int d) {
	int w = diff(y, m, d) % 7;
	if (w == 0)
		w = 7;
	return w;
}
//��֪����1��������w,�����n������e�Ǽ���
int m1(int w, int n, int e) {
	return 1 + (n - 1) * 7 + (7 - w + e) % 7;
}
//��֪6��1����w,����5�µ����һ������һ
int m2(int w) {
	int d = (w == 1 ? 7 : w - 1);
	return 32 - d;
}

int main() {
	int y;
	while (cin >> y) {
		/*
		���ӣ�https://www.nowcoder.com/questionTerminal/d95d98a2f96e49078cd7df84ba0c9d79
		��Դ��ţ����

		* 1��1�գ�Ԫ��
		* 1�µĵ���������һ������·�¡��������2014-01-01
		* 2�µĵ���������һ����ͳ��
		* 5�µ����һ������һ��������ʿ������
		* 7��4�գ���������
		* 9�µĵ�һ������һ���Ͷ���
		* 11�µĵ��ĸ������ģ��ж���
		* 12��25�գ�ʥ����
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