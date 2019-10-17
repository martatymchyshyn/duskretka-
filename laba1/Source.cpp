#include<iostream>

using namespace std;

int main()
{
	int x, y, z, bracket1, bracket2, bracket3, bracket4, bracket5, bracket6, result;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	cout << "z=";
	cin >> z;
    if (x ==y) {
		bracket1 = 1;
	}
	else {
		bracket1 = 0;
	}
	if (y==z) {
		bracket2= 1;
	}
	else {
		bracket2 = 0;
	}
	if (z == x) {
		bracket3 = bracket4 = 1;
	}
	else {
		bracket3 = bracket4 = 0;
	}
	if (bracket2 == 1 && bracket3 == 0) {
		bracket5 = 0;
	}
	else {
		bracket5 = 1;
	}
	if (bracket5 == 1 && bracket4 == 0) {
		bracket6 = 0;
	}
	else {
		bracket6 = 1;
	}
	if (bracket1 == 0 && bracket6 == 0) {
		result = 0;
	}
	else if (bracket1 == 1 && bracket6 == 0) {
		result = 0;
	}
	else {
		result = 1;
	}
	if ((x == 1 || x == 0) && (y == 1 || y == 0 )&&( z == 1 || z == 0)) {
		cout << "The result of the task:" << result << endl;

	}
	else {
		cout << "Error" << endl;
	}
	
	system("pause");
}