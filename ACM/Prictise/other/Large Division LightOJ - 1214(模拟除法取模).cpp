#include <bits/stdc++.h>
using namespace std;

int _, cas;
string a;
vector <int> dig;
bool ok;
long long b;

void dfs(int pos, long long yu) {
	if(pos == dig.size()) {
		if(yu == 0) ok = 1;
		else ok = 0;
//		printf("ok = %d\n", ok);
		return;
	}
	yu *= 10;
	yu += dig[pos];
	if(yu >= b) yu %= b;
	dfs(pos+1, yu);
}

int main() {
	scanf("%d", &_);
	while(_--) {
		dig.clear();
		cin >> a;
		scanf("%lld", &b); b = abs(b);
		for(char i: a) {
			if(i >= '0' && i <= '9')
				dig.push_back(i-'0');
		}
		dfs(0,0);
		printf("Case %d: %s\n", ++cas, ok?"divisible":"not divisible");
	}
}


// java大数写法
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int tt = input.nextInt();
		for(int o = 1; o <= tt; o++) {
			BigInteger zero = new BigInteger("0");
			BigInteger a = input.nextBigInteger();
			BigInteger b = input.nextBigInteger();
			if(a.compareTo(zero) < 0){
				a = zero.subtract(a);
			}
			if(b.compareTo(zero) < 0){
				b = zero.subtract(b);
			}
			BigInteger c = a.mod(b);
			String ans;
			if(c.equals(zero)) {
				ans = "divisible";
			}
			else {
				ans = "not divisible";
			}
			System.out.println("Case "+ o + ": " + ans);
		}
	}
}