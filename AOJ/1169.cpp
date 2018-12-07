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

int n, m, s, g;

struct edge {
	int from, to;
	string w;
};

void solve(){
	int in1, in2;
	string in;
	cin >> m >> s >> g;
	vector<edge> e(m);
	vs dist(n, "A");
	string ans;
	rep(i, m) {
		cin >> in1 >> in2;
		cin >> in;
		e[i].from = in1;
		e[i].to = in2;
		e[i].w = in;
		//cout << e[i].w << endl;
	}
	dist[g] = "";
	bool ok = true;
	rep(i,  6* n) {
		rep(j, m) {
			if (dist[e[j].to] != "A" && (dist[e[j].from] == "A" ||(dist[e[j].from] >  e[j].w+ dist[e[j].to]))) {
				dist[e[j].from] = e[j].w + dist[e[j].to];
				//if (e[j].from == s)cout << i <<" "+ dist[s] << endl;
			}
		}
		if (i == n - 1)ans = dist[s];
		rep(j, n) {
			//cout << j << " " << dist[j] << endl;
		}
	}
	rep(i, n) {
		//cout << dist[i] << endl;
	}
	if (dist[s] != ans||dist[s]=="A") {
		cout << "NO" << endl;
	}
	else {
		cout << dist[s] << endl;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> n,n) {
		solve();
	}
}
