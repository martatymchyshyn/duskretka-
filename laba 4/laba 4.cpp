#include <iostream>
using namespace std;

int main()
{
	
	int v, count = 0, min = 0, k, t;
	bool check = false;
	cout << "The number of vertices of the graph : ";
	cin >> v;
	int* tops = new int[v];
	//��� ������� ���
	int** matrix = new int* [v];
	for (int i = 0; i < v; i++) {
		matrix[i] = new int[v];
	}
	//��� �����
	int** rebra = new int* [v - 1];

	for (int i = 0; i < v - 1; i++) {
		rebra[i] = new int[2];
	}
	//��� ������� ���
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			cin >> matrix[i][j];
		}
	}
	//������ ������� ���� �� ���������

	tops[count] = 1;
	count++;

	for (int i = 0; count < v; i++) {
		for (int j = 0; j < count; j++) {
			for (int a = 0; a < v; a++) {
				for (int m = 0; m < count; m++) {
					//�������� �� ������� ��� ���� ������, ���� ���, �� ���������� �� �������� ��������
					if (tops[m] == a + 1) {
						check = true;
					}
				}

				if (check) { check = false; continue; }
				//������ ��������� ������� � �����, �������� �������� ������ ������ ���������� �������, � ���� ��� ����� ������� �����, �� � ���������� ���
				if (min == 0 && matrix[tops[j] - 1][a] > 0) {
					min = matrix[tops[j] - 1][a];
					k = rebra[count - 1][0] = tops[j]; t = rebra[count - 1][1] = a + 1;
					continue;
				}

				if (matrix[tops[j] - 1][a] > 0 && matrix[tops[j] - 1][a] < min) {
					min = matrix[tops[j] - 1][a];
					//�������� �����
					k = rebra[count - 1][0] = tops[j]; t = rebra[count - 1][1] = a + 1;
				}
			}
		}
		//��������� �����, �� ��� �� ������ �� ����� ��������� � ���� �������� � ���������� ������
		matrix[k - 1][t - 1] = 0; matrix[t - 1][k - 1] = 0;
		//������ �������� ������� � ����� ������
		tops[count] = t;
		count++;
		min = 0;
	}
	//output
  //�������� ��� ����� ������, ���� ������, �� ��������� ����������
	cout << "V: { ";

	for (int j = 0; j < v; j++) {
		cout << tops[j] << ", ";
	}

	cout << "}";
	//� �������� �����
	cout << endl << "E:{ ";

	for (int j = 0; j < v - 1; j++) {
		cout << "(" << rebra[j][0] << "," << rebra[j][1] << "),";
	}
	cout << "}";
	return 0;

}