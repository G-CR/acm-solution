#include <bits/stdc++.h>
using namespace std;

int _, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		if(n % 2 == 0) {
			for(int i = n; i >= 1; i--) printf("%d ", i);
		}
		else {
			int mid = (n+1)/2;
			for(int i = n;i >= 1; i--) {
				if(i == mid+1) printf("%d ", mid);
				else if(i == mid) printf("%d ", mid+1);
				else printf("%d ", i);
			}
		}
		puts("");
	}
}