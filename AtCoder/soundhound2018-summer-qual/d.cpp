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

constexpr ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

class compare {
public:
	bool operator()(tuple<ll, ll> a, tuple<ll, ll> b) {
		return (get<1>(a) > get<1>(b));
	}
};

using tll = tuple<ll, ll>;
using tlll = tuple<ll, ll, ll>;

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);
	cout << setprecision(18) ;
	//cout << fixed;
	ll n, m, s, t;
	cin >> n >> m >> s >> t;
	s--; t--;
	vector<vector<tlll>> g(n);
	vl u(m), v(m), a(m), b(m);
	rep(i, m) {
		cin >> u[i] >> v[i] >> a[i] >> b[i];
		u[i]--; v[i]--;
		g[u[i]].push_back(tlll(v[i], a[i], b[i]));
		g[v[i]].push_back(tlll(u[i], a[i], b[i]));
	}
	vb vstd(n, false);
	vl en(n, LINF), sn(n, LINF);
	priority_queue<tll, vector<tll>, compare> q;
	q.push(tll(s, 0));
	while (!q.empty()) {
		ll to, dist;
		tie(to, dist) = q.top(); q.pop();
		if (vstd[to])continue;
		vstd[to] = true;
		en[to] = dist;
		rep(i, g[to].size()) {
			ll next = get<0>(g[to][i]);
			ll cost = get<1>(g[to][i]);
			if (en[next] < dist + cost)continue;
			q.push(tll(next, dist + cost));
		}
	}
	fill(all(vstd), false);
	priority_queue<tll, vector<tll>, compare> q2;
	q2.push(tll(t, (ll)0));
	while (!q2.empty()) {
		ll to, dist;
		tie(to, dist) = q2.top(); q2.pop();
		if (vstd[to])continue;
		vstd[to] = true;
		sn[to] = dist;
		rep(i, g[to].size()) {
			ll next = get<0>(g[to][i]);
			ll cost = get<2>(g[to][i]);
			if (sn[next] < dist + cost)continue;
			q2.push(tll(next, dist + cost));
		}
	}
	ll mn = LINF;
	vl ans(n);
	rep(i, n) {
		mn = min(mn, en[n - i - 1] + sn[n - i - 1]);
		ans[n - i - 1] = mn;
	}
	rep(i, n) {
		cout << 1e15 - ans[i] << endl;
	}
}

