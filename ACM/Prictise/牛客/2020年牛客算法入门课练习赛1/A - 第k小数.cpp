#include <bits/stdc++.h>
using namespace std;

int _, n, k, x, a[5000006];

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x<<1) + (x<<3) + (ch^48);
		ch = getchar();
	}
	return x * f;
}

int main() {
	_ = read();
	while(_--) {
		n = read(); k = read();
		for(int i = 0;i < n; i++) {
			a[i] = read();
		}
		nth_element(a, a+k-1, a+n);
		printf("%d\n", a[k-1]);
	}
}