#include <bits/stdc++.h>
using namespace std;

int _, n, m;
string s;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		if(n > m) swap(n, m);
		cin >> s;
		int head = 0, tail = m;
		int cnt = s.length()/m;
		while(cnt--) {
//			cout << "cnt = " << cnt << endl;
			for(int i = head;i < tail; i++) printf("%c", s[i]); 
			puts("");
			head = tail; tail = head + m;
		}
	}
}