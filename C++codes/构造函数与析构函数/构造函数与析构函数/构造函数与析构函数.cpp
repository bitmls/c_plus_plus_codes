#include <iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "���캯���ĵ���" << endl;
	}
	~Person() {
		cout << "���������ĵ���" << endl;
	}
};

//int main() {
//	Person p1;
//	system("pause");
//	return 0;
//}