#include <bits/stdc++.h>
using namespace std;

int num[30];
int n, k;
string s;

int main() {
	scanf("%d %d", &n, &k);
	cin >> s;
	for(int i = 0;i < n; i++) {
		num[s[i]-'a']++;
	}
	char t = '`';
	int kan = 0;
	for(int i = 0;i < 26; i++) {
		if(kan + num[i] >= k) {
			kan = k-kan;
			t++;
			break;
		}
		else {
			kan += num[i];
			t++;
		}
	}
	
	for(int i = 0;i < n; i++) {
		if(s[i] > t) {
			printf("%c", s[i]);
		}
		if(s[i] == t) {
			if(kan) kan--;
			else printf("%c", s[i]);
		}
	}
	puts("");
}

/*
#include <bits/stdc++.h>
using namespace std;

vector <int> vc[30];
int n, k;
string s;
bool vis[400005];

int main() {
	scanf("%d %d", &n, &k);
	cin >> s;
	for(int i = 0;i < n; i++) {
		vc[s[i]-'a'].push_back(i);
	}
	
	for(int i = 0;i < 26; i++) {
		while(!vc[i].empty() && k) {
			vis[vc[i][0]] = 1;
			vector<int>::iterator it = vc[i].begin();
			vc[i].erase(it);
			k--;
		}
		if(!k) break;
	}
	for(int i = 0;i < n; i++) {
		if(!vis[i]) printf("%c", s[i]);
	}
	puts("");
}
*/