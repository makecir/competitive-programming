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
	ll n, fsum = 0, bsum = 0;
	cin >> n;
	ll ans = -(LINF);
	vl v(3 * n);
	vl fmx(n+1, 0), bmn(n+1,0);
	priority_queue<ll> b;
	priority_queue<ll, vector<ll>, greater<ll>> f;
	rep(i, 3 * n) {
		cin >> v[i];
		if (i < n) {
			fsum += v[i];
			f.push(v[i]);
		}
		if (i >= 2 * n) {
			bsum += v[i];
			b.push(v[i]);
		}
	}
	fmx[0] = fsum;
	bmn[n] = bsum;
	rep(i, n) {
		if (f.top() < v[n + i]) {
			fsum += v[n + i] - f.top();
			f.pop();
			f.push(v[n + i]);
		}
		fmx[i + 1] = fsum;
	}
	rep(i, n) {
		int j = n - i - 1;
		if (b.top() > v[n + j]) {
			bsum += v[n + j] - b.top();
			b.pop();
			b.push(v[n + j]);
		}
		bmn[j] = bsum;
	}
	rep(i, n+1) {
		ans = max(fmx[i] - bmn[i],ans);
	}
	cout << ans << endl;
}
