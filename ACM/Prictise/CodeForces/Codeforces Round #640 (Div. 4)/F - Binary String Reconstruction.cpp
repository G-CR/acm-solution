#include <bits/stdc++.h>
using namespace std;

int n0, n1, n2, _;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d %d", &n0, &n1, &n2);
		if(n0==0&&n1==0) {
			for(int i = 1;i <= n2+1; i++) printf("1"); puts("");
			continue;
		}
		if(n1==0&&n2==0) {
			for(int i = 1;i <= n0+1; i++) printf("0"); puts("");
			continue;
		}
		
		string s = "";
		for(int i = 1;i <= n0+1; i++) s += '0';
		for(int i = 1;i <= n2; i++) s += '1';
		for(int i = 1;i <= n1; i++) s += i%2?'1':'0';
		
		
		
		cout << s << endl;
	}
}