//#include <iostream>
//using namespace std;
//
//class Building;
//
//class GoodGay
//{
//public:
//	void visit(Building& b);
//};
//
//class Building
//{
//	friend class GoodGay;
//public:
//	Building();
//public:
//	string m_SettingRoom;
//private:
//	string m_BedRoom;
//};
//
//void GoodGay::visit(Building& b)
//{
//	cout << "�û������ڷ���" << b.m_SettingRoom << endl;
//	cout << "�û������ڷ���" << b.m_BedRoom << endl;
//}
//
//Building::Building()
//{
//	m_SettingRoom = "����";
//	m_BedRoom = "����";
//}
//
//void test()
//{
//	Building b;
//	GoodGay gg;
//	gg.visit(b);
//}
//
//int main()
//{
//	test();
//	return 0;
//}