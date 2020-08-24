#include <bits/stdc++.h>
using namespace std;

int _, x, y, z;
vector <int> v;
int main() {
	scanf("%d", &_);
	while(_--) {
		int a, b, c;
		scanf("%d %d %d", &x, &y, &z);
		v.clear();
		v.push_back(x);v.push_back(y);v.push_back(z);
		sort(v.begin(), v.end());
		if(v[1] != v[2]) puts("NO");
		else {
			puts("YES");
			if(x == y) a = v[2], b = v[0], c = v[0];
			else if(y == z) c = v[2], a = v[0], b = v[0];
			else if(x == z) b = v[2], a = v[0], c = v[0];
			printf("%d %d %d\n", a, b, c);
		}	
	}
}