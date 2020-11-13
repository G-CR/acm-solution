//https://ac.nowcoder.com/acm/contest/7697#question
#include <bits/stdc++.h>
using namespace std;

int n, ak, hp;
int a[22], b[22], c[22];

int att(int pos, int xue) {
	int num1 = (b[pos]/ak) + (bool)(b[pos]%ak);
	int num2 = (xue/a[pos]) + (bool)(xue%a[pos]);
	if(num1 > num2) return -1;
	return xue-(num1-1)*a[pos];
}

int dfs(int pos, int xue, int level, int jingyan) {
	if(pos == n+1) return level;
	
	int shengyu = att(pos, xue);
	if(shengyu == -1) return dfs(pos+1, xue, level, jingyan);
	
	int buda = dfs(pos+1, xue, level, jingyan);
	
	int newjy = jingyan + c[pos];
	bool huixue = newjy >= 10;
	shengyu = huixue?hp:shengyu;
	int da = dfs(pos+1, shengyu, level+newjy/10, newjy%10);
//	if(da > buda) printf("%d 打\n",pos);
//	else printf("%d 不打\n", pos);
	return max(da, buda);
}

int main() {
	scanf("%d %d %d", &n, &ak, &hp);
	for(int i = 1;i <= n; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	}
	
	printf("%d\n", dfs(1, hp, 0, 0));
}