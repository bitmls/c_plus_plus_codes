#include "circle.h"

//����Բ������λ�ã��뾶
void Circle::setCircle(Point p1, double r)
{
	cirPoint = p1;
	R = r;
}

//�жϵ���Բ���ĸ�λ��,��Բ�ڷ���-1����Բ�Ϸ���0����Բ�ⷵ��1
int Circle::PointPosition(Point p)
{
	if (R > p.getLength(cirPoint))
	{
		return -1;
	}
	else if (R == p.getLength(cirPoint))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}