#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ok[100005];
ll N,vs,vb,vl;

int main() {
	scanf("%lld %lld %lld %lld", &N, &vs, &vb, &vl);
	int i = 1,j = 1,k = 1;
	ll sum = 0;
	if(!((N+1)%vs) && !((N+1)%vb) && !((N+1)%vl)) {
		int a[3];
		a[0] = vs; a[1] = vb; a[2] = vl; sort(a,a+3);
		if(a[1]%a[0] && a[2]%a[1]) return puts("3000000000"),0;
	}
	while(1) {
		if(i+vs > N) i = i+vs-N-1;
		else i += vs;
		if(ok[i] != 1 && ok[i] != 0) {
			sum++;
			break;
		}
		else {
			sum++;
			if(i != 1) ok[i] = 1;
		}
//		cout << "vi = " << i << endl;
		
		if(j+vb > N) j = j+vb-N-1;
		else j += vb;
		if(ok[j] != 2 && ok[j] != 0) {
			sum++;
			break;
		}
		else {
			sum++;
			if(j != 1) ok[j] = 2;
		}
//		cout << "vj = " << j << endl;
		
		if(k+vl > N) k = k+vl-N-1;
		else k += vl;
		if(ok[k] != 3 && ok[k] != 0) {
			sum++; 
			break;
		}
		else {
			sum++;
			if(k != 1) ok[k] = 3;
		}
//		cout << "vk = " << k << endl;
	}
	printf("%lld\n", sum);
}