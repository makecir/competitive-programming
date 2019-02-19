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
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k, in, pos = -1;
	cin >> n >> k;
	vb b(n,false);
	vs nap;
	rep(i, k) {
		cin >> in;
		b[in - 1] = true;
	}
	string s;
	string ans;
	rep(i, n) {
		cin >> s;
		if (b[i]) {
			if (pos == -1) {
				pos = s.size();
				ans = s;
			}
			else{
				rep(j, pos) {
					if (j == s.size()){
						pos = min(pos, j); 
						j += 1E6;
					}
					if (j<s.size()&&s[j] != ans[j]) {
						pos = min(pos,j);
						j += 1E6;
					}
				}
			}
		}
		else {
			nap.push_back(s);
		}
	}
	ans = ans.substr(0,pos);
	//cout << ans << endl;
	int mx = 0;
	bool ok = true;
	rep(i, nap.size()) {
		rep(j, nap[i].size()+1) {
			if (j == pos) {
				mx += 1E6;
				j += 1E6;
				ok = false;
			}
			else if (j >= nap[i].size()) {
				mx = max(mx,(int)nap[i].size()+1);
				j += 1E6;
			}
			else if (ans[j] != nap[i][j]) {
				mx = max(mx, j + 1);
				j += 1E6;
			}
		}
	}
	//cout << pos << " "<<mx << endl;
	if (mx <= pos&&ok)cout << ans.substr(0,mx) << endl;
	else cout << -1 << endl;
}
