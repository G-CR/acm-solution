#include <bits/stdc++.h>
using namespace std;

map <string, int> user, res;
vector <pair <string, int> > record;
string name;
int score;
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		cin >> name >> score;
		user[name] += score;
		res[name] += score;
		record.push_back({name, score});
	}
	
	int ma = -1e9, tim = 0;
	for(auto i: user) {
		ma = max(ma, i.second);
	}
	
	user.clear(); string ans;
	for(auto i: record) {
		user[i.first] += i.second;
		if(user[i.first] >= ma && res[i.first] >= ma) {
			ans = i.first;
			break;
		}
	}
	
	cout << ans << endl;
}