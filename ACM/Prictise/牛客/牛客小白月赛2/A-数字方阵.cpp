#include <bits/stdc++.h>
using namespace std;
const int maxn = 1003;

int n;
long long a[maxn][maxn];
bool vis_num[maxn*maxn];
map <long long, bool> vis_sum;

void shuchu() {
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= n; j++) {
			printf("%lld ", a[i][j]);
		}
		puts("");
	}
}

int main() {
	srand(time(NULL));
	scanf("%d", &n);
	
	while(1) {
		memset(vis_num, 0, sizeof vis_num);
		vis_sum.clear();
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= n; j++) {
				int now;
				while(1) {
					now = rand()%(n*n)+1;
					if(!vis_num[now]) {
						vis_num[now] = 1;
						break;
					}
				}
				a[i][j] = (long long)now;
			}
		}
		
//		shuchu();
		bool ok = 1;
		long long sum1, sum2;
		for(int i = 1;i <= n; i++) {
			long long sum1 = 0, sum2 = 0;
			for(int j = 1;j <= n; j++) {
				sum1 += a[i][j];
				sum2 += a[j][i];
			}
			if(vis_sum[sum1] || vis_sum[sum2]) {ok = 0; break;}
			vis_sum[sum1] = 1;
			vis_sum[sum2] = 1;
		}
		sum1 = 0, sum2 = 0;
		for(int i = 1;i <= n; i++) {
			sum1 += a[i][i];
			sum2 += a[i][n-i+1];
		}
		if(vis_sum[sum1] || vis_sum[sum2]) ok = 0;
		if(ok) break;
	}
	
	shuchu();
}