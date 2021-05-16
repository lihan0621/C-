#include<iostream>
#include<string>
using namespace std;
string FindMax(const string& line)
{
	if (line.find("joker JOKER") != string::npos) {
		return "joker JOKER";
	}
	//分开两手牌
	int dash = line.find('-');
	string car1 = line.substr(0, dash);
	string car2 = line.substr(dash + 1);
	//获取两手牌的张数
	int car1_cnt = count(car1.begin(), car1.end(), ' ') + 1;
	int car2_cnt = count(car2.begin(), car2.end(), ' ') + 1;
	//获取两手牌的各自第一张牌
	string car1_first = car1.substr(0, car1.find(' '));
	string car2_first = car2.substr(0, car2.find(' '));
	if (car1_cnt == car2_cnt) {//两手牌的类型相同
		string str = "345678910JQKA2jokerJOKER";
		if (str.find(car1_first) > str.find(car2_first))
			return car1;
		return car2;
	}
	if (car1_cnt == 4)//说明是炸弹
		return car1;
	if (car2_cnt == 4)
		return car2;
	return "ERROR";
}
int main()
{
	string line, res;
	getline(cin, line);
	res = FindMax(line);
	cout << res << endl;
	return 0;
}