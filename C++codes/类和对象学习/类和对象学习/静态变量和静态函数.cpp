#include <iostream>
using namespace std;

class Person
{
public:
	static void person_test()
	{
		m_age = 100;  // ��̬��Ա�������Է��ʾ�̬����
		//m_id = 100;  // ��̬��Ա�������ܷ��ʷǾ�̬����
		cout << "��̬��Ա�����ĵ���" << endl;
	}

	static int m_age;
	int m_id;
};

int Person::m_age = 20;

void test0()
{
	Person p1;
	cout << p1.m_age << endl;
	Person p2;
	cout << p2.m_age << endl;
	
	p1.person_test();
	p2.person_test();
	Person::person_test();//��ëл��������ë�����Ҷ�
}

void test1()
{
	cout << Person::m_age << endl;
}

int main()
{
	test0();
	test1();
	return 0;
}