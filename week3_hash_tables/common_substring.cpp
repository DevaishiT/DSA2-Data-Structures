#include <iostream>
#include <vector>

using namespace std;
typedef long long lli;

struct Answer {
	size_t i, j, len;
};

Answer solve(const string &s, const string &t) {
	Answer ans = {0, 0, 0};

	int prime1 = 1000000007;
	int prime2 = 67108864;
	int x = rand()%(prime - 1) + 1;

	// for (size_t i = 0; i < s.size(); i++)
	// 	for (size_t j = 0; j < t.size(); j++)
	// 		for (size_t len = 0; i + len <= s.size() && j + len <= t.size(); len++)
	// 			if (len > ans.len && s.substr(i, len) == t.substr(j, len))
	// 				ans = {i, j, len};
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	string s, t;
	while (cin >> s >> t) {
		auto ans = solve(s, t);
		cout << ans.i << " " << ans.j << " " << ans.len << "\n";
	}
}
