#include<stdio.h>
#include<math.h>
using namespace std;

int T,num,ans;
char a[5];

int main() {
	scanf("%d", &T);
	for(int p = 1;p <= T; p++) {
		ans = 0;
		scanf("%s", a+1);
		for(int i = 1;i <= 4; i++) {
			for(char j = '0';j <= '9'; j++) {
				if(i == 1 && j == '0') continue;
				if(j == a[i]) continue;
				char t = a[i];
				a[i] = j;
				num = (a[1]-'0')*1000+(a[2]-'0')*100+(a[3]-'0')*10+(a[4]-'0');
				a[i] = t;
				if(sqrt(num) == floor(sqrt(num))){
					ans++;
				} 
			}
		}
		printf("Case %d: %d\n", p, ans);
	}
}