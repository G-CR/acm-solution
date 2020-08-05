#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int s[107][107],n,c,a[100007];

int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c;j++){
			if(s[a[i]][j]%2==0&&a[i]!=j){
				s[a[i]][j]++;
			}
		}
		for(int j=1;j<=c;j++){
			if(s[j][a[i]]%2==1&&a[i]!=j){
				s[j][a[i]]++;
			}
		}
	}
	
	int ans=0;
	for(int i=1;i<=c;i++){
		for(int j=1;j<=c;j++){
			ans=max(ans,s[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}