#include <iostream>
using namespace std;

const int M = 20000;
bool isprime[M+5];

void solve() {
	for(int i = 2;i <= M; i++) isprime[i] = 1;
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) {
			for(int j = i*2; j<= M; j += i)
				isprime[j] = 0;
		}
	}
	isprime[2] = 0;
}

int x;

int main() {
	solve();
	int cnt = 0;
	while(~scanf("%d", &x) && x>0) {
		printf("%d: ", ++cnt);
		if(isprime[x]) puts("yes");
		else puts("no");
	}
}