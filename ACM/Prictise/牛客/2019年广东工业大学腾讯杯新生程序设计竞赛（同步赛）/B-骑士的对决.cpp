#include <bits/stdc++.h>
using namespace std;

char a[3],b;

int main() {
	scanf(" %c %c", &a[1], &a[2]);
	scanf(" %c", &b);
	if(b == 'S') {
		if(a[1] != 'S' && a[2] != 'S') puts("pmznb");
		else if((a[1] == 'S' || a[2] == 'S') && (a[1] == 'B' || a[2] == 'B')) puts("pmznb");
		else puts("lyrnb");
	}
	else if(b == 'J') {
		if(a[1] != 'J' && a[2] != 'J') puts("pmznb");
		else if((a[1] == 'J' || a[2] == 'J') && (a[1] == 'S' || a[2] == 'S')) puts("pmznb");
		else puts("lyrnb");
	}
	else {
		if(a[1] != 'B' && a[2] != 'B') puts("pmznb");
		else if((a[1] == 'B' || a[2] == 'B') && (a[1] == 'J' || a[2] == 'J')) puts("pmznb");
		else puts("lyrnb");
	}
}