## Kadj Squares [POJ - 3347](https://vjudge.net/problem/POJ-3347/origin)

题意：给n个正方形的面积，每一个正方形以图中的方式放在坐标轴上，遵循使得其坐标最小的原则摆放。问从y轴正方向向负方向看有多少个正方形可以被看到。

![题图](https://vj.z180.cn/628f7472da2cc4b643149a7d2695ae0c?v=1603623995)

思路：首先要确定每一个矩形的位置，对于当前矩形，可以枚举它前面的所有矩形，它的位置一定是它可以在的位置的最后一个位置，所以不断取max，然后怎么算呢，当前矩形跟它的相邻矩形有一个关系，$r[j] - abs( h[i] - h[j])$ ,r是相邻矩阵的右端点，h是高。确定完位置后就是看能否看得到它。如果当前矩阵是从上方是看不到的，那么它的左右端点都是在相邻矩阵的掩盖之下的，所以我们把可疑的矩形都变一下形，如果当前矩形的左端点比相邻矩形的右端点要左，那么就是可以的矩形了，右边当然也同理，我们就把这个可疑矩阵的左端点等于相邻矩形的右端点，那么如果它是不可能被看到的矩形的话不出意外它的左端点肯定比右端点还要右，如果是无辜矩形的话就没什么影响，应用这个特性就可以把矩形筛选出来了。然后就是把变长乘以 $\sqrt{2}$ 倍，这样输入的原面积就可以直接等于h了，直接进行整形运算，避免误差。

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n, h[55], l[55], r[55];
vector <int> ans;

int main() {
	while(~scanf("%d", &n) && n) {
		ans.clear();
		for(int i = 0;i <= n; i++) {
			h[i] = l[i] = r[i] = 0;
		}
		for(int i = 1;i <= n; i++) {
			scanf("%d", &h[i]);
		}
		
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= i-1; j++) {
				l[i] = max(l[i], r[j]-abs(h[i]-h[j]));
			}
			r[i] = l[i]+2*h[i];
		}
		
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= i-1; j++) {
				if(h[i] < h[j] && l[i] < r[j]) {
					l[i] = r[j];
				}
				else if(h[i] > h[j] && l[i] < r[j]) {
					r[j] = l[i];
				}
			}
		}
		
		for(int i = 1;i <= n; i++) if(l[i] < r[i]) ans.push_back(i);
		for(int i = 0;i < ans.size(); i++) {
			printf("%d%c", ans[i], i==ans.size()-1?'\n':' ');
		}
	}
}
```

