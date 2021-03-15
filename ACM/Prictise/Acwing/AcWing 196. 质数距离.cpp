#include <bits/stdc++.h>
using namespace std;

long long l, r;
const int N = 1e5;
long long isprime[N+10], prime[N+10];
int pn = 0;

void getprime() {
	memset(isprime, -1, sizeof(isprime));
	for(int i = 2;i < N;i++){
		if(isprime[i]) prime[pn++] = i;
		for(int j = 0;j < pn && 1ll*i*prime[j] < N;j++) {
			isprime[i*prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
}

bool gun[1000006];

int main() {
	getprime();
	while(~scanf("%lld %lld", &l, &r)) {
		memset(gun, 0, sizeof(gun));
		if(l == 1) gun[0] = 1;
		for(int i = 0;i < pn; i++) {
			for(long long j = max((double)2, ceil((double)l/prime[i])); j <= r/prime[i]; j++) {
				gun[prime[i] * j - l] = 1;
			}
		}
		
		vector <long long> pr;
		for(long long i = l;i <= r; i++) {
			if(!gun[i-l]) pr.push_back(i);
		}
		
		int cla, clb, cl = 1e9, moa, mob, mo = -1;
		if(pr.size() < 2) puts("There are no adjacent primes.");
		else {
			for(int i = 1;i < pr.size(); i++) {
				int cha = pr[i] - pr[i-1];
				if(cha < cl) {
					cla = pr[i-1];
					clb = pr[i];
					cl = cha;
				}
				if(cha > mo) {
					moa = pr[i-1];
					mob = pr[i];
					mo = cha;
				}
			}
			printf("%d,%d are closest, %d,%d are most distant.\n", cla, clb, moa, mob);
		}
	}
}