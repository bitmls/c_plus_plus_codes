#include <iostream>
using namespace std;

class Student
{
public:
	string m_name = "��";
	int m_ID = 00000000;

	void AddName(string name)
	{
		m_name = name;
	}

	void AddID(int ID)
	{
		m_ID = ID;
	}

	void PrintInfomation()
	{
		cout << m_name << "��ѧ��Ϊ" << m_ID << endl;
	}
};

//int main()
//{
//	Student stu_1;
//	stu_1.PrintInfomation();
//	stu_1.AddName("�");
//	stu_1.AddID(20240309);
//	stu_1.PrintInfomation();
//
//	return 0;
//}