#include <iostream>
using namespace std;

class Circle
{
private:
	double PI = 3.14159265;

public:
	double m_r;

	double CalcCircumference()
	{
		return 2 * PI * m_r * m_r;
	}
};

//int main()
//{
//	Circle circle;
//	circle.m_r = 4;
//	cout << "Բ�İ뾶Ϊ" << circle.m_r << endl;
//	cout << "Բ���ܳ�Ϊ" << circle.CalcCircumference() << endl;
//
//	return 0;
//}