#include<iostream>
using namespace std;

long long b, x;
int _;

int main(){
	scanf("%d", &_);
	while(_--){
		scanf("%lld %lld", &b, &x); b--;
		if(b%x==0) puts("T");
		else puts("F");
	}
}