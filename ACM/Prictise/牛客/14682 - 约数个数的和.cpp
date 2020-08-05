#include <iostream>
using namespace std;


int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		ans = ans + (n/i);
	}
	printf("%d\n", ans);
	return 0;
}