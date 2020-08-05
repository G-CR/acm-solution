#include <bits/stdc++.h>
using namespace std;

string s = "";
int n, ans;

int main() {
	scanf("%d", &n);
	if(n > 30 || n < 10) return puts("0"), 0;
	for(int a = 1;a <= 3; a++) 
		for(int b = 1;b <= 3; b++)
			for(int c = 1;c <= 3; c++)
				for(int d = 1;d <= 3; d++)
					for(int e = 1;e <= 3; e++)
						for(int f = 1;f <= 3; f++)
							for(int g = 1;g <= 3; g++)
								for(int h = 1;h <= 3; h++)
									for(int i = 1;i <= 3; i++)
										for(int j = 1;j <= 3; j++) {
											if(a+b+c+d+e+f+g+h+i+j == n) {
												s += a+'0'; s += b+'0'; s += c+'0'; 
												s += d+'0'; s += e+'0'; s += f+'0'; 
												s += g+'0'; s += h+'0'; s += i+'0'; 
												s += j+'0'; s += " "; ans++;
											}
										}
	printf("%d\n", ans);
	for(int i = 0;i < s.length(); i++) {
		printf("%c ", s[i]);
		if(s[i] == ' ') puts("");
	}
}