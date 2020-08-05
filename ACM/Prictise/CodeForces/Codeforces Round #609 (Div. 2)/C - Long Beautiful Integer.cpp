#include <bits/stdc++.h>
using namespace std;

int n, k;
string a, b;

int main() {
	scanf("%d %d", &n, &k);
	cin >> a; b = a;
	for(int i = k;i < n; i++) b[i] = b[i-k];
	
	int j = k-1;
	while(a > b) {
		while(b[j] == '9') {
			b[j] = '0'; 
			j--;
		}
		b[j] += 1;j--;
	}
	for(int i = k;i < n; i++) b[i] = b[i-k];
	printf("%d\n", n);
	cout << b << endl;
}