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
	int n, m;
	cin >> n >> m;
	int in1, in2;
	vi a(m), b(m);
	vector<vector<tuple<int, int>>> vv(n + 1);
	rep(i, m) {
		cin >> in1 >> in2;
		a[i] = in1;
		tuple<int, int> t;
		t = make_tuple(i + 1, in2);
		vv[in1].push_back(t);
	}

	rep(i, n + 1) {
		sort(all(vv[i]), compare());
		rep(j, vv[i].size()) {
			b[get<0>(vv[i][j]) - 1] = j + 1;
		}
	}
	rep(i, m) {
		printf("%06d%06d\n", a[i], b[i]);
	}
}
