[题目链接](http://acm.hdu.edu.cn/showproblem.php?pid=1018)

题意：求一个数的阶乘的位数

思路：位数 **len = log<sup>1</sup><sub>10</sub> +  log<sup>2</sup><sub>10</sub> + log<sup>3</sup><sub>10</sub> + .... + log<sup>n</sup><sub>10</sub> + 1**

```cpp
#include <bits/stdc++.h>
using namespace std;

int _, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		double ans = 0;
		for(int i = 1;i <= n; i++) {
			ans += log10(i);
		}
		printf("%d\n", (int)ans+1);
	}
}
```

