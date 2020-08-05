#include <bits/stdc++.h>
using namespace std;

double len[4];
vector <double> ans;

int main() {
	scanf("%lf %lf %lf", &len[1], &len[2], &len[3]);
	sort(len+1, len+4);
	if(len[1]+len[2] <= len[3]) return puts("wtnl"), 0;
	double a = (len[3]-len[2]+len[1])/2; ans.push_back(a);
	double b = len[1] - a; ans.push_back(b);
	double c = len[3] - a; ans.push_back(c);
	if(a <= 0 || b <= 0 || c <= 0) puts("No");
	else {
		puts("Yes");
		sort(ans.begin(), ans.end());
		for(int i = 0;i < ans.size(); i++) printf("%.2lf ", ans[i]);
	}
}