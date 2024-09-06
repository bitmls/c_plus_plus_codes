//-----------------------------------------------------------------------------
// *********************         ְ������ϵͳ         **************************
//-----------------------------------------------------------------------------
// *********************        0.�˳��������        **************************
// *********************        1.����ְ����Ϣ        **************************
// *********************        2.��ʾְ����Ϣ        **************************
// *********************        3.ɾ����ְְ��        **************************
// *********************        4.�޸�ְ����Ϣ        **************************
// *********************        5.����ְ����Ϣ        **************************
// *********************        6.���ձ������        **************************
// *********************        7.��������ĵ�        **************************
//-----------------------------------------------------------------------------


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class Employee
{
public:
	enum class EmployeeType
	{
		COMMON,
		MANAGER,
		BOSS
	};

public:
	int id;
	string name;
	int level;
};

class Company
{
public:
	vector<Employee> employees_list;
};


void menu()
{
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << " *********************         ְ������ϵͳ         **************************" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << " *********************        0.�˳��������        **************************" << endl;
	cout << " *********************        1.����ְ����Ϣ        **************************" << endl;
	cout << " *********************        2.��ʾְ����Ϣ        **************************" << endl;
	cout << " *********************        3.ɾ����ְְ��        **************************" << endl;
	cout << " *********************        4.�޸�ְ����Ϣ        **************************" << endl;
	cout << " *********************        5.����ְ����Ϣ        **************************" << endl;
	cout << " *********************        6.���ձ������        **************************" << endl;
	cout << " *********************        7.��������ĵ�        **************************" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
}

void write_infomation_into_file(Company& company)
{
	ofstream ofs("employees_list.txt", ios::out);

	ofs << company.employees_list.size() << endl;
	for (Employee employee : company.employees_list)
		ofs << employee.id << " " << employee.name << " " << employee.level << endl;

	ofs.close();
}

void exit_system()
{
	cout << "�˳��ɹ�" << endl;
	exit(0);
}

void add_employee_infomation(Company& company)
{
	int add_num;
	cout << "��Ҫ��ӵ�������";
	cin >> add_num;

	for(int i = 0; i < add_num; i++) {
		Employee new_employee;

		cout << "������Ա�� id ��";
		cin >> new_employee.id;
		cout << "������Ա�� ���� ��";
		cin >> new_employee.name;
		cout << "������Ա�� ���� ��";
		cin >> new_employee.level;

		company.employees_list.push_back(new_employee);

		cout << "��" << i + 1 << "��Ա��������" << endl;
	}

	write_infomation_into_file(company);

	cout << "����Ա�������ɣ���ǰְ������Ϊ " << company.employees_list.size() << " ��" << endl;

	system("pause");
	system("cls");
}

void show_employee_infomation(const Company& company)
{
	cout << "��ǰְ����������" << company.employees_list.size() << endl;
	for (Employee employee : company.employees_list)
	{
		cout << "id = " << employee.id << " name = " << employee.name << " level = " << employee.level << endl;
	}

	system("pause");
	system("cls");
}

void delete_departing_employee(Company& company)
{
	int input;
	int input_id;
	string input_name;

	cout << "0.�˳�" << endl;
	cout << "1.�� id ɾ��" << endl;
	cout << "2.�� name ɾ��" << endl;
	cout << "�����룺" << endl;

	cin >> input;

	switch (input)
	{
	case 0:
		cout << "�˳�" << endl;
		break;
	case 1:
		cout << "������Ҫɾ����Ա���� id :";
		cin >> input_id;

		for (int i = 0; i < company.employees_list.size(); i++)
		{
			if (company.employees_list[i].id == input_id) {
				company.employees_list.erase(company.employees_list.begin() + i);

				write_infomation_into_file(company);

				cout << "ɾ���ɹ�����ǰְ������Ϊ " << company.employees_list.size() << " ��" << endl;

				system("pause");
				system("cls");

				return;
			}
		}

		cout << "δ�ҵ��� id �ŵ�Ա��" << endl;

		break;
	case 2:
		cout << "������Ҫɾ����Ա���� name :";
		cin >> input_name;

		for (int i = 0; i < company.employees_list.size(); i++)
		{
			if (company.employees_list[i].name.compare(input_name))
			{
				company.employees_list.erase(company.employees_list.begin() + i);

				write_infomation_into_file(company);

				cout << "ɾ���ɹ�����ǰְ������Ϊ " << company.employees_list.size() << " ��" << endl;

				system("pause");
				system("cls");

				return;
			}
		}

		cout << "δ�ҵ��� id �ŵ�Ա��" << endl;

		break;
	default:
		cout << "�������" << endl;
		break;
	}

	system("pause");
	system("cls");
}

