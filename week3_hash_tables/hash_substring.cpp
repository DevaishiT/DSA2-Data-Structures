#include <iostream>
#include <string>
#include <vector>

using std::string;
//typedef unsigned long long ull;

struct Data 
{
    string pattern, text;
};

Data read_input() 
{
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) 
{
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

long long polyHash (string s, int x, int prime)
{
	long long temp = 0;
	for (long long i = static_cast<long long>(s.length()) - 1; i >= 0; i--)
		temp = (temp*x + s[i])%prime; 
	return temp;
}

std::vector<long long> precomputeHashes (string t, int p, int prime, int x)
{
	std::vector<long long> H(t.length() - p + 1);
	string s = t.substr(t.length() - p, p);
	H[H.size() - 1] = polyHash(s, x, prime);
	long long y = 1;
	for(int i = 0; i < p; i++) y = (y * x) % prime;
	for(int i = H.size() - 2; i >= 0; i--)
		H[i] = ((x*H[i+1] + t[i] - y*t[i+p])%prime + prime)%prime;
	return H;
}


std::vector<int> get_occurrences(const Data& input) 
{
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    int prime = 1000000007;
    int x = rand() % (prime - 1) + 1;
     long long  s_hash = polyHash(s, x, prime);
    std::vector< long long> t_hash = precomputeHashes(t, s.length(), prime, x);
    for (size_t i = 0; i + s.size() <= t.size(); ++i) 
    {
        if (s_hash != t_hash[i]) continue;
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    }
    return ans;

    // const string& s = input.pattern, t = input.text;
    // std::vector<int> ans;
    // for (size_t i = 0; i + s.size() <= t.size(); ++i)
    //     if (t.substr(i, s.size()) == s)
    //         ans.push_back(i);
    // return ans;
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
