//#include <iostream>
//using namespace std;
//
//// ��ͨ�����뺯��ģ����ù���
//// 1.�����ͨ�������Ե��ã����ȵ�����ͨ����
//// 2.����ͨ����ģ������б� ǿ�Ƶ��� ����ģ��
//
//
//void my_print(int a)
//{
//	cout << "��ͨ��������\n" << endl;
//}
//
//template<typename T>
//void my_print(T a)
//{
//	cout << "����ģ�����\n" << endl;
//}
//
//template<typename T>
//void my_print(T a, T b)
//{
//	cout << "����ģ�����ص���\n" << endl;
//}
//
//void test()
//{
//	int a = 10;
//
//	//my_print(a);
//
//	// ͨ����ģ������б�ǿ�Ƶ��ú���ģ��
//	my_print<>(a);
//
//	my_print(a, 1);
//
//	char c = 'c';
//
//	my_print(c);
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}