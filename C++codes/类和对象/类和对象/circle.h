#pragma once
#include <iostream>
using namespace std;
#include "point.h"

class Circle
{
public:
	//����Բ������λ�ã��뾶
	void setCircle(Point p1, double r);

	//�жϵ���Բ���ĸ�λ��,��Բ�ڷ���-1����Բ�Ϸ���0����Բ�ⷵ��1
	int PointPosition(Point p);

private:
	Point cirPoint;
	double R;
};