void modify_employee_infomation(Company& company)
{
	int input;
	int input_id;
	string input_name;

	cout << "0.�˳�" << endl;
	cout << "1.�� id ����" << endl;
	cout << "2.�� name ����" << endl;
	cout << "�����룺" << endl;
	
	cin >> input;

	switch (input)
	{
	case 0:
		cout << "�˳�" << endl;
		break;
	case 1:
		cout << "������Ҫ�޸ĵ�Ա���� id ";
		cin >> input_id;

		for (int i = 0; i < company.employees_list.size(); i++)
		{
			Employee& employee = company.employees_list[i];
			if (employee.id == input_id)
			{
				cout << "���ҵ���Ҫ�޸ĵ�Ա��" << endl;
				cout << "������Ա�� id ��";
				cin >> employee.id;
				cout << "������Ա�� ���� ��";
				cin >> employee.name;
				cout << "������Ա�� ���� ��";
				cin >> employee.level;

				cout << "��Ϣ�޸ĳɹ���" << endl;

				write_infomation_into_file(company);

				system("pause");
				system("cls");

				return;
			}
		}
		
		break;
	case 2:
		cout << "������Ҫ�޸ĵ�Ա���� name ";
		cin >> input_name;

		for (int i = 0; i < company.employees_list.size(); i++)
		{
			Employee& employee = company.employees_list[i];
			if (employee.name.compare(input_name))
			{
				cout << "���ҵ���Ҫ�޸ĵ�Ա��" << endl;
				cout << "������Ա�� id ��";
				cin >> employee.id;
				cout << "������Ա�� ���� ��";
				cin >> employee.name;
				cout << "������Ա�� ���� ��";
				cin >> employee.level;

				cout << "��Ϣ�޸ĳɹ���" << endl;

				write_infomation_into_file(company);

				system("pause");
				system("cls");

				return;
			}
		}
		
		break;
	default:
		cout << "�������" << endl;
		break;
	}

	system("pause");
	system("cls");
}

void search_employee_infomation(Company& company)
{
	int input;
	int input_id;
	string input_name;

	cout << "0.�˳�" << endl;
	cout << "1.�� id ����" << endl;
	cout << "2.�� name ����" << endl;
	cout << "�����룺" << endl;

	cin >> input;

	switch (input)
	{
	case 0:
		cout << "�˳�" << endl;
		break;
	case 1:
		cout << "������Ҫ���ҵ�Ա���� id ";
		cin >> input_id;

		for (int i = 0; i < company.employees_list.size(); i++)
		{
			Employee& employee = company.employees_list[i];
			if (employee.id == input_id)
			{
				cout << "���ҵ���Ҫ���ҵ�Ա��" << endl;
				cout << "id ��" << employee.id;
				cout << " ���� ��" << employee.name;
				cout << " ���� ��" << employee.level << endl;

				system("pause");
				system("cls");

				return;
			}
		}

		cout << "δ�ҵ���Ա��" << endl;

		break;
	case 2:
		cout << "������Ҫ���ҵ�Ա���� name ";
		cin >> input_name;

		for (int i = 0; i < company.employees_list.size(); i++)
		{
			Employee& employee = company.employees_list[i];
			if (employee.name.compare(input_name))
			{
				cout << "���ҵ���Ҫ���ҵ�Ա��" << endl;
				cout << "id ��" << employee.id;
				cout << " ���� ��" << employee.name;
				cout << " ���� ��" << employee.level << endl;

				system("pause");
				system("cls");

				return;
			}
		}

		cout << "δ�ҵ���Ա��" << endl;

		break;
	default:
		cout << "�������" << endl;
		break;
	}

	system("pause");
	system("cls");
}

void sort_by_id(Company& company)
{
	for (int i = 0; i < company.employees_list.size() - 1; i++)
	{
		for (int j = 0; j < company.employees_list.size() - 1 - i; j++)
		{
			if (company.employees_list[j].id > company.employees_list[j + 1].id)
			{
				Employee temp_employee = company.employees_list[j];
				company.employees_list[j] = company.employees_list[j + 1];
				company.employees_list[j + 1] = temp_employee;
			}
		}
	}

	cout << "����ɹ�" << endl;

	cout << "��ǰְ����������" << company.employees_list.size() << endl;
	for (Employee employee : company.employees_list)
		cout << "id = " << employee.id << " name = " << employee.name << " level = " << employee.level << endl;

	write_infomation_into_file(company);

	system("pause");
	system("cls");
}

void clear_all_ducuments()
{
	ofstream ofs("employees_list.txt", ios::out);

	ofs.close();

	cout << "Ա���ļ������" << endl;

	system("pause");
	system("cls");
}

void workforce_management_system()
{
	Company company;

	ifstream ifs("employees_list.txt", ios::in);

	if (ifs.is_open())
	{
		int employee_num = 0;
		ifs >> employee_num;
		company.employees_list.resize(employee_num);

		for (Employee& employee : company.employees_list)
			ifs >> employee.id >> employee.name >> employee.level;

		ifs.close();
	}

	int input;

	while (1) {
		menu();
		cout << "�����룺";
		cin >> input;

		switch (input)
		{
		case 0:		exit_system();							break;
		case 1:		add_employee_infomation(company);		break;
		case 2:		show_employee_infomation(company);		break;
		case 3:		delete_departing_employee(company);		break;
		case 4:		modify_employee_infomation(company);	break;
		case 5:		search_employee_infomation(company);	break;
		case 6:		sort_by_id(company);					break;
		case 7:		clear_all_ducuments();					break;
		default: break;
		}
	}
}

int main()
{
	workforce_management_system();

	return 0;
}