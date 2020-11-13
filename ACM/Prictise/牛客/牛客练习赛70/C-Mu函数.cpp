#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e7;
bool check[MAX+10];  
int prime[MAX+10];  
int mu[MAX+10];  
int n, _;
long long k;

void Mobius() {  
	memset(check,false,sizeof(check));  
	mu[1] = 1;  
	int tot = 0;  
	for(int i = 2; i <= MAX; i++) {
		if( !check[i] ) {  
			prime[tot++] = i;  
			mu[i] = -1;  
		}  
		for(int j = 0; j < tot; j++) {  
			if(i * prime[j] > MAX) break;  
			check[i * prime[j]] = true;  
			if( i % prime[j] == 0) {  
				mu[i * prime[j]] = 0;  
				break;  
			} else {  
				mu[i * prime[j]] = -mu[i];  
			}  
		}  
	}  
}

int main() {
	Mobius();
	scanf("%d", &_);
	while(_--) {
		vector <int> v;
		scanf("%d %lld", &n, &k);
		int now = mu[n]+n, a, b;
		for(int i = 1;i <= 10; i++) {
			v.push_back(now);
			if(i == 5) a = now;
			else if(i == 6) b = now;
			now = mu[now]+now;
		}
		if(k <= 10) printf("%d\n", v[k-1]);
		else {
			if(k % 2) printf("%d\n", a);
			else printf("%d\n", b);
		}
	}
}