#include <iostream>
#include <cmath>
#include <map>
#include <cstring>
using namespace std;

const double h = 1000.0/1024.0;
map<string, int> mp;
int _;
string s;

void init() {
	mp["B]"] = 0; mp["KB"] = 1; mp["MB"] = 2;
	mp["GB"] = 3; mp["TB"] = 4; mp["PB"] = 5;
	mp["EB"] = 6; mp["ZB"] = 7; mp["YB"] = 8;
}

int main() {
	init();
	scanf("%d", &_);
	for(int p = 1;p <= _; p++) {
		cin >> s;
		string dw = "";
		int pos;
		
		for(int i = 0;i < s.length(); i++) {
			if(s[i] == '[') {
				pos = i+1;
				break;
			}
		}
		
		dw += s[pos]; dw += s[pos+1];
		printf("Case #%d: %.2lf", p, (1-pow(h,mp[dw]))*100); 
		puts("%");
	}
}