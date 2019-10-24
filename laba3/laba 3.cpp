#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int a;
	cout << "Enter the size of arrays :" << " ";
	cin >> a;
	int* array1 = new int[a];
	cout << "Enter the array1: " << endl;
	for (int i = 0; i < a; i++) {
		cin >> array1[i];

	}

	int* array2 = new int[a];
	cout << "Enter the array2: " << endl;
	for (int j = 0; j < a; j++) {
		cin >> array2[j];

	}
	int** matrix = new int* [a];
	for (int i = 0; i < a; i++) {
		matrix[i] = new int[a];
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			if (((2 * array1[i] - array2[j])) < 3) {
				matrix[i][j] = 1;
			}
			else {
				matrix[i][j] = 0;
			}

		}
	}
	cout << " Matrix : " << " " << endl;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			cout << matrix[i][j];

		}
		cout << endl;
	}
	cout << "Relation : " << endl;
	int  reflexive = 0;
	for (int i = 0; i < a; i++) {
		if (matrix[i][i] == 1) {
			reflexive++;

		}
	}
	if (reflexive == a) {
		cout << "Reflexive " << endl;
	}
	else if (reflexive < a && reflexive >0) {
		cout << "It is Not Reflexive " << endl;

	}
	else if (reflexive == 0) {
		cout << "Antireflexive" << endl;
	}

	bool sym = 0;
	bool sym1 = 0;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			if (matrix[i][j] == matrix[j][i] && i != j) {
				sym = 1;
			}
			else if (matrix[i][j] != matrix[j][i] && i != j) {
				sym1 = 1;
			}
		}
	}
	if (sym == 1 && sym1 == 0) {
		cout << "Symetric" << endl;
	}
	else if (sym == 1 && sym1 == 1) {
		cout << "Asymetric" << endl;
	}
	else {
		cout << "Antisymetric" << endl;
	}
	int q = 1, b = 1;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			for (int t = 0; t < a; t++) {
				if (i != j && j != t && t != i)
					if (matrix[i][j] == 1 && matrix[j][t] == 1 && matrix[i][t] == 0) {
						cout << "i=" << i << " j=" << j << " t=" << t << endl;
						q = 0;
					}
					else if (matrix[i][j] == 1 && matrix[j][t] == 1 && matrix[i][t] == 1) {
						b = 0;
					}
			}
		}
	}

	if (q == 1) {
		cout << "Tranzitive " << endl;
	}
	else if (b == 1) {
		cout << "Antitranzitive " << endl;
	}
	else {
		cout << "It is NOT Tranzitive " << endl;
		system("pause");

	}
}