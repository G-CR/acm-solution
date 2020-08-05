#include <bits/stdc++.h>
using namespace std;

struct node {
	int len;
	string s;
	bool operator < (const node&o) const {
		return len<o.len;
	}
}str[105];
int n;

bool check(string s1, string s2) {
	int n1 = s1.length();
	int n2 = s2.length();
	int i = 0, j = 0;
	while(i < n1 && j < n2) {
		if(s1[i] == s2[j]) {
			i++; j++;
		}
		else {
			i = i-j+1;
			j = 0;
		}
	}
	if(j == n2) return 1;
	else return 0;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		cin >> str[i].s;
		str[i].len = str[i].s.length();
	}
	sort(str+1, str+1+n);
//	for(int i = 1;i <= n; i++) cout << str[i].s << endl;
	
	bool ok = 1;
	for(int i = 2;i <= n; i++) {
		if(!check(str[i].s, str[i-1].s)) {
			ok = 0;
			break;
		}
	}
	if(ok) {
		puts("YES");
		for(int i = 1;i <= n; i++) cout << str[i].s << endl;
	}
	else puts("NO");
}