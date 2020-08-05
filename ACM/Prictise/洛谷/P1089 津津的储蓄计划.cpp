#include <bits/stdc++.h>
using namespace std;

int give = 300, need, sheng = 0, cun = 0,ans = 0;

int main() {
	for(int i = 1;i <= 12; i++) {
		scanf("%d", &need);
		sheng = sheng + give - need;
		if(sheng < 0) return printf("-%d", i), 0;
		
		cun = (sheng/100)*100;
		ans += cun;
		sheng -= cun;
	}
	printf("%.0lf\n", (double)ans*1.2+(double)sheng);
}