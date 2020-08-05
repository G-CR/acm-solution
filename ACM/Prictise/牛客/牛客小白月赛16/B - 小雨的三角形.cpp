#include <iostream>
using namespace std;
const int mod = 1e9+7;
long long a[1005],ans;
int i,j,n,m,Sta,End;

int main()
{
	cin >> n >> m;
	a[1] = 1,j = 3;
	for(i = 2,j = 3;i <= n; i++,j =(j*2)%mod) a[i] = (a[i-1]+j);
	while(m--)
	{
		scanf("%d %d", &Sta, &End);
		for(i = Sta;i <= End; i++) ans += a[i];
		printf("%lld\n",ans % mod); ans = 0;
	}
}