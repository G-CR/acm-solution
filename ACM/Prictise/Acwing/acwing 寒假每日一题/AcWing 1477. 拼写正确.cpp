#include <bits/stdc++.h>
using namespace std;

map <int, string> mp;
string s;
long long ans;

void init() {
    mp[0] = "zero";
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";
    mp[4] = "four";
    mp[5] = "five";
    mp[6] = "six";
    mp[7] = "seven";
    mp[8] = "eight";
    mp[9] = "nine";
}

int main() {
    init();
    cin >> s;
    for(int i = 0;i < s.length(); i++) {
        ans += s[i]-'0';
    }
    s = "";
    while(ans) {
        s += ans % 10 + '0';
        ans /= 10;
    }
    if(s.size() == 0) s = "0";
    reverse(s.begin(), s.end());
    for(int i = 0;i < s.length(); i++) {
//      printf("%c", s[i]);
        cout << mp[s[i]-'0'] << " ";
    }
}
