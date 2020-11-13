#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod[2]={1000000007,998244353};
ll base[2]={43,47};
ll has[3][1000007],po[2][1000007];

string s;
int m, len;
pair <ll, ll> ha;
map <pair<ll, ll>, int> mp;

void init(){
	po[0][0]=1,po[1][0]=1;
	for(int i=1;i<1000001;i++){
		po[0][i]=(po[0][i-1]*base[0])%mod[0];
		po[1][i]=(po[1][i-1]*base[1])%mod[1];
	}
}
void gethash(string s){
	int len=s.length(),x;
	for(int i=0;i<len;i++){
		x=s[i];
		has[0][i+1]=(has[0][i]*base[0]%mod[0]+x)%mod[0];
		has[1][i+1]=(has[1][i]*base[1]%mod[1]+x)%mod[1];
	}
}

ll getv(int l,int r,int k){
	return (has[k][r]-has[k][l-1]*po[k][r-l+1]%mod[k]+mod[k])%mod[k];
}

int main() {
	init();
	while(~scanf("%d %d", &m, &len)) {
		int ans = 0;
		cin >> s;
		gethash(s);
		
		map <pair<ll, ll>, int> mp;
		pair<ll, ll> ha;
		for(int i = 1;i <= len; i++) {
			mp.clear();
			int l = i, r = i+m-1;
			while(r <= s.length()) {
				ha.first = getv(l, r, 0);
				ha.second = getv(l, r, 1);
				mp[ha]++;
				if(l > m*len) {
					ha.first = getv(l-m*len, r-m*len, 0);
					ha.second = getv(l-m*len, r-m*len, 1);
					mp[ha]--;
					if(mp[ha] == 0) mp.erase(ha);
				}
				
				if(mp.size() == m) ans++;				
				l += len;
				r += len;
			}
		}
		
		printf("%d\n", ans);
	}
}