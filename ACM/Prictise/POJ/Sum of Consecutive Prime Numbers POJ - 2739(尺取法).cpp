#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int M = 10000;
bool isprime[M+5];
vector <int> prime;
int n;

void solve() {
	for(int i = 1;i <= M; i++) isprime[i] = 1;
	for(int i = 3;i <= M; i++) if(!(i%2)) isprime[i] = 0;
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) {
			for(int j = i*2; j<= M; j += i)
				isprime[j] = 0;
		}
	}
	isprime[1] = 0;
	for(int i = 2;i <= M; i++)
		if(isprime[i]) prime.push_back(i);
}

int main() {
	solve();
	int len = prime.size();
	while(~scanf("%d", &n) && n) {
		int l = 0, r = 0, ans = 0, sum = 0;
		while(prime[r] <= n) {
			sum += prime[r];
			while(sum > n) {
				sum -= prime[l++];
			}
			if(sum == n) ans++;
			r++;
		}
		
		printf("%d\n", ans);
	}
}