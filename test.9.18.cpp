#include <iostream>
using namespace std;

class HeapObj
{
public:
	//���ù��캯����������
	static HeapObj* getObj()
	{
		//HeapObj* p = new HeapObj();
		//return *p;
		return new HeapObj;
	}
	//��ֹ���캯���ĵ��ã� ˽��
private:
	HeapObj()
	{}

	//������
	//ֻ��������ʵ��
	//HeapObj(const HeapObj&);

	//��������Ϊdelete����
	HeapObj(const HeapObj&) = delete;

};

void test()
{
	//HeapObj h;
	HeapObj* ptr = HeapObj::getObj();
	//HeapObj copy(*ptr);
}

int main()
{
	test();
	system("pause");
	return 0;
}