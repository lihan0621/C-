//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//int FindsubString(char* pch)
//{
//	int count = 0;
//	char* p1 = pch;
//	while (*p1 != '\0') {
//		if (*p1 == p1[1] - 1) {
//			p1++;
//			count++;
//		}
//		else {
//			break;
//		}
//	}
//	int count2 = count;
//	while (*p1 != '\0') {
//		if (*p1 == p1[1] + 1) {
//			p1++;
//			count2--;
//		}
//		else {
//			break;
//		}
//	}
//	if (count2 == 0)
//		return count;
//	return 0;
//}
//void ModifyString(char* ptext)
//{
//	char* p1 = ptext;
//	char* p2 = p1;
//	while (*p1 != '\0') {
//		int count = FindsubString(p1);
//		if (count > 0) {
//			*p2++ = *p1;
//			sprintf(p2, "%i", count);
//			while (*p2 != '\0') {
//				p2++;
//			}
//			p1 += count + count + 1;
//		}
//		else {
//			*p2++ = *p1++;
//		}
//	}
//}
//int main()
//{
//	char text[32] = "XYBCDCBABABA";
//	ModifyString(text);
//	printf(text);
//	return 0;
//}
