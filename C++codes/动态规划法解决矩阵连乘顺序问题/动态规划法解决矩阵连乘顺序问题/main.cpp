#include<iostream>
using namespace std;
#define N 7

//��������ֵ 
void MatrixChain(int* p, int n, int m[][N], int s[][N]) {
	for (int i = 1; i <= n; i++) {  //��������ֻ��һ������ʱ������Ϊ0
		m[i][i] = 0;
	}
	for (int r = 2; r <= n; r++) {
		for (int i = 1; i <= n - r + 1; i++) {
			int j = i + r - 1; //��������ĩβ����ע��r-1����Ϊ������Ϊ2ʱ��ʵ��������+1
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;

			for (int k = i + 1; k < j; k++) {  //�����潫�������i+1��ʼ�����Զ����ĵ�ֱ��j-1Ϊֹ
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}

	}

}

//�������Ž� 
void Traceback(int i, int j, int s[][N]) {
	if (i == j)       //�ع�����
	{
		cout << "A" << i;
	}
	else       //������Ѷϵ�һ��Ϊ�������ż����ݹ�
	{
		cout << "(";
		Traceback(i, s[i][j], s);
		Traceback(s[i][j] + 1, j, s);
		cout << ")";
	}
}
int main() {
	int p[N] = { 30,35,15,5,10,20,25 };
	int m[N][N], s[N][N];

	MatrixChain(p, N - 1, m, s); //N-1��Ϊֻ����������
	cout << "�������ѳ˻���ʽΪ: ";
	Traceback(1, 6, s);
	return 0;
}
