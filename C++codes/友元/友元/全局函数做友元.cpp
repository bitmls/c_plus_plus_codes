//#include <iostream>
//using namespace std;
//
//class Building
//{
//	friend void goodGay(Building& b);
//
//public:
//	Building()//�ú���������ë������Ҳ����������ë��Զ��д���룬��ѹ������������ë
//	{
//		m_SettingRoom = "����";
//		m_BedRoom = "r";
//	}
//
//public:
//	string m_SettingRoom;
//private:
//	string m_BedRoom;
//};
//
//void goodGay(Building& b)
//{
//	cout << "goodGay����" << b.m_SettingRoom << endl;
//	cout << "goodGay����" << b.m_BedRoom << endl;
//}
//
//void test0()
//{
//	Building b;
//	goodGay(b);
//}
//
////int main()
////{
////	test0();
////	return 0;
////}