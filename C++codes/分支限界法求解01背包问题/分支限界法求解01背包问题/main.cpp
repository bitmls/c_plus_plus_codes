#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Thing {
public:
	Thing(int w, int v);
	double GetK();
	bool operator<(const Thing& s) const {
		return m_k > s.m_k;
	}

	int m_w;  // ����
	int m_v;  // ��ֵ
	double m_k;  // ��λ��ֵ
};

class TreeNode {
public:
	double CalcUb();

	int m_W;  // ��ǰ����
	int m_V;  // ��ǰ��ֵ
	int m_ub;  // �ý���Ͻ�
};

Thing::Thing(int w, int v) {
	m_w = w;
	m_v = v;
}

double Thing::GetK() {
	return (double)m_v / (double)m_w;
}

double TreeNode::CalcUb() {
	return 0;
}

int main() {
	int capacity;  // ����
	int count;  // ��Ʒ������

	cout << "The capacity of this backpack is:";
	cin >> capacity;
	cout << "The count of goods is:";
	cin >> count;

	vector<Thing>things;

	for (int i = 0; i < count; i++) {
		int w, v;
		cout << "weight:";
		cin >> w;
		cout << "value:";
		cin >> v;
		Thing temp(w, v);
		things.push_back(temp);
	}

	sort(things.begin(), things.end());

	for (int i = 0; i < count; i++) {
		cout << "w=" << things[i].m_w << ", v=" << things[i].m_v << ", k=" << things[i].GetK() << endl;
	}

	return 0;
}