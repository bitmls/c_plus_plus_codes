#pragma once
#include <iostream>
using namespace std;

class Point
{
public:
	//���õ������
	void setPoint(int x, int y);

	//���ص��ˮƽ����
	int getX();
	//���ص����ֱ����
	int getY();

	//��������֮��ĳ���
	double getLength(Point p);

private:
	int m_X;
	int m_Y;
};
