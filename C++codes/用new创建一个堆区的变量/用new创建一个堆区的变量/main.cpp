#include <iostream>
using namespace std;

//int* func(void)
//{
//	//��new���ڶ�������һ��ռ�
//	int* pa = new int(10);
//	return pa;
//}
//
//int main()
//{
//	int* p = func();
//
//	cout << *p << endl;
//
//	return 0;
//}


int* func(void)
{
	int* p = new int(10);
	return p;
}

void test1(void)
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

	delete p;

	//cout << *p << endl;
}

void test2(void)
{
	int* parr = new int[10];

	for (int i = 0; i < 10; i++)
	{
		parr[i] = 100 + i;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << parr[i] << endl;
	}

	//ɾ���������ٵ�����ʱ��delete����Ҫ����[]
	delete[] parr;
}

int main()
{
	//test1();
	test2();

	return 0;
}