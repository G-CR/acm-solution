#include <bits/stdc++.h>
using namespace std;

int n, m;
string ans, fin;
struct Node {
	string name;
	int num;
} boy[100005];

int cal(string s) {
	int num = 0;
	for(int i = 0;i < s.length(); i++) {
		if(s[i] == ans[i]) num++;
	}
	return num;
}

bool cmp(Node a, Node b) {
	if(a.num == b.num) return a.name < b.name;
	return a.num > b.num;
}

int main() {
	scanf("%d %d", &n, &m);
	cin >> ans;
	for(int i = 1;i <= m; i++) {
		cin >> boy[i].name;
		cin >> fin;
		boy[i].num = cal(fin);
	}
	sort(boy+1, boy+1+m, cmp);
	cout << boy[1].name << "\n";
	printf("%.2lf\n", 100.0*(double)boy[1].num/(double)n);
}