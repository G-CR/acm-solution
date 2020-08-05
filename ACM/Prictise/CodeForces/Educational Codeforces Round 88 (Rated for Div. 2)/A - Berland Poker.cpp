#include <bits/stdc++.h>
using namespace std;

int _, n, m, k;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d %d", &n, &m, &k);
		int pai = n/k; 
		int Max = min(pai, m); //cout << "Max = " << Max << endl;
		int sheng = max(m - Max, 0); //cout << "sheng = " << sheng << endl;
		int Min = (int)ceil((double)sheng/(double)(k-1)); //cout << "Min = " << Min << endl;
		printf("%d\n", sheng==0?Max:Max-Min);
	}
}