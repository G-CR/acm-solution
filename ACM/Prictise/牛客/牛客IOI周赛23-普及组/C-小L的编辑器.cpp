#include <bits/stdc++.h>
using namespace std;

string s, t;

struct node {
	char val;
	node *nxt, *pre;
};

int main() {
	cin >> s >> t;
	node *head;
	head = (struct node *)malloc(sizeof(struct node));
	head->val = s[0];
	head->nxt = NULL; head->pre = NULL;
	node* done = head;
	
	for(int i = 1;i < s.length(); i++) {
		node *now = (struct node *)malloc(sizeof(struct node));
		now->val = s[i];
		
		if(t[i-1] == 'L') {
			now->nxt = done;
			now->pre = done->pre;
			if(done->pre == NULL) head = now;
			else done->pre->nxt = now;
			done->pre = now;
		}
		else if(t[i-1] == 'R') {
			if(done->nxt == NULL) now->nxt = NULL;
			else {
				now->nxt = done->nxt;
				done->nxt->pre = now;
			}
			done->nxt = now;
			now->pre = done;
		}
		
		done = now;
	}
	
	node* i = head;
	while(1) {
		printf("%c", i->val);
		if(i->nxt == NULL) break;
		i = i->nxt;
	}
}