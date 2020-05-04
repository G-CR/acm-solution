## [A.QAQ](https://codeforces.com/contest/894/problem/A)

题意：求字符串中为“QAQ”的子序列个数

思路：由于n不大，暴力就找到A的位置，再暴力找这个A👈Q的个数，再暴力找这个A👉Q的个数，乘起来就是这个A所贡献的子序列的个数，一直找完所有的A就👌。

```cpp
#include <bits/stdc++.h>
using namespace std;

string t, s;

int Left(int pos) {
	int sum = 0;
	for(int i = 0;i < pos; i++) {
		if(s[i] == 'Q') sum++;
	}
	return sum;
}

int Right(int pos) {
	int sum = 0;
	for(int i = pos+1;i < s.length(); i++) {
		if(s[i] == 'Q') sum++;
	}
	return sum;
}

int main() {
	cin >> s;
	int ans = 0;
	for(int i = 0;i < s.length(); i++) {
		if(s[i] == 'A') {
			ans += Left(i)*Right(i);
		}
	}
	printf("%d\n", ans);
}
```



## [B.Ralph And His Magic Field](https://codeforces.com/contest/894/problem/B)

题意：一个n*m的格子，在格子里面填数字，然后让每一行每一列的乘积等于k，求可以有多少种填数字的方式。

思路：因为放进格子的数是整数，所以方案是有限的，这1e18的范围整的，O(n)都过不了，可以想一下，每个格子只能填-1或者1进去，那么每个格子就有两种可能；那么再想一想，真的每个格子都有两种可能吗，假如一行长长的格子，k=-1，前面都填完了，乘积为1，最后一个格子有权选填1吗，对吧，有些格子是没有资格有选择权的。就好比人生啊，不是谁生来都有那么多条路选择的（这tm就是边玩边写题解，写出来的都是些什么鬼）所以我们需要找到没有资格的格子，其实也好找，仔细想一想，前面的选完了，剩下的就没得选了，所以这个范围： __| 的都没得选 也就是前 n-1,m-1 有得选也就是n*m的格子有 2<sup>n-1 * m-1</sup>  种填法。

写完了，交，WA了，为啥呢，到底是为甚摸呢，再冥思苦想一波，当 **n和m的奇偶不一样** 并且 **k=-1** 的时候好像会打架诶，假如是2*3的格子，那么你自己试试吧，能行和列凑成k算你厉害，给你发点奖金，去配个好点的眼镜。特判一下就完了。

算幂的时候用快速幂，O(logn) 的时间，妥妥的。

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;

ll poww(ll a,ll b)
{
	a %= mod;
	ll ans = 1,base = a;
	while(b)
	{
		if(b&1)
			ans = ans*base%mod;
		base = base*base%mod;
		b >>= 1;
	}
	return ans;
}
ll n, m;
int k;

int main() {
	scanf("%lld %lld %d", &n, &m, &k);
	if(n%2!=m%2 && k==-1) puts("0");
	else {
		long long t1 = poww(2, n-1);
		long long t2 = poww(t1%mod, m-1);
		printf("%lld\n", (t2+mod)%mod);
	}
}
```

