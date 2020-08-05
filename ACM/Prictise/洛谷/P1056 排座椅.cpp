#include <bits/stdc++.h>
using namespace std;

int N, M, K, L, D;
int a, b, c, d;
struct node {
	int id;
	int num;
} num1[2000], num2[2000];
vector <int> ans1, ans2;

bool cmp(node a, node b) {
	return a.num > b.num;
}

int main() {
	scanf("%d %d %d %d %d", &M, &N, &K, &L, &D);
	for(int i = 0;i < 2000; i++) {
		num1[i].id = i; num2[i].id = i;
		num1[i].num = 0; num2[i].num = 0;
	}
	while(D--) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(a == c) {
			num2[min(b,d)].num++;
		}
		if(b == d) {
			num1[min(a,c)].num++;
		}
	}
	
	sort(num1, num1+1005, cmp); sort(num2, num2+1005, cmp);
	
	for(int i = K-1;i >= 0; i--) {
		ans1.push_back(num1[i].id);
	} 	
	for(int i = L-1;i >= 0; i--) {
		ans2.push_back(num2[i].id);
	} 
	
	sort(ans1.begin(), ans1.end());
	sort(ans2.begin(), ans2.end());
	
	for(int i = 0;i < ans1.size(); i++) printf("%d ", ans1[i]); puts("");
	for(int i = 0;i < ans2.size(); i++) printf("%d ", ans2[i]); puts("");
}