#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
using vb = vector<bool>;
using vs = vector<string>;
using msi = map<string, int>;
using mii = map<int, int>;
using psi = pair<string, int>;
using pii = pair<int, int>;
using vlai = valarray<int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define mp make_pair
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

vl fact(200002), finv(200002);

ll modpw(ll x, ll k) {
	ll res = 1;
	while (k != 0) {
		if (k& 1) res = res*x % MOD;
		x = x*x % MOD;
		k = k >> 1;
	}
	return res;
}

ll comb(ll n, ll k) {
	if (n == 0 && k == 0)return 1;
	if (n < k || n < 0)return 0;
	return fact[n] * finv[n - k] % MOD * finv[k] % MOD;;
}

int main() {
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	ll ans = 0;
	fact[0] = 1;
	finv[0] = 1;
	rep(i, 200001) {
		fact[i + 1] = (fact[i] * (i + 1)) % MOD;
		finv[i + 1] = modpw(fact[i + 1], MOD - 2);
	}
	rep(i, w - b) {
		ans += comb(h - a + b + i - 1, h - a - 1)*comb(a + w - b - i - 2, a - 1);
		ans %= MOD;
	}
	cout << ans << endl;
}
