#include<iostream>
using namespace std;
long long l ,t,a,b,n,m,gcr;

int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
		if(a>b){
			gcr=min(n,a-b);
			n-=gcr;
			a-=gcr;
		}
		else{
			gcr=min(n,b-a);
			n-=gcr;
			b-=gcr;
		}
		if(a==0||b==0){
			if(m>0){
				printf("No\n");
			}
			else{
				if(a+b>=n){
					printf("Yes\n");
				}
				else{
					printf("No\n");
				}
			}
		}
		else{
			gcr=min(n,m);
			if(a>=gcr&&b>=gcr){
				a-=gcr;
				b-=gcr;
				n-=gcr;
				m-=gcr;
			}
			else{
				printf("No\n");
				continue;
			}
			
			if(n>0){
				if(a+b>=n){
					printf("Yes\n");
				}
				else{
					printf("No\n");
				}
			}
			else{
				if(a>=m&&b>=m){
					printf("Yes\n");
				}
				else{
					printf("No\n");
				}
			}
			
		}
	}
}