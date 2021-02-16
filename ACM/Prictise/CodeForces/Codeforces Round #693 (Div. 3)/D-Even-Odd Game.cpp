#include <bits/stdc++.h>
using namespace std;

int _, n;
long long x;

bool cmp(long long a, long long b) {
	return a > b;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		vector <long long> ji, ou;
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &x);
			if(x%2) ji.push_back(x);
			else ou.push_back(x);
		}
		sort(ji.begin(), ji.end(), cmp);
		sort(ou.begin(), ou.end(), cmp);
		
		long long ansj = 0, anso = 0;
		bool t = 1;
		int pos1 = 0, pos2 = 0;
		
		while(1) {
			if(pos1 >= ou.size() && pos2 >= ji.size()) break;
			if(pos1 >= ou.size()) {
				if(t) pos2++;
				else ansj += ji[pos2++];
				t = !t;
			}
			else if(pos2 >= ji.size()) {
				if(t) anso += ou[pos1++];
				else pos1++;
				t = !t;
			}
			else {
				if(t) {
					if(ou[pos1] >= ji[pos2]) {
						anso += ou[pos1];
						pos1++;
					}
					else pos2++;
					t = !t;
				}
				else {
					if(ji[pos2] >= ou[pos1]) {
						ansj += ji[pos2];
						pos2++;
					}
					else pos1++;
					t = !t;
				}
			}
		}
		
		if(anso > ansj) puts("Alice");
		else if(anso < ansj) puts("Bob");
		else puts("Tie");
	}
}