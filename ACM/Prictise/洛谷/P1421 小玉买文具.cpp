#include <bits/stdc++.h>
using namespace std;

double a,b;

int main() {
	cin >> a >> b;
	b /= 10;
	a += b;
	cout << (int)(a/1.9) << endl;
}