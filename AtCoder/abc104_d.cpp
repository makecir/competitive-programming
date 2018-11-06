#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
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
	ll ans = 0;
	string s;
	cin >> s;
	int n = s.size();
	vll vv(4, vl(n+1));
	vv[0][0] = 1;
	range(i,1,n+1) {
		if (s[i-1] == '?') {
			rep(j, 4) vv[j][i] = vv[j][i - 1] * 3;
			rep(j, 3) vv[j+1][i] += vv[j][i - 1];
		}
		else {
			vv[0][i] = vv[0][i - 1];
			vv[1][i] = vv[1][i - 1];
			vv[2][i] = vv[2][i - 1];
			vv[3][i] = vv[3][i - 1];
			if (s[i-1] == 'A') vv[1][i] += vv[0][i - 1];
			if (s[i-1] == 'B') vv[2][i] += vv[1][i - 1];
			if (s[i-1] == 'C') vv[3][i] += vv[2][i - 1];
		}
		rep(j, 4) vv[j][i] %= MOD;
	}
	cout << vv[3][n] << endl;
}
