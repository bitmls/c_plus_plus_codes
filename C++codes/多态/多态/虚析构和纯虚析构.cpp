//#include <iostream>
//using namespace std;
//
//class Animal
//{
//public:
//	Animal()
//	{
//		cout << "Animal���캯���ĵ���" << endl;
//	}
//	virtual ~Animal()
//	{
//		cout << "Animal���������ĵ���" << endl;
//	}
//	virtual void Speak() = 0;
//public:
//	string* m_Name;
//};
//
//class Cat :public Animal
//{
//public:
//	Cat(string name)
//	{
//		m_Name = new string(name);
//		cout << "Cat���캯���ĵ���" << endl;
//	}
//	~Cat()
//	{
//		if (m_Name != NULL)
//		{
//			delete m_Name;
//			m_Name = NULL;
//			cout << "Cat���������ĵ���" << endl;
//		}
//	}
//	void Speak()
//	{
//		cout << *m_Name << "��˵��" << endl;
//	}
//};
//
//void test()
//{
//	Animal* animal = new Cat("Tom");
//	animal->Speak();
//	delete animal;
//	animal = NULL;
//}
//
//int main()
//{
//	test();
//	return 0;
//}