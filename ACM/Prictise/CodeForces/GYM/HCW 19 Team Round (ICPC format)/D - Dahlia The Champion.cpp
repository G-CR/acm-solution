#include <bits/stdc++.h>
using namespace std;
struct Node{
	double k;
	int right;
	int up;
	friend bool operator < (const Node& n1, const Node& n2)
	{
		if(n1.right == n2.right) return n1.up < n2.up;
		if(n1.k==n2.k)return n1.right < n2.right;
		return n1. k < n2. k;
	}
}node;

int n,ans;
double r,x,y,a,b,t,s;
int onxrt,onyup;
set <Node> sst;

int main() {
	scanf("%lf %lf %lf %d", &x, &y, &r, &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lf %lf", &a, &b);
		s = sqrt((a-x)*(a-x) + (b-y)*(b-y));
		if(s > r) continue;
		if(x == a) t = 9999999999;
		else t = (y-b)/(x-a);
		
		if(a-x > 0) onxrt = 1;
		else if(a-x == 0) onxrt = 0;
		else onxrt = -1;
		
		if(b-y > 0) onyup = 1;
		else if(b-y == 0) onyup = 0;
		else onyup = -1;
		
		node.k = t; node.right = onxrt; node.up = onyup;
		if(sst.count(node) == 0){
			ans++;
			sst.insert(node);
		}
	}
	printf("%d\n",ans);
}