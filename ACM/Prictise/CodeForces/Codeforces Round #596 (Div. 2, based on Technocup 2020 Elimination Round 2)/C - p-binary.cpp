#include <iostream>
using namespace std;

int cacu(int n) {
	if(n == 0) return 0;
	return n % 2 + cacu(n / 2);
}

int main() {
	int n, p, cnt = 0;
	scanf("%d %d", &n, &p);
	while(n > 0) {
		n -= p;
		cnt++;
		if(cacu(n) <= cnt) {
			if(n < cnt) break;
			printf("%d\n", cnt);
			return 0;
		}
	}
	puts("-1");
}