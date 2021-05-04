#include <bits/stdc++.h>
using namespace std;

int a[1000000];

int get_mid(int l, int r) {
	int key = a[l];
	while(l < r) {
		while(l < r && a[r] >= key) r--;
		a[l] = a[r];
		while(l < r && a[l] <= key) l++;
		a[r] = a[l];
	}
	a[l] = key;
	return l;
}

void quick_sort(int l, int r) {
	if(l < r) {
		int mid = get_mid(l, r);
		quick_sort(l, mid-1);
		quick_sort(mid+1, r);
	}
}

int main() {
	srand(time(NULL));
	int n = 10;
	for(int i = 0; i < n; i++)
		a[i] = n-i;
	
	quick_sort(0, n-1);
	
	printf("n = %d\n", n);
	for(int i = 0; i < n; i++)
		printf("%lld ", a[i]); puts("");
}