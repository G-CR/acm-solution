#include <bits/stdc++.h>
using namespace std;

const int LIM = 3e7 + 10;
int prime[LIM / 3];
int miniFactor[LIM];
int primepos;

void euler() {
	int tmp;
	for (int i = 2; i < LIM; i++) {
		if (!miniFactor[i]) prime[primepos++] = i, miniFactor[i] = i;
		for (int j = 0; (tmp = i * prime[j]) < LIM; j++) {
			miniFactor[tmp] = prime[j];
			if (!(i % prime[j])) break;
		}
	}
}

int main() {
	euler();
	long long sum = 0;
	int n;
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		sum += miniFactor[i];
	}
	printf("%lld\n", sum);
}