#include <bits/stdc++.h>
using namespace std;

int tot[20004];
int n, m, x;
set<int> st;

int main() {
	while(~scanf("%d %d", &n, &m)) {
		st.clear();
		for(int i = 1;i <= n+m; i++) {
			scanf("%d", &tot[i]);
		}
		sort(tot+1, tot+1+n+m);
		for(int i = 1;i <= n+m; i++) {
			st.insert(tot[i]);
		}
		set<int>::iterator it;
		it = st.begin();
		while(it != st.end()) {
			it++;
			if(it == st.end()) it--,printf("%d\n", *it);
			else it--, printf("%d ", *it);
			it++;
		}
	}
}



#include <bits/stdc++.h>
using namespace std;

int tot[20004];
int n, m, x;

int main() {
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 1;i <= n+m; i++) {
			scanf("%d", &tot[i]);
		}
		tot[0] = 0;
		sort(tot+1, tot+1+n+m);
		printf("%d", tot[1]);
		for(int i = 2;i <= n+m; i++) {
			if(tot[i] != tot[i-1]) {
				printf(" %d", tot[i]);
			}
		}
		puts("");
	}
}