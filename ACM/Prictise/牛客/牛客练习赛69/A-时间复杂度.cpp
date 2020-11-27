#include <bits/stdc++.h>
using namespace std;

int _, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		double fen = (6 * n) % 360;
		double shi = 0.5 * n;
		double cha = (fabs(fen-shi));
		printf("%d\n", (int)(min(cha, 360-cha)+0.5));
	}
}