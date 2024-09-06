#include <iostream>
using namespace std;

class Building;
class GoodGay
{
public:
	void visit(Building& b);
	void visit2(Building& b);
};

class Building
{
	friend void GoodGay::visit2(Building& b);
public:
	Building();
public:
	string m_SettingRoom;
private:
	string m_BedRoom;
};

Building::Building()
{
	m_SettingRoom = "����";
	m_BedRoom = "����";
}

void GoodGay::visit(Building& b)
{
	cout << "goodGay����" << b.m_SettingRoom << endl;
	//cout << "goodGay����" << b.m_BedRoom << endl;
}

void GoodGay::visit2(Building& b)
{
	cout << "goodGay����" << b.m_SettingRoom << endl;
	cout << "goodGay����" << b.m_BedRoom << endl;
}

void test()
{
	Building b;
	GoodGay gg;
	gg.visit(b);
	gg.visit2(b);
}

int main()
{
	test();
	return 0;
}