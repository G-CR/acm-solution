#include <bits/stdc++.h>
using namespace std;

vector <int> odd, even;
int n, x;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &x);
		if(x&1) odd.push_back(x);
		else even.push_back(x);
	}
	
	int numodd = odd.size(), numeven = even.size();
	sort(odd.begin(), odd.end(), cmp);
	sort(even.begin(), even.end(), cmp);
	
	int staodd = 0, staeven = 0;
	if(numeven > numodd) staeven++;
	else if(numodd > numeven) staodd++;
	
	int sum = 0;
	if(numodd-staodd > numeven-staeven)  for(int i = staeven+staodd+numeven;i < numodd; i++) sum += odd[i];
	else if(numodd-staodd < numeven-staeven) for(int i = staodd+staeven+numodd;i < numeven; i++) sum += even[i];
	
	printf("%d\n",sum);
}