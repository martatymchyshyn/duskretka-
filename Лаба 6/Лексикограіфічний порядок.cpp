#include <iostream>
using namespace std;

void swap(int* a, int i, int j) {
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}
bool Existence(int* a, int n, int m) {
	int j;

	do {
		j = n - 1;
		while (j != -1 && a[j] >= a[j + 1]) j--;

		if (j == -1) {
			return false;
		}
		int k = n - 1;
		while (a[j] >= a[k]) {
			k--;
		}
		swap(a, j, k);

		int l = j + 1, r = n - 1;

		while (l < r) {
			swap(a, l++, r--);
		}
	} while (j > m - 1);
	return true;
}
void PrintPlacing(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main() {
	int* a, n, r;
	cout << "Enter the value" << endl;
	cout << "/////////////////////////////" << endl;
	do {
		cout << "Enter N :  ";
		cin >> n;
		cout << "/////////////////////////////" << endl;
		cout << "Enter R :  ";
		cin >> r;
	} while (n < r);

	cout << "/////////////////////////////" << endl;
	cout << "Lexicographic order : " << endl;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	PrintPlacing(a, r);
	while (Existence(a, n, r)) {
		PrintPlacing(a, r);
	}
}