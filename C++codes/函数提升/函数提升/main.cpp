#include <iostream>
using namespace std;

////����������Ĭ��ֵ
//int test1(int a, int b = 10, int c = 10)
//{
//	return a + b + c;
//}
//
////�����Ķ���������ֻ������һ��дĬ��ֵ
//int test2(int a, int b, int c);
//
//int test2(int a = 10, int b = 10, int c = 10)
//{
//	return a + b + c;
//}
//
//int main()
//{
//	//cout << test1(10) << endl;
//	cout << test2() << endl;
//
//	return 0;
//}


//void func()
//{
//	cout << "����func����" << endl;
//}
//
//void func(int a = 10)
//{
//	cout << "����func(int a)����" << endl;
//}
//
//int main()
//{
//	int a = 1;
//	func(a);
//
//	return 0;
//}

//void test(int a = 10) {
//	cout << a << endl;
//}
//
//int main() {
//	test(20);
//	test();
//	return 0;
//}


// ��������

void func(int a = 10) {
	cout << a << endl;
}

void func(double a) {
	cout << "func����" << endl;
}

void func(const int a) {
	cout << "const����" << endl;
}

int main() {
	func(10);
	return 0;
}