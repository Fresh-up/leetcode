#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
//模糊回文字符串
bool function(string& s) {
	if (s.empty()) return false;
	stack<char> stk;
	int cnt = 0;
	for (int k = 0; k < s.size(); ++k) {
		s[k] = tolower(s[k]);
	}
	sort(s.begin(), s.end());
	for (auto i : s) {
		if (isalpha(i)) {
			if (stk.empty())
				stk.push(i);
			else {
				if (stk.top() == i) {
					stk.pop();
				}
				else stk.push(i);
			}
		}
		else ++cnt;
	}
	if (stk.empty()) return true;
	else {
		if (stk.size() == 1 && !(cnt & 1))
			return true;
		else return false;
	}
}

int main() {
	string s;
	while (1) {
		cin >> s;
		if (function(s)) cout << "true" << endl;
		else cout << "false" << endl;
	}
	return 0;
}