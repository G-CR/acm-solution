#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef map<int, int>::iterator iter;

struct Point {
	int x, y;
	Point(){}
	Point (int _x, int _y) {
		x = _x; y = _y;
	}
	ll operator ^ (const Point &b) const {
		return 1ll * x * b.y - 1ll * y * b.x;
	}
	void input() {
		scanf("%d %d", &x, &y);
	}
};

struct dynamic_polygon {
	map <int, int> top, down;
	void insert_top(Point p) {
		if (check_top(p))
			return;
		int x = p.x, y = p.y;
		top[x] = y;
		iter it = top.find(x);
		iter jt = it;
		if (it != top.begin()) {
			--jt;
			while (remove_top(jt++))
				--jt;
		}
		if (++jt != top.end())
			while (remove_top(jt--))
			++jt;
	}
	
	void insert_down(Point p) {
		if (check_down(p))
			return;
		int x = p.x, y = p.y;
		down[x] = y;
		iter it = down.find(x);
		iter jt = it;
		
		if (it != down.begin()) {
			--jt;
			while (remove_down(jt++))
				--jt;
		}
		if (++jt != down.end())
			while (remove_down(jt--))
			++jt;
	}
	bool remove_top(iter it) {
		if (it == top.begin())
			return false;
		iter jt = it, kt = it;
		--jt;
		++kt;
		if (kt == top.end())
			return false;
		
		Point p1 (it->first - jt->first, it->second - jt->second);
		Point p2 (kt->first - jt->first, kt->second - jt->second);
		if((p1 ^ p2) >= 0) {
			top.erase(it);
			return true;
		}
		return false;
	}
	bool remove_down(iter it) {
		if (it == down.begin())
			return false;
		iter jt = it, kt = it;
		--jt;
		++kt;
		if (kt == down.end())
			return false;
		
		Point p1 = Point(it->first - jt->first, it->second - jt->second);
		Point p2 = Point(kt->first - jt->first, kt->second - jt->second);
		if ((p1 ^ p2) <= 0) {
			down.erase(it);
			return true;
		}
		return false;
	}
	
	bool check_top(Point p) {
		int x = p.x, y = p.y;
		iter it = top.lower_bound(x);
		if (it == top.end())
			return false;
		if (it->first == x)
			return y <= it->second;
		if (it == top.begin())
			return false;
		iter jt = it;
		--jt;
		Point p1 (it->first - jt->first, it->second - jt->second);
		Point p2 (x - jt->first, y - jt->second);
		return (p1 ^ p2) <= 0;
	};
	
	bool check_down(Point p) {
		int x = p.x, y = p.y;
		iter it = down.lower_bound(x);
		if (it == down.end())
			return false;
		if (it->first == x)
			return y >= it->second;
		if (it == down.begin())
			return false;
		iter jt = it;
		--jt;
		Point p1 (it->first - jt->first, it->second - jt->second);
		Point p2 (x - jt->first, y - jt->second);
		return (p1 ^ p2) >= 0;
	}
	
	void insert(Point p) { // 插入点p到凸包内
		insert_top(p);
		insert_down(p);
	}
	
	bool check(Point p) { // 检查点p是否在凸包内
		if(check_top(p) && check_down(p)) return 1;
		else return 0;
	}
};

dynamic_polygon poly;

int main() {
	int _; scanf("%d", &_);
	while(_--) {
		int op; scanf("%d", &op);
		Point p; p.input();
		if(op == 1) poly.insert(p);
		else puts(poly.check(p) ? "YES" : "NO");
	}
}