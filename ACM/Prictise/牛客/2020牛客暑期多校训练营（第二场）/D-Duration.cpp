#include <bits/stdc++.h>
using namespace std;

string a, b;

int gettime(string s) {
	int h = 0, m = 0, ss = 0;
	for(int i = 0;i <= 1; i++) {
		h *= 10; h += s[i]-'0'; 
	}
	for(int i = 3;i <= 4; i++) {
		m *= 10; m += s[i]-'0'; 
	}
	for(int i = 6;i <= 7; i++) {
		ss *= 10; ss += s[i];
	}
	return ss+m*60+h*3600;
}

int main() {
	cin >> a >> b;
	int t1 = gettime(a);
	int t2 = gettime(b);
	if(t1 > t2) swap(t1, t2);
	printf("%d\n", t2-t1);
}