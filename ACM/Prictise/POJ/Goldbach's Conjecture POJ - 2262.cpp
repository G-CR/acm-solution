#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int M = 1000000;
bool isprime[M+5];
vector <int> prime;
int a, b, n;

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
	while(~scanf("%d", &n) && n) {
		for(int i = 0;i < prime.size(); i++) {
			a = n - prime[i];
			if(isprime[a]) {
				b = prime[i];
				break;
			}
		}
		if(a > b) swap(a, b);
		printf("%d = %d + %d\n", n, a, b);
	}
}