//#include <iostream>
//using namespace std;
//
//class Cube
//{
//public:
//	//���ó�����ĳ����
//	void setCube(double L, double W, double H)
//	{
//		m_L = L;
//		m_W = W;
//		m_H = H;
//	}
//
//	//��ȡ��
//	double getLength()
//	{
//		return m_L;
//	}
//	//��ȡ��
//	double getWidth()
//	{
//		return m_W;
//	}
//	double getHight()
//	{
//		return m_H;
//	}
//
//	//���㳤����ı����
//	double calcSurfaceArea()
//	{
//		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
//	}
//
//	//���㳤��������
//	double calcVolume()
//	{
//		return m_L * m_W * m_H;
//	}
//
//	//�Ƚ������������Ƿ����
//	bool isSame(Cube c2)
//	{
//		if (m_L == c2.m_L && m_W == c2.m_W && m_H == c2.m_H)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//private:
//	double m_L;
//	double m_W;
//	double m_H;
//};
//
//bool isSameCube(Cube& c1, Cube& c2)
//{
//	if (c1.getLength() == c2.getLength() &&
//		c1.getWidth() == c2.getWidth() &&
//		c1.getHight() == c2.getHight())
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int main()
//{
//	Cube c1, c2;
//
//	c1.setCube(3, 4, 5);
//	c2.setCube(3, 4, 5);
//
//	cout << "c1�ı����Ϊ��" << c1.calcSurfaceArea() << endl;
//	cout << "c1�����Ϊ��" << c1.calcVolume() << endl;
//	cout << "c1��c2�����" << c1.isSame(c2) << endl;
//	cout << "c1��c2�����" << isSameCube(c1, c2) << endl;
//
//	return 0;
//}