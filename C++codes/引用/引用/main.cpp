//#include <iostream>
//using namespace std;

//int main()
//{
//	//1.����ʱ�����ʼ��
//	//int& c;
//
//	//2.�����ڳ�ʼ�����ܸı�
//
//	int a = 10;
//	int& b = a;
//
//	cout << "a��ֵ��" << a << endl;
//	cout << "b��ֵ��" << b << endl;
//
//	b = 100;
//
//	cout << "a��ֵ��" << a << endl;
//	cout << "b��ֵ��" << b << endl;
//
//	system("pause");
//	return 0;
//}

//void intSwap1(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void intSwap2(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void intSwap3(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	//intSwap1(a, b);  //�����κδ���Ľ���
//	//intSwap2(&a, &b);  //ȡ��a��b�ĵ�ַ����ֵ
//	intSwap3(a, b);  //�β�ʹ�����õĽ���
//
//	cout << "a��ֵΪ" << a << endl;
//	cout << "b��ֵΪ" << b << endl;
//
//	return 0;
//}


//int& test(void)
//{
//	static int a = 10;
//	return a;
//}
//
//int main()
//{
//	int& ref = test();
//
//	cout << "a��ֵΪ" << ref << endl;
//	cout << "a��ֵΪ" << ref << endl;
//
//	//��������Ϊ��ֵ
//	test() = 1000;
//
//	cout << "a��ֵΪ" << ref << endl;
//
//	ref = 100;
//
//	cout << "a��ֵΪ" << ref << endl;
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main() {
//	int a = 10;
//	int& b = a;
//
//	cout << b << endl;
//
//	b = 20;
//
//	cout << a << endl;
//
//	return 0;
//}

#/*include <iostream>
using namespace std;

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 10;
	int b = 20;
	Swap(a, b);
	cout << a << "  " << b << endl;
	return 0;
}*/

//#include <iostream>
//using namespace std;

//int& test(void)
//{
//	static int a = 10;
//	return a;
//}
//
//int main()
//{
//	int& ref = test();
//
//	cout << "a��ֵΪ" << ref << endl;
//	cout << "a��ֵΪ" << ref << endl;
//
//	//��������Ϊ��ֵ
//	test() = 1000;
//
//	cout << "a��ֵΪ" << ref << endl;
//
//	ref = 100;
//
//	cout << "a��ֵΪ" << ref << endl;
//
//	return 0;
//}


#include <iostream>
using namespace std;

void test(int& num) {
	num = 1000;
}

int main() {
	int a = 100;
	cout << a << endl;
	test(a);
	cout << a << endl;

	return 0;
}