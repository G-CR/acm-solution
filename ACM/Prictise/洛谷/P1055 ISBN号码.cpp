#include <bits/stdc++.h>
using namespace std;

char s[15];

int cal() {
	return ((s[0]-'0')*1 + (s[2]-'0')*2 + (s[3]-'0')*3 + (s[4]-'0')*4 + (s[6]-'0')*5 + (s[7]-'0')*6 + (s[8]-'0')*7 + (s[9]-'0')*8 + (s[10]-'0')*9) % 11;
}

int main() {
	scanf("%s", s);
	int ans = cal();
	char t;
	if(ans < 10) t = ans+'0';
	else t = 'X';
	
	if(s[12] == t) puts("Right");
	else {
		for(int i = 0;i < 12; i++) printf("%c", s[i]);
		printf("%c\n", t);
	}	
}