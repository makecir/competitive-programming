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

struct union_find {
	vector<int> rnk, par;
	union_find(int n) {
		rnk.resize(n);
		par.resize(n);
		rep(i, rnk.size()) {
			par[i] = i;
			rnk[i] = 0;
		}
	}
	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)return;
		if (rnk[x] < rnk[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (rnk[x] == rnk[y])rnk[x]++;
		}
	}
	bool same(int x, int y) {
		return (find(x) == find(y));
	}
};

int main() {
	int n, k, l, in1, in2;
	cin >> n >> k >> l;
	union_find u1(n), u2(n);
	rep(i, k) {
		cin >> in1 >> in2;
		u1.unite(in1-1, in2-1);
	}
	rep(i, l) {
		cin >> in1 >> in2;
		u2.unite(in1-1, in2-1);
	}
	map<pii, int> mp;
	rep(i, n) {
		mp[pii(u1.find(i), u2.find(i))]++;
	}
	rep(i, n) {
		cout<<mp[pii(u1.find(i), u2.find(i))]<<(i!=n-1?" ":"\n");
	}
}
