//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person()
//	{
//		cout << "���캯����Ĭ�ϵ���" << endl;
//	}
//	Person(int a)
//	{
//		cout << "���캯���Ĳ�������" << endl;
//	}
//	Person(const Person& p)
//	{
//		m_Age = p.m_Age;
//		cout << "���캯���Ŀ�������" << endl;
//	}
//
//	~Person()
//	{
//		cout << "������������" << endl;
//	}
//
//	int m_Age;
//};
//
//int main()
//{
//	//Person p1;  //Ĭ��
//	//Person p2(10);  //�в�
//	//Person p3(p2);  //����
//
//	//��ʾ��
//	//Person p1;
//	//Person p2 = Person(10);  //<--��������
//	//Person p3 = Person(p2);
//
//	//��ʽת����
//	Person p1;
//	Person p2 = 10;
//	Person p3 = p2;
//
//	return 0;
//}