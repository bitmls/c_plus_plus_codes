#include <iostream>
using namespace std;

int BinarySearch(int* arr, int n, int num, int head, int tail) {
	int mid = (head + tail) / 2;
	while (head < tail) {  // ��ͷָ����βָ�벻ͬ
		if (num < arr[mid])  // num��������벿��
			mid = BinarySearch(arr, n, num, head, mid);
		else if(num > arr[mid])  // num�������Ұ벿��
			mid = BinarySearch(arr, n, num, mid + 1, tail);
	}
	return mid;
}

int main() {
	int* arr = new int[10];
	for (int i = 0; i < 10; i++)
		arr[i] = i;
	cout << BinarySearch(arr, 10, 4, 0, 9) << endl;

	return 0;
}