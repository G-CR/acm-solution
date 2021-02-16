#include <bits/stdc++.h>
using namespace std;

int n, m;
char str[1000006];
int son[1000006][26], idx;
int cnt[1000006];

void insert() {
	int p = 0;
	for(int i = 0; str[i]; i++) {
		int& s = son[p][str[i]-'a'];
		if(!s) s = ++idx;
		p = s;
	}
	cnt[p]++;
}

int query() {
	int p = 0, res = 0;
	for(int i = 0; str[i]; i++) {
		int s = son[p][str[i]-'a'];
		if(!s) break;
		p = s;
		res += cnt[p];
	}
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	while(n--) {
		scanf("%s", str);
		insert();
	}
	
	while(m--) {
		scanf("%s", str);
		printf("%d\n", query());
	}
}