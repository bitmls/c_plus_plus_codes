//#include <iostream>
//using namespace std;
//
//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);
//public:
//	Person(int a, int b)
//	{
//		m_A = a;
//		m_B = b;
//	}
//private:
//	int m_A;
//	int m_B;
//};
////
////��ëѧ32,ѧ���ˣ��Ȼ����е�Ƭ����ѧ����ë��ѧ��׼�⣬ѧhal�⣬ѧ�Ĵ�����ѧ����һ�㣬hal��ѧ�ÿ�
//// ѧc++
//// ���������Ҫ��ʵ��cout�����ֻ����ȫ��ʵ�֣�����������ʵ��
//ostream& operator<<(ostream& cout, Person& p)
//{
//	cout << "p.m_A = " << p.m_A << " p.m_B = " << p.m_B;
//	return cout;
//}
//
//void test()
//{
//	Person p(10, 20);
//	cout << p << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}