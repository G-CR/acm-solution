#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

struct node {
	string name;
	int h;
	bool operator < (const node &b) const {
		return h > b.h;
	}
} m[N];

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> m[i].name >> m[i].h;
	}
	sort(m, m+n);
	cout << m[1].name << endl;
}