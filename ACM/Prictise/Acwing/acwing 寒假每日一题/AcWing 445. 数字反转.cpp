#include <bits/stdc++.h>
using namespace std;

int n;
bool z;

int main() {
    scanf("%d", &n);
    if(n >= 0) z = 1;
    n = abs(n);
    string s = "";
    while(n) {
        s += n % 10 + '0';
        n /= 10;
    }

    int pos = s.length()-1;
    for(int i = 0;i < s.length(); i++) {
        if(s[i] != '0') {
            pos = i;
            break;
        }
    }

    if(!z) printf("-");
    for(int i = pos;i < s.length(); i++) {
        printf("%c", s[i]);
    }
    puts("");
}