#include <bits/stdc++.h>
using namespace std;

map <string, bool> mp;
string s;
int _;

void init() {
	mp["algorithm"] = 1;
	mp["bitset"] = 1;
	mp["cctype"] = 1;
	mp["cerrno"] = 1;
	mp["clocale"] = 1;
	mp["cmath"] = 1;
	mp["complex"] = 1;
	mp["cstdio"] = 1;
	mp["cstdlib"] = 1;
	mp["cstring"] = 1;
	mp["ctime"] = 1;
	mp["deque"] = 1;
	mp["exception"] = 1;
	mp["fstream"] = 1;
	mp["functional"] = 1;
	mp["limits"] = 1;
	mp["list"] = 1;
	mp["map"] = 1;
	mp["iomanip"] = 1;
	mp["ios"] = 1;
	mp["iosfwd"] = 1;
	mp["iostream"] = 1;
	mp["istream"] = 1;
	mp["ostream"] = 1;
	mp["queue"] = 1;
	mp["set"] = 1;
	mp["sstream"] = 1;
	mp["stack"] = 1;
	mp["stdexcept"] = 1;
	mp["streambuf"] = 1;
	mp["string"] = 1;
	mp["utility"] = 1;
	mp["vector"] = 1;
	mp["cwchar"] = 1;
	mp["cwctype"] = 1;
}

int main() {
	init();
	scanf("%d", &_);
	while(_--) {
		cin >> s;
		if(mp[s]) puts("Qian");
		else puts("Kun");
	}
}