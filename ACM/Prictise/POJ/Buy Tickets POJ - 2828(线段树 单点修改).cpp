#include <cstdio>
using namespace std;
const int maxn = 2e5+7;

int n, sum[maxn<<2], ans[maxn], x[maxn], val[maxn];

void build(int l, int r, int k) {
	sum[k] = r-l+1;
	if(l == r) return;
	int mid = (l+r)>>1;
	build(l, mid, k<<1);
	build(mid+1, r, k<<1|1);
}

void up(int num, int val, int l, int r, int k) {
	if(l == r) {
		ans[l] = val; sum[k]--; return;
	}
	
	int mid = (l+r)>>1;
	if(num <= sum[k<<1]) up(num, val, l, mid, k<<1);
	else up(num-sum[k<<1], val, mid+1, r, k<<1|1);
	
	sum[k] = sum[k<<1] + sum[k<<1|1];
}

int main() {
	while(~scanf("%d", &n)) {
		for(int i = 1;i <= n; i++) scanf("%d %d", &x[i], &val[i]);
		build(1, n, 1);
		for(int i = n;i >= 1; i--) {
			up(x[i]+1, val[i], 1, n, 1);
		}
		
		for(int i = 1;i <= n; i++) printf("%d ",ans[i]);
		puts("");
	}
}