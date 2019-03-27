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
class rcompare {
public:
	bool operator()(tuple<int, int> a, tuple<int, int> b) {
		return (get<0>(a) < get<0>(b));
	}
};
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vi a(n), b(n), c(n), d(n);
	vector<tii> red, blue;
	rep(i, n) {
		cin >> a[i] >> b[i];
		red.push_back(tii(a[i], b[i]));
	}
	rep(i, n) {
		cin >> c[i] >> d[i];
		blue.push_back(tii(c[i], d[i]));
	}
	sort(all(red), rcompare()); sort(all(blue), compare());
	int ans = 0; 
	rep(i, n) {
		int  x = get<0>(blue[i]);
		int  y = get<1>(blue[i]);
		for (int j = n-1; j>=0; j--) {
			if (get<0>(red[j]) < x && get<1>(red[j]) < y) {
				ans++;
				//cout << get<0>(blue[j]);
				get<0>(red[j]) = INF;
				j = -1;
			}
		}
		//cout << endl;
	}
	cout << ans << endl;
}