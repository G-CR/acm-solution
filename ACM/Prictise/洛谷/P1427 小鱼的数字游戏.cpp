#include <bits/stdc++.h>
using namespace std;

int a[105];

int main() {
	int n;
	for(int i = 1;;i++) {
		scanf("%d", &a[i]);
		if(a[i] == 0) {
			n = i;
			break;
		} 
	}
	
	for(int i = n-1; i >= 1; i--) {
		printf("%d ", a[i]);
	}
}