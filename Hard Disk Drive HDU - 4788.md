[题目链接](http://acm.hdu.edu.cn/showproblem.php?pid=4788)

**题意**：操作系统读取空间的规则 与 生产厂家读取的规则 有所不同，操作系统在存储单位之间的换算是 1KB = 1024B （以此类推），生产厂家的换算规则是 1KB = 1000B，这样就会导致生产出来后操作系统读取的空间与厂家标注的有误差，现在给出一个存储量，要求这两者之间的误差。 

计算误差的方法： 首先将给出的单位换算成B 然后：

### （$1-\frac{生 产 厂 家 给 的 量}{操 作 系 统 读 出 的 量}$）%

**思路**：首先这题非常简单。首先把单位化小就是把数字按比例扩大，生产厂家的缩小一个单位就乘以1000，操作系统的缩小一个单位就乘以1024，之后把结果代入上面的公式就可以了，如果 long long 再多几个0这个题目就解出来了，but没有。其实再想一下那个分式，除出来的结果就是一个小于1的值，而且 上面✖️几个 1000，下面就要➗几个1024，那为什么不把这两个数捆绑起来当作一个常数，缩小一次单位就乘以一次（1000/1024）这样就OK了。 剩下就是读取单位了，方法很多种，我用的比较直观的map。

```cpp
#include <iostream>
#include <cmath>
#include <map>
#include <cstring>
using namespace std;

const double h = 1000.0/1024.0;
map<string, int> mp;
int _;
string s;

void init() {
	mp["B]"] = 0; mp["KB"] = 1; mp["MB"] = 2;
	mp["GB"] = 3; mp["TB"] = 4; mp["PB"] = 5;
	mp["EB"] = 6; mp["ZB"] = 7; mp["YB"] = 8;
}

int main() {
	init();
	scanf("%d", &_);
	for(int p = 1;p <= _; p++) {
		cin >> s;
		string dw = "";
		int pos;
		
		for(int i = 0;i < s.length(); i++) {
			if(s[i] == '[') {
				pos = i+1;
				break;
			}
		}
		
		dw += s[pos]; dw += s[pos+1];
		printf("Case #%d: %.2lf", p, (1-pow(h,mp[dw]))*100); 
		puts("%");
	}
}
```

