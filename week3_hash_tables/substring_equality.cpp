#include <iostream>
#include <vector>

using namespace std;
typedef long long lli;

class Solver {
	string s;
	int x; 
	int prime1;
	int prime2;
	vector<lli> hash1_array;
	vector<lli> hash2_array;
	vector<lli> power1_array;
	vector<lli> power2_array;
public:	
	Solver(string s) : s(s) {	
		// initialization, precalculation
		prime1 = 1000000007;
		prime2 = 67108864;
		x = rand()%(prime2 - 1) + 1;
		// x = 2;
		hash1_array.resize(s.length());
		hash2_array.resize(s.length());
		power1_array.resize(s.length());
		power2_array.resize(s.length());

		// hash_array[s.length() - 1] = s[s.length() - 1];
		hash1_array[s.length() - 1] = s[s.length() - 1] - 97;
		hash2_array[s.length() - 1] = s[s.length() - 1] - 97;
		power1_array[0] = power2_array[0] = 1;

		for(int i = s.length() - 2; i >= 0; i--)
		{
			// hash_array[i] = ((hash_array[i + 1]*x)%prime + s[i])%prime;
			hash1_array[i] = ((hash1_array[i + 1]*x)%prime1 + s[i] - 97)%prime1;
			if (hash1_array[i] < 0) hash1_array[i] += prime1;

			hash2_array[i] = ((hash2_array[i + 1]*x)%prime2 + s[i] - 97)%prime2;
			if (hash2_array[i] < 0) hash2_array[i] += prime2;
		}

		for(int i = 1; i < s.length(); i++)
		{
			power1_array[i] = (power1_array[i-1]*x)%prime1;
			if (power1_array[i] < 0) power1_array[i] += prime1;

			power2_array[i] = (power2_array[i-1]*x)%prime2;
			if (power2_array[i] < 0) power2_array[i] += prime2;
		}

		// for (int i=0; i<s.length(); i++) 
		// 	cout << hash_array[i] << " " << power_array[i] << endl;
	}
	bool ask(int a, int b, int l) {

		if (a == b) return true;

		lli hash_A, hash_B;
		if (a + l < s.length())
			hash_A = (hash1_array[a] - (power1_array[l] * hash1_array[a+l]) % prime1) % prime1;
		else hash_A = hash1_array[a];
		if (hash_A < 0) hash_A += prime1;

		if (b + l < s.length())
			hash_B = (hash1_array[b] - (power1_array[l] * hash1_array[b+l]) % prime1) % prime1;
		else hash_B = hash1_array[b];
		if (hash_B < 0) hash_B += prime1;

		if (hash_B != hash_A) return false;

		if (a + l < s.length())
			hash_A = (hash2_array[a] - (power2_array[l] * hash2_array[a+l]) % prime2) % prime2;
		else hash_A = hash2_array[a];
		if (hash_A < 0) hash_A += prime2;

		if (b + l < s.length())
			hash_B = (hash2_array[b] - (power2_array[l] * hash2_array[b+l]) % prime2) % prime2;
		else hash_B = hash2_array[b];
		if (hash_B < 0) hash_B += prime2;

		// cout << hash_A << " " << hash_B << endl;

		if (hash_B != hash_A) return false;

		// cout << s.substr(a, l) << " " << s.substr(b, l) << endl;
		// return s.substr(a, l) == s.substr(b, l);
		else return true;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
