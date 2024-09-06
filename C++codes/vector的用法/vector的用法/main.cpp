#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu
{
	string name;
	int score;
};

int main()
{
	vector<int>arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	//arr.pop_back();
	//arr.pop_back();
	//arr.pop_back();

	arr[0] = 100;

	cout << arr.size() << endl;
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;

	// vector<int>().swap(arr);  // ��������������ͷ��ڴ�

	cout << arr.empty() << endl;

	vector<int>vec1;
	vector<int>vec2;
	vec1.push_back(1);
	vec1.push_back(2);
	vec2 = vec1;
	for (int i = 0; i < vec2.size(); i++)
		cout << vec2[i] << " ";
	cout << endl;

	sort(arr.begin(), arr.begin() + 2);  // ����ǰ������

	//sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;

	vector<Stu>students;  // ���Դ����Զ������͵�����
	Stu s1;
	s1.name = "����";
	s1.score = 100;
	students.push_back(s1);
	students.push_back({ "Jack", 90 });

	for (int i = 0; i < students.size(); i++)
		cout << "name: " << students[i].name << " score: " << students[i].score << endl;

	vector<int>vast_arr(100, 0);  // ����һ��100��Ԫ����������Ϊ0������

	return 0;
}