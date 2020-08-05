#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y;
}pos[5], dir[5];

int l[5];

bool cmp(node a, node b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool check() {
	struct node post[5];
	for(int i = 1;i <= 4; i++) {
		post[i].x = pos[i].x; 
		post[i].y = pos[i].y;
	}
	sort(post+1, post+5, cmp);
	
	dir[1].x = post[1].x - post[2].x;
	dir[1].y = post[1].y - post[2].y;
	
	dir[2].x = post[1].x - post[3].x;
	dir[2].y = post[1].y - post[3].y;
	
	dir[3].x = post[4].x - post[3].x;
	dir[3].y = post[4].y - post[3].y;
	
	dir[4].x = post[4].x - post[2].x;
	dir[4].y = post[4].y - post[2].y;
	
	
	if(dir[1].x*dir[2].x+dir[1].y*dir[2].y != 0) return 0;
	else if(dir[2].x*dir[3].x+dir[2].y*dir[3].y != 0) return 0;
	else if(dir[4].x*dir[3].x+dir[4].y*dir[3].y != 0) return 0;
	else if(dir[4].x*dir[1].x+dir[4].y*dir[1].y != 0) return 0;


	l[1] = (post[1].x-post[2].x)*(post[1].x-post[2].x) + (post[1].y-post[2].y)*(post[1].y-post[2].y);
	l[2] = (post[1].x-post[3].x)*(post[1].x-post[3].x) + (post[1].y-post[3].y)*(post[1].y-post[3].y);
	l[3] = (post[4].x-post[3].x)*(post[4].x-post[3].x) + (post[4].y-post[3].y)*(post[4].y-post[3].y);
	l[4] = (post[4].x-post[2].x)*(post[4].x-post[2].x) + (post[4].y-post[2].y)*(post[4].y-post[2].y);
	
	if(l[1] == l[2] && l[2] == l[3] && l[3] == l[4]) return 1;
	return 0;
}

int main() {
	for(int i = 1;i <= 4; i++) {
		scanf("%d %d", &pos[i].x, &pos[i].y);
	}
	
	if(check()) return puts("wen"), 0;
	
	else {
		for(int i = 1;i <= 4; i++) {
			for(int j = -1;j <= 1; j++) {
				if(j == 0) continue;
				int t = pos[i].x;
				pos[i].x += j;
				if(check()) return puts("hai xing"), 0;
				pos[i].x = t;
			}
			
			for(int j = -1;j <= 1; j++) {
				if(j == 0) continue;
				int t = pos[i].y;
				pos[i].y += j;
				if(check()) return puts("hai xing"), 0;
				pos[i].y = t;
			}
		}
	}
	puts("wo jue de bu xing");
}

// 法二

/*

#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y;
} pos[5];
set<int> st;

bool check() {
	st.clear();
	for(int i = 1;i <= 4; i++) {
		for(int j = i+1;j <= 4; j++) {
			int l = (pos[i].x-pos[j].x)*(pos[i].x-pos[j].x) + (pos[i].y-pos[j].y)*(pos[i].y-pos[j].y);
			st.insert(l);
		}
	}
	set<int> ::iterator it;
	it = st.end(); it--;
	
	if(st.size() == 2 && 2 * *st.begin() == *it)return 1;
	return 0;
}

int main() {
	for(int i = 1;i <= 4; i++) {
		scanf("%d %d", &pos[i].x, &pos[i].y);
	}
	if(check()) return puts("wen"), 0;
	
	for(int i = 1;i <= 4; i++) {
		for(int j = -1;j <= 1; j++) {
			if(j == 0) continue;
			int t = pos[i].x;
			pos[i].x += j;
			if(check()) return puts("hai xing"), 0;
			pos[i].x = t;
		}
		
		for(int j = -1;j <= 1; j++) {
			if(j == 0) continue;
			int t = pos[i].y;
			pos[i].y += j;
			if(check()) return puts("hai xing"), 0;
			pos[i].y = t;
		}
	}
	puts("wo jue de bu xing");
}

*/