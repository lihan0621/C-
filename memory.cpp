#include <iostream>
#include <assert.h>
using namespace std;

class String
{
public:
	String(const char* str = "")
		:m_data(nullptr)
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	~String()
	{
		delete[] m_data;
		m_data = nullptr;
	}
private:
	String(const String& s);
	String& operator=(const String& s);
private:
	char* m_data;
};

void main()
{
	String s1 = "abc";
	//String s2 = s1;
	String s3;
	//s3 = s1;
}

/*
class String
{
public:
	String(const char* str = "")
		:m_data(nullptr)
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String& s)
	{
		m_data = new char[strlen(s.m_data) + 1];
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			delete[] m_data;
			m_data = new char[strlen(s.m_data) + 1];
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String()
	{
		delete[] m_data;
		m_data = nullptr;
	}
private:
	char* m_data;
};

void main()
{
	String s1 = "abc";
	String s2 = s1;
	String s3;
	s3 = s2;
}

/*
class String
{
public:
	String(const char* str = "")
		:m_data(nullptr)
	{
		m_data = (char*)malloc(strlen(str) + 1);
		assert(m_data != NULL);
		strcpy(m_data, str);
	}
	String(const String& s)
	{
		m_data = (char*)malloc(strlen(s.m_data) + 1);
		assert(m_data != NULL);
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			free(m_data);
			m_data = (char*)malloc(strlen(s.m_data) + 1);
			assert(m_data != NULL);
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String()
	{
		free(m_data);
		m_data = nullptr;
	}
private:
	char* m_data;
};

void main()
{
	String s1 = "abc";
	String s2 = s1;
	String s3;
	s3 = s2;
}

/*
class Test
{
public:
	Test()
	{
		cout << "Create Test Object." << endl;
		m_data = 0;
	}
	~Test()
	{
		cout << "Free Test Object." << endl;
	}
public:
	void InitTest(int data = 0)
	{
		cout << "Init Test." << endl;
		m_data = data;
	}
	void DestroyTest()
	{
		cout << "Destroy Test." << endl;
	}
private:
	int m_data;
};

void main()
{
	Test* pt = new Test[10];
	delete[] pt;
}

/*
void main()
{
	Test* pt = new Test;  //1.申请空间 2.调动构造函数
	delete pt;            //1.摧毁对象 2.释放空间
}

/*
int main()
{
	Test* pt = (Test*)malloc(sizeof(Test));
	if (pt == NULL)
		return 0;
	pt->InitTest(1);

	pt->DestroyTest();
	free(pt);

	system("pause");
	return 0;
}

/*
int main()
{
	int* p1 = (int*)malloc(sizeof(int) * 10);
	if (p1 == NULL)
		return 0;

	int* p2 = new int[10]{ 1,2,3,4,5,6,7,8,9,10 };  //C++11

	free(p1);
	delete[] p2;

	system("pause");
	return 0;
}


/*
int main()
{
	//int* p1 = (int*)malloc(sizeof(int));
	int* p1 = (int*)calloc(1, sizeof(int));
	if (p1 == NULL)
		return 0;
	*p1 = 10;
	free(p1);

	int* p2 = new int(100);//new 初始化

	delete p2;

	system("pause");
	return 0;
}
/*
int main()
{
	int* p1 = (int*)malloc(sizeof(int) * 10);
	if (p1 == NULL)
		return 0;

	int* p2 = new int[10];

	free(p1);
	delete[] p2;

	system("pause");
	return 0;
}

int main()
{
	int* p1 = (int*)malloc(sizeof(int));
	if (p1 == NULL)
		return 0;
	int* p2 = new int;
	free(p1);
	delete p2;
	system("pause");
	return 0;
}

int main()
{
	int* ptr = (int*)malloc(sizeof(int) * 10);
	if (ptr == NULL)
		return 0;
	//calloc;
	//realloc;

	free(ptr); 
	system("pause");
	return 0;
}
*/