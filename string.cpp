//��ǳ����



//#include<iostream>
//#include<string>
//using namespace std;
////�ִ�д��
//class String
//{
//public:
//	String(const char* str = "")
//		:_data(new char[strlen(str) + 1])
//	{
//		strcpy(_data, str);
//	}
//	//�������죺�ִ�д��--->���ÿ������߼�
//	//�������캯���ڴ����ֲ�����ʱ�����пռ�����+���ݿ���
//	//ͨ��������Ա��ִ�У����մﵽ���������Ŀ��
//	String(const String& str)
//		:_data(nullptr)
//	{
//		String tmp(str._data);
//		swap(_data, tmp._data);
//	}
//	//��ֵ��������ִ�д��-->���ÿ���
//	//��������������ɣ����пռ�����+���ݿ���
//	//�����ֲ����������������ɵ�ǰ����ԭ����Դ���ͷ�
//	String& operator=(String str)
//	{
//		swap(_data, str._data);
//		return *this; 
//	}
//	~String()
//	{
//		if (_data)
//		{
//			delete[]_data;
//			_data = nullptr;
//		}
//	}
//private:
//	char* _data;
//};
//��ͳд��
//class String
//{
//public:
//	/*String()
//		:_data(new char[1] )
//	{
//		_data[0] = '\0'; 
//	}*/
//	String(const char* str = "")
//		:_data(new char[strlen(str) + 1])
//	{
//		strcpy(_data, str);
//	}
//	////ǳ����
//	//String(const String& str)
//	//	:_data(str._data)
//	//{}
//	//���
//	String(const String& str)
//		:_data(new char[strlen(str._data) + 1])
//	{
//		strcpy(_data, strcat._data);
//	}
//	String& operator=(const String& str)
//	{
//		if (this != &str)
//		{
//			delete[] _data;
//			_data = new char[strlen(str._data) + 1];
//			strcpy(_data, str._data);
//		}
//		return *this;
//	}
//	const char* c_str()const
//	{
//		return _data;
//	}
//	~String()
//	{
//		if (_data)
//		{
//			delete[]_data;
//			_data = nullptr;
//		}
//	}
//
//private:
//	char* _data;
//};
//void test()
//{
//	String str;
//	cout << str.c_str() << endl;
//	String str2;
//	cout << str2.c_str() << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}