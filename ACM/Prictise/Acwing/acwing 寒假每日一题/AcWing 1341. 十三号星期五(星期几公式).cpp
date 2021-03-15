#include <bits/stdc++.h>
using namespace std;

int n;
int num[12];

int cal(int year, int month, int day) {
	if (month == 1 || month == 2) month += 12, year--;
	return (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
} // 0 -> 星期天

int main() {
	scanf("%d", &n);
	for(int i = 1900;i <= 1900+n-1; i++) {
		for(int j = 1;j <= 12; j++) {
			int w = cal(i, j, 13);
			num[w]++;
		}
	}
	
	for(int i = 0;i < 7; i++) {
		printf("%d ", num[(i+6)%7]);
	}
}