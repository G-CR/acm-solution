#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main() {
	cin >> s1 >> s2;
	if(s1 == "elephant") {
		if(s2 == "mouse") puts("tiangou txdy");
		else puts("tiangou yiwusuoyou");
	}
	else if(s1 == "tiger") {
		if(s2 == "elephant") puts("tiangou txdy");
		else puts("tiangou yiwusuoyou");
	}
	else if(s1 == "cat") {
		if(s2 == "tiger") puts("tiangou txdy");
		else puts("tiangou yiwusuoyou");
	}
	else if(s1 == "mouse") {
		if(s2 == "cat") puts("tiangou txdy");
		else puts("tiangou yiwusuoyou");
	}
}