#include <bits/stdc++.h>
using namespace std;

struct Node {
	string name;
	double grade[6];
	double sum;
}node[200005];
double Max[6];
int n;

double getsum(Node a) {
	double sum1 = (a.grade[1]*600/Max[1])*0.25;
	double sum2 = (a.grade[2]*300/Max[2]+a.grade[3]*300/Max[3])*0.25;
	double sum3 = (a.grade[4]*300/Max[4]+a.grade[5]*300/Max[5])*0.5;
	return sum1+sum2+sum3;
}

bool cmp(Node a, Node b) {
	if(fabs(a.sum-b.sum) <= 1e-5) {
		return a.name < b.name;
	}
	return a.sum > b.sum;
}

int main() {
	while(~scanf("%d", &n)) {
		memset(Max, 0, sizeof Max);
		
		for(int i = 1;i <= n; i++) {
			cin >> node[i].name;
			for(int j = 1;j <= 5; j++) {
				scanf("%lf", &node[i].grade[j]);
				Max[j] = max(Max[j], node[i].grade[j]);
			} 
		}
		
		for(int i = 1;i <= n; i++) {
			node[i].sum = getsum(node[i]);
		}
		sort(node+1, node+1+n, cmp);
		
		for(int i = 1;i <= n; i++) {
			cout << node[i].name << " ";
			printf("%.5lf\n", node[i].sum);
		}
	}
}