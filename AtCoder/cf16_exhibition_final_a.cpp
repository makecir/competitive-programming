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
	vl f(100001); f[1]=1;
	//range(i, 2, f.size()) {
	//	f[i] = f[i - 1] * i;
	//	f[i] %= MOD;
	//}
	int n;
	cin >> n;
	vi a(n), b(n);
	rep(i, n) cin >> a[i] ;
	rep(i, n) cin >> b[i];
	sort(all(a));sort(all(b));
	a.push_back(INF);	b.push_back(INF);
	vi v;
	ll ans = 1;
	//cout << a << endl;
	//cout << b << endl;
	int j = 0, k = 0;
	rep(i, 2 * n) {
		if (a[j] < b[k]) {
			v.push_back(j);
			j++;
		}
		else {
			v.push_back(k);
			k++;
		}
	}
	int mx = 0;
	rep(i, v.size()) {
		mx = max(v[i], mx);
		ans *= max(mx - v[i], 0)+1;
		ans %= MOD;
	}
	cout << ans << endl;
}