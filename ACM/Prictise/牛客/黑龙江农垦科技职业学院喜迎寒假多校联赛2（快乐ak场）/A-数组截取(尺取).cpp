#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[20000007];

inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main() {
	n = read(); k = read();
	for(int i = 1;i <= n; i++) {
		a[i] = read();
	}
	
	int l = 1, r = 0;
	long long now = -1;
	int ans = -1;
	
	while(r <= n) {
		if(now == k) {
			ans = max(ans, r-l+1);
			now += a[++r];
		}
		else if(now < k) {
			if(now == -1) now = a[++r];
			else now += a[++r];
		}
		else {
			if(r-l+1 > ans) now -= a[l++];
			else {
				now += a[++r];
				now -= a[l++];
			}
		}
	}
	
	printf("%d\n", ans);
}