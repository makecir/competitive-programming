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

ll n, m, q;

void solve() {
	string ou = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	vs s,b;
	vl ans(m,((ll)1<<n)-1);
	string in1, in2;
	rep(i, q) {
		cin >> in1 >> in2;
		s.push_back(in1);
		b.push_back(in2);
	}
	//cout << ans[0];
	//cout << bitset<64>(ans[0]) << endl;
	rep(i, q) {
		ll tr=0;
		ll fa=0;
		rep(j, n) {
			if (s[i][n - j - 1] == '1')tr += 1;
			if(j!=n-1)tr *= 2;
		}
		fa = ((ll)1 << n) - 1 - tr;
		rep(j, m) {
			bool bo;
			if (i != 0)bo = (b[i][j]-'0')^(b[i-1][j] - '0');
			else bo = (b[i][j] != '0');
			if (bo) {
				ans[j]=ans[j]&tr;
			}
			else {
				ans[j] = ans[j] & fa;
			}
		}

		//cout << bitset<64>(tr) << endl;
		//cout << bitset<64>(fa) << endl;
		//cout << bitset<64>(ans[8]) << endl;
	}
	rep(i, m) {
		//cout << bitset<64>(ans[i]) << endl;
		ll che = 1;
		rep(j,n) {
			if (che == ans[i]) {
				cout << ou[j];
				j += n;
			}
			if (j != n - 1) che *= 2;
			else cout << "?";
		}
	}
	cout << endl;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	while (cin >> n >> m >> q,n) {
		solve();
	}
}
