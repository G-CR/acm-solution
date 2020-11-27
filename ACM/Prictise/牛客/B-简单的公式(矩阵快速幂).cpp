#include <bits/stdc++.h>
using namespace std;

int num;
const long long mod = 1000000007;
struct Mat {
	long long m[101][101];
};//存储结构体

Mat a,e; //a是输入的矩阵，e是输出的矩阵
Mat Mul(Mat x,Mat y) {
	Mat c;
	for(int i=1;i<=num;++i) {
		for(int j=1;j<=num;++j) {
			c.m[i][j] = 0;
		}
	}
	for(int i=1;i<=num;++i) {
		for(int j=1;j<=num;++j){
			for(int k=1;k<=num;++k){
				c.m[i][j] = c.m[i][j]%mod + x.m[i][k]*y.m[k][j]%mod;
			}
		}
	}
	return c;
}

Mat pow(Mat x,long long y) { //矩阵快速幂
	Mat ans = e;
	while(y) {
		if(y&1) ans = Mul(ans,x);
		x = Mul(x,x);
		y>>=1;
	}
	return ans;
}

int main() {
	long long n;
	cin >> n;
	if(n == 1) {
		cout << 14;
	}
	if(n == 2) {
		cout << 35*6;
	}
	num = 2;
	a.m[1][1] = 2; a.m[1][2] = 1;
	a.m[2][1] = 3; a.m[2][2] = 0;
	e.m[1][1]=1; e.m[1][2]=0;
	e.m[2][1]=0; e.m[2][2]=1;
	e = pow(a, n-2);
	long long t1 = (6*e.m[1][1]%mod + 2*e.m[2][1]%mod)%mod;
	a.m[1][1] = 3; a.m[1][2] = 1;
	a.m[2][1] = 10; a.m[2][2] = 0;
	e.m[1][1]=1; e.m[1][2]=0;
	e.m[2][1]=0; e.m[2][2]=1;
	e = pow(a, n-2);
	long long t2 = (35*e.m[1][1]%mod + 7*e.m[2][1]%mod)%mod;
	cout << (t1 * t2)%mod << endl;
}



