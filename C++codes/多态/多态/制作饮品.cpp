//#include <iostream>
//using namespace std;
//
//class AbstractDrinking
//{
//public:
//	// ��ˮ
//	virtual void Boil() = 0;
//	// ����
//	virtual void Brew() = 0;
//	// ���뱭��
//	virtual void PourInCup() = 0;
//	// ��������
//	virtual void PutSomething() = 0;
//
//	// ��������
//	void MakeDrink()
//	{
//		Boil();
//		Brew();
//		PourInCup();
//		PutSomething();
//	}
//};
//
//class Coffee :public AbstractDrinking
//{
//public:
//	// ��ˮ
//	void Boil()
//	{
//		cout << "��ũ����ȭ" << endl;
//	}
//	// ����
//	void Brew()
//	{
//		cout << "�忧�ȷ�" << endl;
//	}
//	// ���뱭��
//	void PourInCup()
//	{
//		cout << "��������" << endl;
//	}
//	// ��������
//	void PutSomething()
//	{
//		cout << "����ţ��" << endl;
//	}
//};
//
//class Tea :public AbstractDrinking
//{
//public:
//	// ��ˮ
//	void Boil()
//	{
//		cout << "������ˮ" << endl;
//	}
//	// ����
//	void Brew()
//	{
//		cout << "���Ҷ" << endl;
//	}
//	// ���뱭��
//	void PourInCup()
//	{
//		cout << "��������" << endl;
//	}
//	// ��������
//	void PutSomething()
//	{
//		cout << "�������" << endl;
//	}
//};
//
//// ��������
//void doWork(AbstractDrinking* abs)
//{
//	abs->MakeDrink();
//	delete abs;
//}
//
//void test()
//{
//	doWork(new Coffee);
//	cout << "---------------------" << endl;
//	doWork(new Tea);
//}
//
//int main()
//{
//	test();
//	return 0;
//}