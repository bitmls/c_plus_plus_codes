#include <iostream>
using namespace std;

class Person {
public:
	Person() {
		m_age = 0;
		cout << "Ĭ�Ϲ��캯���ĵ���" << endl;
	}
	Person(int a) {
		m_age = a;
		cout << "�вι��캯���ĵ���" << endl;
	}
	Person(const Person& p) {
		m_age = p.m_age;
		cout << "�������캯���ĵ���" << endl;
	}

	~Person() {
		cout << "���������ĵ���" << endl;
	}

	int GetAge() {
		return m_age;
	}

private:
	int m_age;
};

int main() {
	//// 1.���ŷ�
	//Person p1;
	//Person p2(10);
	//Person p3(p2);
	// 
	//// 2.��ʾ��
	//Person p1;
	//Person p2 = Person(10);
	//Person p3 = Person(p2);

	// 3.��ʽת����
	Person p1;
	Person p2 = 10;
	Person p3 = p2;

	cout << "p1������Ϊ:" << p1.GetAge() << endl;
	cout << "p2������Ϊ:" << p2.GetAge() << endl;
	cout << "p3������Ϊ:" << p3.GetAge() << endl;

	return 0;
}