#include <bits/stdc++.h>
using namespace std;

long long prep[3][3][3], color[4];
long long a, b, c;

int main() {
	prep[0][0][0] = 0; prep[0][0][1] = 0; prep[0][0][2] = 1;
	prep[0][1][1] = 1; prep[0][1][2] = 3; prep[0][2][2] = 6;
	prep[1][1][1] = 3; prep[1][1][2] = 6; prep[1][2][2] = 10;
	prep[2][2][2] = 15;
	
	while(~scanf("%lld %lld %lld", &color[1], &color[2], &color[3])) {
		long long sum = 0;
		for(int i = 1;i <= 3; i++) {
			long long t = color[i]>2?2:color[i];
			sum += (color[i]-t); color[i] = t;
		}
		sort(color+1, color+4);
//		cout << color[1] << " " << color[2] << " " << color[3] << endl;
		long long k = color[1]+color[2]+color[3];
		printf("%lld\n", sum*k+prep[color[1]][color[2]][color[3]]);
	}
}