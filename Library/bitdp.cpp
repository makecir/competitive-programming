#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
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
#define EPS 1E-9
#define MOD 1000000007
#define PI 3.1415926535897932384

template <class T>ostream &operator<<(std::ostream &o, const vector<T> &v)
{
	rep(i, v.size()) {
		o << (i > 0 ? " " : "") << v[i];
	}
	return o;
}

void solve(int n) {
	int ans = INF;
	string s;
	vector<string> ss,vs;
	vvi vv(n, vi(n, 0));
	rep(i, n) {
		cin >> s;
		ss.push_back(s);
	}
	rep(i, n) {
		rep(j, n) {
			if (i != j) {
				if (ss[i].find(ss[j]) != std::string::npos) {
					bool sw = true;
					rep(k, vs.size()) {
						if (vs[k] == ss[j])sw = false;
					}
					if (sw)vs.push_back(ss[j]);
				}
			}
		}
	}
	rep(i, vs.size()) {
		rep(j, ss.size()) {
			if (vs[i] == ss[j]) {
				ss.erase(ss.begin() + j);
				n--;
				break;
			}
		}
	}

	rep(i, n) {
		rep(j, n) {
			if (i != j) {
				int t = 0;
				rep(k, min(ss[i].size(), ss[j].size())) {
					if (ss[i].substr(ss[i].size() - k - 1, k + 1) == ss[j].substr(0, k + 1))t = k + 1;
				}
				vv[i][j] = ss[j].size() - t;
			}
		}
	}
	//bitdp
	vvi dp(pow(2, n), vi(n, INF));
	rep(i, n) {
		dp[1 << i][i] = ss[i].size();
	}
	rep(i, pow(2, n)) {
		rep(j, n){
			if(dp[i][j]!=INF){
				rep(k, n) {
					if (!((1 << k) & i)) {
						dp[(1 << k) + i][k] = min(dp[(1 << k) + i][k], dp[i][j] + vv[j][k]);
					}
				}
			}
		}
	}
	cout << *min_element(all(dp.back())) << endl;
}

int main() {
	int n;
	while (cin >> n, n) {
		solve(n);
	}
}
