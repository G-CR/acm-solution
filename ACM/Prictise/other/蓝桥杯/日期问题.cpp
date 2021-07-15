#include <bits/stdc++.h>
using namespace std;

string s;
bool isrun(int y) {
	return (y%4==0&&y%100) || y%400==0;
}
int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int y, int m, int d) {
	if(m >= 1 && m <=12) {
		int num = a[m];
		if(m == 2 && isrun(y)) num++;
		if(d && d <= num) return 1;
		return 0;
	}
	else return 0;
}

bool check1(int y, int m, int d) {
	if(check(y, m, d)) return 1;
	return 0;
}

bool check2(int m, int d, int y) {
	if(check(y, m, d)) return 1;
	return 0;
}

bool check3(int d, int m, int y) {
	if(check(y, m, d)) return 1;
	return 0;
}

int fz(int i, int j) {
	int res = s[i] - '0';
	return res * 10 + (s[j] - '0');
}

struct node {
	int a, b, c;
};

bool cmp(node p, node q) {
	if(p.a == q.a) {
		if(p.b == q.b) {
			return p.c < q.c;
		}
		return p.b < q.b;
	}
	return p.a < q.a;
}
vector <node> ans;

int main() {
	cin >> s;
	int a = fz(0, 1), b = fz(3, 4), c = fz(6, 7);
	
	if(check1(a, b, c)) {
		ans.push_back({a>=60?1900+a:2000+a, b, c});
	}
	if(check2(a, b, c) && a != c) {
		ans.push_back({c>=60?1900+c:2000+c, a, b});
	}
	if(check3(a, b, c) && a != b) {
		ans.push_back({c>=60?1900+c:2000+c, b, a});
	}
	
	sort(ans.begin(), ans.end(), cmp);
	for(auto i : ans) {
		printf("%d-%.2d-%.2d\n", i.a, i.b, i.c);
	}
}