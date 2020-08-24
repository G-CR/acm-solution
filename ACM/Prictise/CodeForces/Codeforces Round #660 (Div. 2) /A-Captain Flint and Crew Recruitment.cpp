#include<bits/stdc++.h>
using namespace std;

int _,n;
int main(){
	scanf("%d", &_);
	while(_--){
		scanf("%d",&n);
		if(n>30) {
			puts("YES");
			int t = n-30;
			if(t != 6 && t!=10 && t!=14) {
				printf("%d %d %d %d\n",6,10,14,t);
			}
			else {
				printf("%d %d %d %d\n",6,10,15,n-31);
			}
		}
		else{
			puts("NO");
		}
	}
}