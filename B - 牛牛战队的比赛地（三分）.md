[题目链接](https://ac.nowcoder.com/acm/contest/3006/B)

题意：一个二维平面上有若干个点，现在需要在X轴上面找到一个点，距离这若干点中最远的点的距离最小，并输出距离。

思路：在一条线上面找，这种题目属于最值存在于中间某个地方的情况，不具有单调性。所以二分不可做。这时候就可以尝试使用三分，可以解决答案呈抛物线状的题，这个题目需要求最小值，那么这个抛物线就是 **a > 0** 的。

三分的做法： 先取一段长度，为最左端和最右端的长度三等分，然后取两个中间点恰好将一大段分为三小段，再根据题目的要求将一大段范围缩小成两小段，根据题目需要的的精度设置好循环就OK了。

```cpp
#include <bits/stdc++.h>
using namespace std;
const double ps = 1e-6;
int n;
double x[100005], y[100005];

double dist(double pos) {
	double res = -1;
	for(int i = 1;i <= n; i++) {
		res = max(res, sqrt((x[i]-pos)*(x[i]-pos) + y[i]*y[i]));
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) scanf("%lf %lf", &x[i], &y[i]);
	double head = -10000, tail = 10000;
	while(head+ps < tail) {
		double len = (tail-head)/3;
		double lmid = head+len;
		double rmid = tail-len;
		if(dist(lmid) > dist(rmid)) head = lmid;
		else tail = rmid;
	}
	printf("%lf\n", dist(tail));
}
```

