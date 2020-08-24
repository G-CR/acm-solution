#include <bits/stdc++.h>
using namespace std;

int _, n;
long long a, b;
deque <int> q;
stack <int> sta;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %lld %lld", &n, &a, &b);
		if(a+b-1 <= n && n <= a*b) puts("YES");
		else {puts("NO"); continue;}
		
		int sheng = 0, pos = n;
		bool ok = 0;
		while(pos > 0) {
			sheng++;
			for(;pos >= 1; pos--) {
//				printf("pos = %d\n", pos);
				sta.push(pos);
				if(sta.size()==b || sheng+pos-1==a) break;
			} pos--;
//			puts("");
//			printf("sheng = %d pos = %d\n", sheng, pos);
			if(sheng+pos == a) ok = 1;
			
			
			while(!sta.empty()) {
				int t = sta.top(); sta.pop();
				q.push_front(t);
			}
			
			if(ok) {
				for(;pos >= 1; pos--) q.push_front(pos);
			}
		}
		for(int i = 1;i <= n; i++) {
			printf("%d%c", q.front(), i==n?'\n':' ');
			q.pop_front();
		}
	}
}