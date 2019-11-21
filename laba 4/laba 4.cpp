#include <iostream>
using namespace std;

int main()
{
	
	int v, count = 0, min = 0, k, t;
	bool check = false;
	cout << "The number of vertices of the graph : ";
	cin >> v;
	int* tops = new int[v];
	//для матриці ваг
	int** matrix = new int* [v];
	for (int i = 0; i < v; i++) {
		matrix[i] = new int[v];
	}
	//для ребер
	int** rebra = new int* [v - 1];

	for (int i = 0; i < v - 1; i++) {
		rebra[i] = new int[2];
	}
	//ввід матриці ваг
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			cin >> matrix[i][j];
		}
	}
	//беремо вершину один як початкову

	tops[count] = 1;
	count++;

	for (int i = 0; count < v; i++) {
		for (int j = 0; j < count; j++) {
			for (int a = 0; a < v; a++) {
				for (int m = 0; m < count; m++) {
					//перевірка чи вершина вже була пройде, якщо так, то переходимо до наступної ітерації
					if (tops[m] == a + 1) {
						check = true;
					}
				}

				if (check) { check = false; continue; }
				//шукаємо мінімальний елемент в рядку, спочатку береться просто перший ненульовий елемент, а потім вже шукаєм відносно нього, це в наступному іфі
				if (min == 0 && matrix[tops[j] - 1][a] > 0) {
					min = matrix[tops[j] - 1][a];
					k = rebra[count - 1][0] = tops[j]; t = rebra[count - 1][1] = a + 1;
					continue;
				}

				if (matrix[tops[j] - 1][a] > 0 && matrix[tops[j] - 1][a] < min) {
					min = matrix[tops[j] - 1][a];
					//записуємо ребро
					k = rebra[count - 1][0] = tops[j]; t = rebra[count - 1][1] = a + 1;
				}
			}
		}
		//Обнулюємо ребро, бо вже не можемо по ньому проходити і маємо опускати в подальшому пошуку
		matrix[k - 1][t - 1] = 0; matrix[t - 1][k - 1] = 0;
		//Додаємо знайдену вершину в масив вершин
		tops[count] = t;
		count++;
		min = 0;
	}
	//output
  //Виводимо наш масив вершин, який вийшов, які послідовно додавались
	cout << "V: { ";

	for (int j = 0; j < v; j++) {
		cout << tops[j] << ", ";
	}

	cout << "}";
	//і виводимо ребра
	cout << endl << "E:{ ";

	for (int j = 0; j < v - 1; j++) {
		cout << "(" << rebra[j][0] << "," << rebra[j][1] << "),";
	}
	cout << "}";
	return 0;

}