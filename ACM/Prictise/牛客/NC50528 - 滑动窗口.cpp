#include <bits/stdc++.h>
using namespace std;

int n, k, a[1000006];
struct node {
	int dig, pos;
} deq[1000006];

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	int head = 1, tail = 0;
	node t;
	for(int i = 1;i <= n; i++) {
		while(head <= tail && deq[head].pos < i-k+1) head++; // 删除过期的元素
		while(head <= tail && a[i] <= deq[tail].dig) tail--;// 保持单调队列的递增性
		t.dig = a[i]; t.pos = i;
		deq[++tail] = t;
		if(i >= k) printf("%d ", deq[head].dig);
	}
	puts("");
	
	head = 1, tail = 0;
	for(int i = 1;i <= n; i++) {
		while(head <= tail && deq[head].pos < i-k+1) head++;
		while(head <= tail && a[i] >= deq[tail].dig) tail--;
		t.dig = a[i]; t.pos = i;
		deq[++tail] = t;
		if(i >= k) printf("%d ", deq[head].dig);
	}
	puts("");
}