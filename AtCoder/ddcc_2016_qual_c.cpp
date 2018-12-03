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
	ll n, k;
	ll ans = 0;
	cin >> n >> k;
	ll in;
	map<ll, ll> mp;
	if (k == 1) {
		cout << (n)*(n - 1) / 2 << endl;
		return 0;
	}
	rep(i, n) {
		cin >> in;
		in = gcd(k,in);
		if (in != 1 && (k%in == 0|| in%k == 0))mp[in]++;
	}
	ll tmp = 0;
	for (auto x : mp) {
		for (auto y : mp) {
			if ((x.fs<=y.fs)&&(x.fs*y.fs) % k == 0) {
				if(x.fs==y.fs)ans+= (x.sc)*(x.sc-1)/2;
				else ans += (x.sc)*(y.sc);
			}
		}
		tmp += x.sc;
	}
	ans += mp[k] * (n - tmp);
	cout << ans << endl;
}
