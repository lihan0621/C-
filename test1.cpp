#include <iostream>
#include <string>
#include <vector>
using namespace std;
void cmdLineParse(const string& str)
{
	string tmp = "";
	vector<string> svec;
	bool flag = false;//判断是否处于字符串状态
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '"') {//判断是否是字符串的起始或者结束
			flag = !flag;
		}
		else if (str[i] == ' ' && !flag) {//判断参数的分隔或者是否为字符串的内容
			svec.push_back(tmp);
			tmp = "";
		}
		else {//正常的参数内容
			tmp += str[i];
		}
	}
	svec.push_back(tmp);//追加最后一个参数
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