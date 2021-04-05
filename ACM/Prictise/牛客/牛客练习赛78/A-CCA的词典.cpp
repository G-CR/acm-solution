#include <bits/stdc++.h>
using namespace std;

int n, q;
string s;
map <string, int> num;

int main() {
	scanf("%d", &n);
	while(n--) {
		cin >> s;
		sort(s.begin(), s.end());
		num[s]++;
	}
	
	scanf("%d", &q);
	while(q--) {
		cin >> s;
		sort(s.begin(), s.end());
		printf("%d\n", num[s]);
	}
}