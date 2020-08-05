#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int a[4*N], n;
map<int, int> fa;
map<int, pair<int, int> > son;

int main() {
	scanf("%d", &n);
	int num = 0, head = 0;
	for(int i = 0;i <= 4*n; i++) a[i] = -1;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i] != -1) {
			if(!head) head = a[i];
			num++;
		} 
	}
	
	for(int i = 1;i <= n; i++) {
		if(a[i] != -1) {
			fa[a[i]] = a[i/2];
			son[a[i]] = make_pair(a[i*2], a[i*2+1]);
		}
	}
	
	
	printf("The size of the tree is %d\n", num);
	printf("Node %d is the root node of the tree\n", head);
	
	for(int i = 1;i <= num; i++) {
		printf("The father of node %d is %d, the left child is %d, and the right child is %d\n", i, fa[i], son[i].first, son[i].second);
	}
}