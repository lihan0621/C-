#include <iostream>
#include <string>
#include <vector>
using namespace std;
void cmdLineParse(const string& str)
{
	string tmp = "";
	vector<string> svec;
	bool flag = false;//�ж��Ƿ����ַ���״̬
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '"') {//�ж��Ƿ����ַ�������ʼ���߽���
			flag = !flag;
		}
		else if (str[i] == ' ' && !flag) {//�жϲ����ķָ������Ƿ�Ϊ�ַ���������
			svec.push_back(tmp);
			tmp = "";
		}
		else {//�����Ĳ�������
			tmp += str[i];
		}
	}
	svec.push_back(tmp);//׷�����һ������
	cout << svec.size() << endl;
	for (int i = 0; i < svec.size(); ++i) {
		cout << svec[i] << endl;
	}
}
//int main()
//{
//	string str;
//	getline(cin, str);
//	cmdLineParse(str);
//	return 0;
//}