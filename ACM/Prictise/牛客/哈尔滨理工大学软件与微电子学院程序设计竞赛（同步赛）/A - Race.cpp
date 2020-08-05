#include <bits/stdc++.h>
using namespace std;
 
int v1, v2, t, s, l;
 
int main() {
	scanf("%d %d %d %d %d", &v1, &v2, &t, &s, &l);
	int now1 = 0, now2 = 0, pau = 0, cnt = 0;
	while(now1 < l && now2 < l) {
		now2 += v2;
		if(pau > 0) pau--;
		else {
			now1 += v1;
		}
		if(now1 - now2 >= t && pau == 0){
			pau = s;
		}
		cnt++;
	}
	if(now1 == l && now2 == l) printf("Tie ");
	else if(now1 == l) printf("Ming ");
	else printf("Hong ");
	printf("%d\n", cnt);
}