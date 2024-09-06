#include <iostream>
using namespace std;

class Person
{
public:
	Person(int age, int height)
	{
		m_Age = age;
		m_Height = new int(height);
		cout << "���캯���Ĳ�������" << endl;
	}
	Person(const Person& p)
	{
		m_Age = p.m_Age;
		//m_Height = p.m_Height;  //������Ĭ��ʵ�־������д���
		//�������
		m_Height = new int(*p.m_Height);

		cout << "���캯���Ŀ�������" << endl;
	}
	~Person()
	{
		//�������룬�����������������ͷŲ���
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "���������ĵ���" << endl;
	}

	int m_Age;
	int* m_Height;
};

void test01()
{
	Person p1(19, 178);

	cout << p1.m_Age << endl;
	cout << *p1.m_Height << endl;

	Person p2(p1);

	cout << p2.m_Age << endl;
	cout << *p2.m_Height << endl;
}

int main()
{
	test01();

	return 0;
}