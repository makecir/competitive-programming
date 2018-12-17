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
	ll n, m;
	ll ans = 0;
	char c;
	cin >> n >> m;
	vvi vv(n, vi(m));
	vvi vv1(n, vi(m)), vv2(n, vi(m)), vv3(n, vi(m)), vv4(n, vi(m));
	rep(i, n) {
		rep(j, m) {
			cin >> c;
			vv[i][j]=(c=='.'?1:0);
		}
	}
	rep(i, n) {
		int t = -1;
		rep(j, m) {
			t = (vv[i][j] == 1 ? t+1 : -1 );
			vv1[i][j] = max(t,0);
		}
	}
	rep(i, n) {
		int t = -1;
		rep(j, m) {
			int jj = m - j - 1;
			t = (vv[i][jj] == 1 ? t + 1 : -1);
			vv2[i][jj] = max(t, 0);
		}
	}
	rep(j, m) {
		int t = -1;
		rep(i, n) {
			t = (vv[i][j] == 1 ? t + 1 : -1);
			vv3[i][j] = max(t, 0);
		}
	}
	rep(j, m) {
		int t = -1;
		rep(i, n) {
			int ii = n - i - 1;
			t = (vv[ii][j] == 1 ? t + 1 : -1);
			vv4[ii][j] = max(t, 0);
		}
	}
	rep(i, n) {
		rep(j, m) {
			ans += vv1[i][j] * vv3[i][j];
			ans += vv1[i][j] * vv4[i][j];
			ans += vv2[i][j] * vv3[i][j];
			ans += vv2[i][j] * vv4[i][j];
		}
	}
	cout << ans << endl;
}

