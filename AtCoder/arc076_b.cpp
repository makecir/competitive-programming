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
	ll n;
	int ans = 0;
	cin >> n;
	vl x(n), y(n);
	vector<tii> xv, yv;
	vector<vector<tii>> xe(n), ye(n);
	vb used(n, false);
	rep(i, n) {
		cin >> x[i] >> y[i];
		xv.push_back(tii(i, x[i]));
		yv.push_back(tii(i, y[i]));
	}
	sort(all(xv),compare()); sort(all(yv),compare());
	range(i, 1, n) {
		xe[get<0>(xv[i])].push_back(tii(get<0>(xv[i - 1]), abs(get<1>(xv[i]) - get<1>(xv[i - 1]))));
		xe[get<0>(xv[i - 1])].push_back(tii(get<0>(xv[i]), abs(get<1>(xv[i]) - get<1>(xv[i - 1]))));
		ye[get<0>(yv[i])].push_back(tii(get<0>(yv[i - 1]), abs(get<1>(yv[i]) - get<1>(yv[i - 1]))));
		ye[get<0>(yv[i - 1])].push_back(tii(get<0>(yv[i]), abs(get<1>(yv[i]) - get<1>(yv[i - 1]))));
	}
	used[0] = true;
	priority_queue<tii, vector<tii>, pcompare> q;
	rep(i, xe[0].size()) {
		q.push(xe[0][i]);
	}
	rep(i, ye[0].size()) {
		q.push(ye[0][i]);
	}
	rep(i, n - 1) {
		while (used[get<0>(q.top())]) {
			q.pop();
		}
		int to = get<0>(q.top());
		used[to] = true;
		ans += get<1>(q.top()); q.pop();
		rep(j, xe[to].size()) {
			if (!used[get<0>(xe[to][j])]) q.push(tii(xe[to][j]));
		}
		rep(j, ye[to].size()) {
			if (!used[get<0>(ye[to][j])])q.push(tii(ye[to][j]));
		}
	}
	cout << ans << endl;
}