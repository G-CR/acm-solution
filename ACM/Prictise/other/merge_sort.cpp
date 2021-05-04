#include <bits/stdc++.h>
using namespace std;

int a[1000000], tmp[1000000];

void merge(int l, int r) {
	int mid = (l + r) >> 1;
	int i = l, j = mid+1;
	int p = 0;
	while(i <= mid && j <= r) {
		if(a[i] <= a[j]) tmp[p++] = a[i++];
		else tmp[p++] = a[j++];
	}
	while(i <= mid) tmp[p++] = a[i++];
	while(j <= r) tmp[p++] = a[j++];
	
	int k = 0;
	for(int i = l; i <= r; i++) {
		a[i] = tmp[k++];
	}
}

void merge_sort(int l, int r) {
	if(l < r) {
		int mid = (l + r) >> 1;
		merge_sort(l, mid);
		merge_sort(mid+1, r);
		merge(l, r);
	}
}


int main() {
	srand(time(NULL));
	int n = 10;
	for(int i = 0; i < n; i++) a[i] = n-i;
	printf("n = %d\n", n);	
	merge_sort(0, n-1);
	for(int i = 0; i < n; i++) 
		printf("%d ", a[i]); 
	puts("");
}