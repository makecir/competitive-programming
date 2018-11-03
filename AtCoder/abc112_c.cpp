#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;
using msi = map<string, int>;
using mii = map<int, int>;
using psi = pair<string, int>;
using pii = pair<int, int>;
using vlai = valarray<int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
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
	int n;
	cin >> n;
	vector<vvi> vvv(n, vvi(101, vi(101)));
	vi x(n), y(n), h(n);
	rep(i, n) {
		cin >> x[i] >> y[i] >> h[i];
	}
	rep(i, n) {
		rep(j, 101) {
			rep(k, 101) {
				vvv[i][j][k] = (abs(x[i] - j) + abs(y[i] - k) + h[i]);
			}
		}
	}
	rep(j, 101) {
		rep(k, 101) {
			bool b = true;
			int hei= -1 ;
			rep(i, n) {
				if (h[i] != 0) {
					hei = vvv[i][j][k];
					i += n;
				}
			}
			rep(i, n) {
				if (h[i] != 0) {
					if (hei != vvv[i][j][k])b = false;
				}
				else {
					if (hei > vvv[i][j][k]) b = false;
				}
			}
			if (b) {
				cout << j << " " << k << " " << hei << endl;
				return 0;
			}
		}
	}
}
