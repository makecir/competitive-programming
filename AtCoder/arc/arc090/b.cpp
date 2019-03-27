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
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vl l(m), r(m), d(m), loc(n, 0);
	vector<vector<pii>> g(n);
	vb vstd(n, false);
	rep(i, m) {
		cin >> l[i] >> r[i] >> d[i];
		l[i]--; r[i]--;
		g[l[i]].push_back(pii(r[i], d[i]));
		g[r[i]].push_back(pii(l[i], -d[i]));
	}
	ll ans = true;
	for (int i = 0; i < n&&ans; i++) {
		if (!vstd[i]) {
			queue<int> q;
			q.push(i);
			//vstd[i] = true;
			loc[i] = 0;
			while (!q.empty()) {
				if (!vstd[q.front()]) {
					vstd[q.front()] = true;
					rep(j, g[q.front()].size()) {
						int to = g[q.front()][j].fs;
						int dis = g[q.front()][j].sc;
						if (vstd[to]) {
							if (loc[to] != loc[q.front()] + dis)ans = false;
						}
						else {
							q.push(to);
							loc[to] = loc[q.front()] + dis;
						}
					}
				}
				q.pop();
			}
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
}