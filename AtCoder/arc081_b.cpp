#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vs = vector<string>;
using msi = map<string, int>;
using mii = map<int, int>;
using psi = pair<string, int>;
using pii = pair<int, int>;
using tii = tuple<int, int>;
using vlai = valarray<int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define INF 1E9
#define LINF 1E18*5
#define EPS 1E-9
#define MOD 1000000007
#define PI 3.1415926535897932384

template<class S, class T>ostream& operator<<(ostream&os, pair<S, T>p) { os << "[" << p.first << ", " << p.second << "]"; return os; };
template<class S>auto&operator<<(ostream&os, vector<S>t) { bool a = 1; for (auto s : t) { os << (a ? "" : " ") << s; a = 0; } return os; }

//int dx[]={1,1,1,0,-1,-1,-1,0},dy[8]={1,0,-1,-1,-1,0,1,1,1};
//
constexpr ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

class compare {
public:
	bool operator()(tuple<int, int> a, tuple<int, int> b) {
		return (get<1>(a) < get<1>(b));
	}
};

class pcompare {
public:
	bool operator()(tuple<int, int> a, tuple<int, int> b) {
		return !(get<1>(a) < get<1>(b));
	}
};

int main() {
	int n;
	cin>>n;
	string s;
	cin >> s;
	vb v(1, true);
	range(i, 1, s.size()) {
		if (s[i] == s[i - 1]) {
			v.back() = false;
		}
		else {
			v.push_back(true);
		}
	}
	ll ans =(v[0]?3:6);
	range(i, 1, v.size()) {
		ll mul;
		if (v[i - 1] == false && v[i]) mul=1;
		if (v[i - 1] && v[i] == false) mul=2;
		if (v[i - 1] && v[i]) mul=2;
		if (v[i - 1] == false && v[i] == false)mul=3;
		ans *= mul;
		ans %= MOD;
	}
	cout << ans << endl;
}