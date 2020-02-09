题目链接: [Heron and His Triangle](https://vjudge.net/problem/HDU-6222#author=solidhtwoo)

**题意**：给定一个数n，要求一个数 t >= n，满足 t-1、t+1 、 t 组成的三角形面积是整数，并且使 t 最小。 多组输入 T (1 ≤ T ≤ 30000)  ，N (1 ≤ N ≤ $10^{30}$). 

**想法**：题目的范围给的很明确了，O(N) 都过不了，那么这个题肯定是会出现规律的，写个打表程序找下规律，在打表之前需要知道一个知识点，就是已知三条边长，如何求面积，我用的是 海伦-秦九韶公式 ：

已知三边a, b, c；

周长的一半 $l = \frac{1}{2}(a+b+c)$；

 三角形面积 s = $\sqrt{l(l-a)(l-b)(l-c)}$；

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int num = 0;
	for(double i = 4;i <= 10000; i++) {
		double c = 0.5*((i-1)+i+(i+1));
		double t1;
		long long t2;
		t1 = sqrt(c*(c-(i-1)) * (c-i) * (c-(i+1)));
		t2 = t1;
		if((double)t2 == t1) 
			printf("a: %.0lf b: %.0lf c: %.0lf s: %lld\n",i-1, i, i+1, t2);
	}
}
```



输出的i ：

```
4 14 52 194 724 2702
```

稍作推敲，不难发现从第三项开始 t<sub>i</sub> = t<sub>i-1</sub> $* 4$ - t<sub>i-2</sub>. 因为 n 的大小可能会让答案爆 long long 所以这里会用大数做。

代码如下：

```java
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String []args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		for(int i = 0;i < t; i++) {
			BigInteger a = input.nextBigInteger();
			BigInteger p = new BigInteger("2");
			BigInteger q = new BigInteger("4");
			BigInteger m = new BigInteger("4");
			BigInteger now = q;
			while(now.compareTo(a) < 0) {
				now = m.multiply(q).subtract(p);
				p = q;
				q = now;
			}
			System.out.println(now);
		}
	}
}
```

