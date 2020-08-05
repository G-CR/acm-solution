#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
	if (num <= 3) {
		return num > 1;
	}
	// 不在6的倍数两侧的一定不是质数
	if (num % 6 != 1 && num % 6 != 5) {
		return false;
	}
	int t = (int)sqrt(num);
	for (int i = 5; i <= t; i += 6) {
		if (num % i == 0 || num % (i + 2) == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		if(isPrime(n)) cout << "Is Prime" << endl;
		else cout << "Not Prime" << endl;
	}
	
}