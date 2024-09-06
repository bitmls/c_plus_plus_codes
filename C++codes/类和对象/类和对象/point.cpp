#include "point.h"

//���õ������
void Point::setPoint(int x, int y)
{
	m_X = x;
	m_Y = y;
}

//���ص��ˮƽ����
int Point::getX()
{
	return m_X;
}
//���ص����ֱ����
int Point::getY()
{
	return m_Y;
}

//��������֮��ĳ���
double Point::getLength(Point p)
{
	return sqrt(pow(abs(p.getX() - m_X), 2) + pow(abs(p.getY() - m_Y), 2));
}