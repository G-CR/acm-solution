#include <bits/stdc++.h>
using namespace std;

long long trans(string s,int radix) {
	long long res = 0;
	for(int i = 0;i < s.length(); i++) {
		char t = s[i];
		if(t >= '0' && t <= '9') {
			if(t - '0' >= radix) return -1;
			res = res * radix + 1ll * (t-'0');
		}
		else {
			if(1ll * (t - 'A' + 10) >= radix) return -1;
			res = res * radix + 1ll * (t - 'A' + 10);
		}
	}
	return res;
}

int getjz(string s) {
	int num = 2;
	for(int i = 0;i < s.length(); i++) {
		if(s[i] >= '0' && s[i] <= '9') num = max(num, s[i]-'0'+1);
		if(s[i] == 'A') num = max(num, 11);
		if(s[i] == 'B') num = max(num, 12);
		if(s[i] == 'C') num = max(num, 13);
		if(s[i] == 'D') num = max(num, 14);
		if(s[i] == 'E') num = max(num, 15);
		if(s[i] == 'F') num = max(num, 16);
	}
	return num;
}

int main() {
	string s;
	char fh;
	while(cin >> s) {
		int n = s.length(), pos = 0;
		string a = "", b = "", c = "";
		for(; pos < n; pos++) {
			if(s[pos]=='+'||s[pos]=='-'||s[pos]=='*'||s[pos]=='/') break;
			a += s[pos];
		} fh = s[pos++];
		for(;pos < n; pos++) {
			if(s[pos]=='=') break;
			b += s[pos];
		} pos++;
		for(;pos < n; pos++) {
			c += s[pos];
		}
//		cout << a << " " << b << " " << c << endl;
		
		bool ok = 0;
		int i = 2;
		i = max(i, getjz(a));
		i = max(i, getjz(b));
		i = max(i, getjz(c));
		for(;i <= 16; i++) {
			long long ta = trans(a, i);
			long long tb = trans(b, i);
			long long tc = trans(c, i);	
//			printf("jz = %d dig = %lld %lld %lld\n", i, ta, tb, tc);
			if((fh=='/' && tc*tb==ta) || (fh=='+'&&ta+tb==tc) || (fh=='-'&&ta-tb==tc) || (fh=='*'&&ta*tb==tc)) {
				printf("%d\n", i);
				ok = 1;
				break;
			} 
		}
		if(!ok) puts("-1");
	}
}