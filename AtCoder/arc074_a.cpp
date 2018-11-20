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
	ll h, w;
	cin >> h >> w;
	ll ans = INF;
	range(i, w / 3 - 1, w) {
		if ((w-i)*h % 2==0) {
			ll lb = max((ll)i*h, (ll)(w - i) * h / 2) - min((ll)i*h, (ll)(w - i) * h / 2);
			ans = min(ans, lb);
		}
		else {
			if ((w - i) > h) {
				ll a = ((w - i) / 2 + 1)*h;
				ll b = ((w - i) / 2)*h;
				ll c = i*h;
				ll mx = max(a, max(b, c));
				ll mn = min(a, min(b, c));
				ans = min(ans, mx - mn);
			}
			else {
				ll a = (h / 2 + 1)*(w - i);
				ll b = (h / 2)*(w - i);
				ll c = i*h;
				ll mx = max(a, max(b, c));
				ll mn = min(a, min(b, c));
				ans = min(ans, mx - mn);
			}
		}
	}
	swap(h, w);
	range(i, w / 3, w) {
		if ((w - i)*h % 2==0) {
			ll lb = max((ll)i*h, (ll)(w - i) * h / 2) - min((ll)i*h, (ll)(w - i) * h / 2);
			ans = min(ans, lb);
		}
		else {
			if ((w - i) > h) {
				ll a = ((w - i) / 2 + 1)*h;
				ll b = ((w - i) / 2)*h;
				ll c = i*h;
				ll mx = max(a, max(b, c));
				ll mn = min(a, min(b, c));
				ans = min(ans, mx - mn);
			}
			else {
				ll a = (h / 2 + 1)*(w - i);
				ll b = (h / 2)*(w - i);
				ll c = i*h;
				ll mx = max(a, max(b, c));
				ll mn = min(a, min(b, c));
				ans = min(ans, mx - mn);		
			}

		}
	}
	cout << ans << endl;
}