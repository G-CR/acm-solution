#include <bits/stdc++.h>
using namespace std;

int elec;

int main() {
	cin >> elec;
	if(elec <= 150) printf("%.1lf\n", 0.4463*elec);
	else if(elec <= 400) printf("%.1lf\n", 0.4463*150 + 0.4663*(elec-150));
	else printf("%.1lf\n", 0.4463*150 + 0.4663*(400-150) + 0.5663*(elec-400));
}