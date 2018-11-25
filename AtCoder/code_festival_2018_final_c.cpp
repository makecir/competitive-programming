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
	int n,m;
	int in;
	cin >> n;
	vi a(n);
	map<int,int> mp;
	rep(i, n) {
		cin >> a[i] >> in;
		mp[a[i]] = in;
	}
	sort(all(a));
	cin >> m;
	rep(i, m) {
		ll ans;
		cin >> in;
		auto itr = lower_bound(all(a), in);
		if (*itr == 0) {
			ans = mp[*(a.end() - 1)] + in - *(a.end() - 1);
		}
		else if (itr != a.begin()) {
			ans = min(mp[*itr], mp[*(itr - 1)] + in - *(itr - 1));
		}
		else {
			ans=mp[*itr];
		}
		cout << ans <<endl;
	}
}
