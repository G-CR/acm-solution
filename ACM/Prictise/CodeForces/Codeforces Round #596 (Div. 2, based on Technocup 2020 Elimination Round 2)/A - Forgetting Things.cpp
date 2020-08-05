#include <bits/stdc++.h>
using namespace std;

int da, db;

int main() {
	scanf("%d %d", &da, &db);
	if(da + 1 == db) {
		printf("%d9 %d0", da, db);
		return 0;
	}
	if(da == db) {
		printf("%d0 %d1",da, db);
		return 0;
	}
	if(da == 9 && db == 1) {
		printf("%d9 %d00",da, db);
		return 0;
	}
	puts("-1");
}