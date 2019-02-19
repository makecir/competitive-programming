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

int len=0;
set<int> st;

void rec(string s) {
	bool th =false,fi=false,se= false;
	rep(i, s.size()) {
		if (s[i] == '3')th = true;
		if (s[i] == '5')fi = true;
		if (s[i] == '7')se = true;
	}
	if (th&&fi&&se) {
		st.insert(stoi(s));
	}
	if ((double)s.size() < len) {
		rec(s + "3");
		rec(s + "5");
		rec(s + "7");
	}

}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	map<int, int> mp;
	rep(i, n) {
		int t = i + 1;
		range(j, 2, 101) {
			while (t%j == 0) {
				t /= j;
				mp[j]++;
			}
		}
	}
	int tw=0, fo=0, ft=0,tf=0,sf=0;
	for(pii p : mp) {
		if (2 <= p.sc)tw++;
		if (4 <= p.sc)fo++;
		if (14 <= p.sc)ft++;
		if (24 <= p.sc)tf++;
		if (74 <= p.sc)sf++;
	}
	for (pii p : mp) {
		//cout << p.fs << " " << p.sc << endl;
	}
	ll ans = 0;
	ans += (max(0, fo)*max(0, fo - 1)) / 2 * max(0, tw - 2);
	ans += tf*max(0, tw - 1);
	ans += ft*max(0, fo - 1);
	ans += sf;
	//cout << tw << " " << fo << " "<<ft<<" "<<tf<<" "<<endl;
	cout << ans << endl;;
}