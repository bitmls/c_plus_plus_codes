//#include <iostream>
//using namespace std;
//
//class Father
//{
//public:
//	int m_a;
//protected:
//	int m_b;
//private:
//	int m_c;
//};
//
//// �����̳�
//class Son1 :public Father
//{
//public:
//	void func()
//	{
//		m_a = 10;  // ����Ĺ���Ȩ�޳�Ա����������Ȼ�ǹ���Ȩ��
//		m_b = 10;  // ����ı���Ȩ�޳�Ա����������Ȼ�Ǳ���Ȩ��
//		//m_c = 10;  // �����˽��Ȩ�޳�Ա���޷�������̳�
//	}
//};
//
//// �����̳�
//class Son2 :protected Father
//{
//	void func()
//	{
//		m_a = 20;
//		m_b = 20;
//		//m_c = 20;
//	}
//};
//
//// ˽�м̳�
//class Son3 :private Father
//{
//	void func()
//	{
//		m_a = 30;
//		m_b = 30;
//		//m_c = 30;
//	}
//};
//
//void test1()
//{
//	Son1 s1;
//	s1.m_a;
//	//s1.m_b;  // ����Ȩ�����ڿ��Է��ʣ�������ʲ���
//}
//
//void test2()
//{
//	Son2 s2;
//	//s2.m_a;  // �����̳к󣬹���Ȩ�ޱ�Ϊ����Ȩ��
//}
//
//void test3()
//{
//
//}
//
//int main()
//{
//	test1();
//	return 0;
//}