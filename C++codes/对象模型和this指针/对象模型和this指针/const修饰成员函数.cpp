#include <iostream>
using namespace std;

class Person
{
public:
	void person_test() const
	{
		//m_age = 100;  // const���ں����Ҳ��ʾ�����ڵĲ������ɸı�
		// const����thisָ���ڵı��������޸�
		m_id = 100;
		cout << "m_id = " << m_id << endl;
	}

	int m_age;
	mutable int m_id;
};

int main()
{
	Person p1;
	p1.person_test();
	const Person p2;
	/p2.m_age = 10;  // ������ֻ�ܵ��ó�����

	return 0;
}
