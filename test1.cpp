//#include <iostream>
//using namespace std;
//int main()
//{
//	int num = 0;
//	cin >> num;
//	int count = 0, max_count = 0;
//	for (int i = 0; i < 32; i++) {
//		if (num & (1 << i)) {
//			count++;
//			max_count = max(count, max_count);
//		}
//		else {
//			count = 0;
//		}
//	}
//	//�����-1, �������;
//	/*while (num) {
//		if (num & 1) {
//			count++;
//			max_count = max(count, max_count);
//		}
//		else {
//			count = 0;
//		}
//			num = num >> 1;
//	}*/
//	cout << count << endl;
//	return 0;
//}