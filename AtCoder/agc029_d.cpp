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
		if (get<1>(a) < get<1>(b))return true;
		else if (get<1>(a) == get<1>(b))return (get<0>(a) < get<0>(b));
		else return false;
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll h, w, n;
	cin >> h >> w >> n;
	vl x(n), y(n);
	vector<tii> v(n);
	rep(i, n) {
		cin >> x[i] >> y[i];
		x[i]--;
		y[i]--;
		v[i]=(tii(y[i], x[i]));
	}
	sort(all(v), compare());
	v.push_back(tii(-1, h));
	int pos = -1;
	rep(i, v.size()) {
		//cout << get<0>(v[i]) <<" "<<get<1>(v[i]) << endl;
	}
	rep(i, v.size()) {
		int dif = get<1>(v[i]) - get<0>(v[i]);
		//cout << dif << endl;
		if (dif - pos >= 2) {
			cout << get<1>(v[i]) << endl;
			return 0;
		}
		else pos = max(pos, dif);
	}
}

