#include <iostream>
using namespace std;
#include "point.h"
#include "circle.h"

//class Point
//{
//public:
//	//���õ������
//	void setPoint(int x, int y)
//	{
//		m_X = x;
//		m_Y = y;
//	}
//
//	//���ص��ˮƽ����
//	int getX()
//	{
//		return m_X;
//	}
//	//���ص����ֱ����
//	int getY()
//	{
//		return m_Y;
//	}
//
//	//��������֮��ĳ���
//	double getLength(Point p)
//	{
//		return sqrt(pow(abs(p.getX() - m_X), 2) + pow(abs(p.getY() - m_Y), 2));
//	}
//
//private:
//	int m_X;
//	int m_Y;
//};

//class Circle
//{
//public:
//	//����Բ������λ�ã��뾶
//	void setCircle(Point p1, double r)
//	{
//		cirPoint = p1;
//		R = r;
//	}
//
//	//�жϵ���Բ���ĸ�λ��,��Բ�ڷ���-1����Բ�Ϸ���0����Բ�ⷵ��1
//	int PointPosition(Point p)
//	{
//		if (R > p.getLength(cirPoint))
//		{
//			return -1;
//		}
//		else if (R == p.getLength(cirPoint))
//		{
//			return 0;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//
//private:
//	Point cirPoint;
//	double R;
//};

int main()
{
	Point p1;
	Point pCir1;
	Circle c1;
	
	p1.setPoint(1, 1);
	pCir1.setPoint(4, 5);

	c1.setCircle(pCir1, 5);

	int ret = c1.PointPosition(p1);
	if (ret == 1)
	{
		cout << "����Բ��" << endl;
	}
	else if (ret == 0)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}

	return 0;
}