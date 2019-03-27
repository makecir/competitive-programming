#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
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
#define pb push_back
#define eb emplace_back
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

vector<vl> vv;
vl c;
int w;


ll prob(int f, int e) {
	ll res = 1;
	ll l = 1, r = 1;
	l = c[max(0, f) - 0];
	r = c[w - 1 - min(e, w - 1)];
	res = l*r;
	return res;
}

ll ans(int h, int k) {
	if (h == 0) {
		if (k == 0)return 1;
		else return 0;
	}
	if (vv[h][k] != -1) {
		return vv[h][k];
	}
	else {
		int hasi = 0;
		if (k == 0 || k == w - 1)hasi++;
		ll res = ans(h - 1, k)*prob(k - 1, k + 1);
		res %= MOD;
		hasi = (k == 1 || k == w - 1) ? 1 : 0;
		if (k != 0) {
			res += ans(h - 1, k - 1) * prob(k - 2, k + 1);
			res %= MOD;
		}
		hasi = (k == 0 || k == w - 2) ? 1 : 0;
		if (k != w - 1) {
			res += ans(h - 1, k + 1) * prob(k - 1, k + 2);
			res %= MOD;
		}
		vv[h][k] = res;
		return res;
	}
}

int main() {
	int h, k;
	cin >> h >> w >> k;
	rep(i, h + 1) {
		vl v;
		rep(j, w) {
			v.push_back(-1);
		}
		vv.push_back(v);
	}
	rep(i, w) {
		c.push_back(1);
	}
	c[1] = 2;
	range(i, 2, w) {
		c[i] = c[i - 1] + c[i - 2];
	}
	cout << ans(h, k - 1) << endl;

}
