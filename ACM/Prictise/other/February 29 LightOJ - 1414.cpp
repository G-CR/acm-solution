#include <bits/stdc++.h>
using namespace std;

int _;
string month1, day1, month2, day2;
long long year1, year2;
map <string, int> mon;

void init() {
	mon["January"] = 1; mon["February"] = 2; mon["March"] = 3;
	mon["April"] = 4; mon["May"] = 5; mon["June"] = 6; 
	mon["July"] = 7; mon["August"] = 8; mon["September"] = 9; 
	mon["October"] = 10; mon["November"] = 11; mon["December"] = 12;
}

bool check(long long year) {
	if(year % 100 == 0) {
		if(year % 400 == 0) return 1;
		else return 0;
	}
	else if(year % 4 == 0) return 1;
	else return 0;
}

int main() {
	init();
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		cin >> month1 >> day1 >> year1;
		cin >> month2 >> day2 >> year2;
		printf("Case %d: ", ++cas);
		
		int ans = (year2/4-year1/4) + (year2/400-year1/400) - (year2/100-year1/100);
		if(check(year1) && mon[month1] <= 2) ans++;
		if(check(year2) && !(mon[month2] >= 3 || (mon[month2] == 2 && day2 == "29,"))) ans--;
		
		printf("%d\n", ans);
	}
}