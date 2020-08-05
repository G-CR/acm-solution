#include <bits/stdc++.h>
using namespace std;

int t;
char s[300005];
queue<int> qo,qj;
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%s", s+1);
		int n = strlen(s+1);
		for(int i = 1;i <= n; i++) {
			if((s[i]-'0')%2) qj.push(s[i]-'0');
			else qo.push(s[i]-'0');
		}
		
		while(1) {
			if(qo.empty()) {
				while(!qj.empty()) {printf("%d", qj.front()); qj.pop();} break;
			}
			else if(qj.empty()) {
				while(!qo.empty()) {printf("%d", qo.front()); qo.pop();} break;
			}
			if(qo.front() < qj.front()) {printf("%d", qo.front()); qo.pop();} 
			else {printf("%d", qj.front()); qj.pop();} 
		}
		puts("");
	}
}