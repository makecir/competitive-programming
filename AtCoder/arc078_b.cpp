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

class pcompare {
public:
	bool operator()(tuple<int, int> a, tuple<int, int> b) {
		return !(get<1>(a) < get<1>(b));
	}
};

int main() {
	int n, in1, in2;
	cin >> n;
	vvi vv(n);
	rep(i, n - 1) {
		cin >> in1 >> in2;
		in1--; in2--;
		vv[in1].push_back(in2);
		vv[in2].push_back(in1);
	}
	queue<pii> f, s;
	vi c(n, 0);
	c[0] = 1; c[n - 1] = -1;
	//rep(i, vv[0].size())f.push(pii(vv[0][i],0));
	//rep(i, vv[n-1].size())s.push(pii(vv[n-1][i],0));
	f.push(pii(0, 0));
	s.push(pii(n - 1, 0));
	rep(i, n-1) {
		bool sw = false;
		while (!f.empty()&&f.front().sc == i) {
			rep(j, vv[f.front().fs].size()) {
				if (c[vv[f.front().fs][j]] == 0) {
					f.push(pii(vv[f.front().fs][j], i + 1));
					sw = true;
					c[vv[f.front().fs][j]] = 1;
				}
			}
			f.pop();
		}
		while (!s.empty()&&s.front().sc == i) {
			rep(j, vv[s.front().fs].size()) {
				if (c[vv[s.front().fs][j]] == 0){
					s.push(pii(vv[s.front().fs][j], i + 1));
					sw = true;
					c[vv[s.front().fs][j]] = -1;
				}
			}
			s.pop();
		}
		if (!sw)break;
	}
	queue<int> fe, su;
	fe.push(0);	su.push(0);
	ll cnt = 1;
	while (!fe.empty()) {
		c[fe.front()] = 2;
		rep(i, vv[fe.front()].size()) {
			if (c[vv[fe.front()][i]] ==0 || c[vv[fe.front()][i]] ==1) {
				fe.push(vv[fe.front()][i]);
				cnt++;
			}
		}
		fe.pop();
		//cnt++;
	}
	cout << (cnt * 2 > n ? "Fennec" : "Snuke") << endl;
	
}