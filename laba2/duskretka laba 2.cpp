#include <iostream>
using namespace std;

void Print(int* a, int n, int i)
{
	if (n)
	{
		if (n & 1)
			cout << a[i] << " ";
		Print(a, n >> 1, i + 1);
	}
}
int main() {
	int capacity1, capacity2, capacity3;
	cout << "Enter the capacity of U : " << endl;
	cin >> capacity1;
	int* arr1 = new int[capacity1];
	cout << "Enter the U : " << endl;
	for (int i = 0; i < capacity1; i++)
	{
		cin >> arr1[i];
	}
	cout << "Enter the capacity of plural : " << endl;
	cin >> capacity2;
	int* arr2 = new int[capacity2];
	cout << "Enter the plural : " << endl;
	for (int j = 0; j < capacity2; j++)
	{
		cin >> arr2[j];
	}
	cout << "Enter the addition of plural :" << endl;

	capacity3 = capacity1 + capacity2;
	int* arr3 = new int[capacity3];
	int k = 0;
	int p = 0;
	for (int i = 0; i < capacity1; i++)
	{
		for (int j = 0; j < capacity2; j++)
		{
			if (arr1[i] == arr2[j])
			{
				p = 1;
			}

		}
		if (p < 1)
		{
			arr3[k] = arr1[i];
			k++;
		}
		p = 0;
	}

	for (int i = 0; i < k; i++)
		cout << arr3[i] << endl;
	cout << "The boolean of plural is : " << endl;
	for (int i = 0; i < k * k; i++) {
		Print(arr3, i, 0);
		cout << "\n";
	}
	system("pause");
}