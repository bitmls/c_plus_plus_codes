#include <iostream>
using namespace std;

class Person
{
public:
	void ShowAge()
	{
		cout << m_age << endl;
	}
	static void ShowId()
	{
		cout << m_id << endl;
	}
	
	int m_age;
	static int m_id;
};

void test()
{
	Person p1;  // �ն��󴴽�Ҳ����1�ֽڵĿռ�
	cout << sizeof(p1) << endl;//��ë
	//�ú�ѧ��ɢ��ѧ����ë���ζ�������
}

//int main()
//{
//	test();
//	return 0;
//}