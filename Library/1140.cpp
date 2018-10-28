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
#define INF (ll)1E9
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

//int dx[]={1,1,1,0,-1,-1,-1,0},dy[8]={1,0,-1,-1,-1,0,1,1,1};
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };

//constexpr ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int H, W;

bool ran(int y, int x) {
	return (0 <= y&&y < H && 0 <= x&&x < W);
}

void solve(int w, int h) {
	int dnum = 0;
	H = h;
	W = w;
	char in;
	vector<vector<bool>> room(h, vector<bool>(w));
	tuple<int, int> st,loc,goal;
	vector<tuple<int, int>> dust;
	rep(i, h) {
		rep(j, w) {
			cin >> in;
			if (in== 'o') {
				st=make_tuple(i, j);
			}
			if (in == '*') {
				goal = make_tuple(i, j);
				dust.push_back(goal);
				dnum++;
			}
			if (in == 'x') {
				room[i][j] = false;
			}
			else {
				room[i][j] = true;
			}
		}
	}
	dust.push_back(st);
	vector<vector<int>> dist(dnum+1, vector<int>(dnum+1,0));
	rep(i, dnum + 1) {
		range(j, i + 1, dnum + 1) {
			tuple<int, int> s = dust[i];
			tuple<int, int> e = dust[j];
			vector<vector<int>> tmp(h, vector<int>(w, 40));
			rep(ii, h) {
				rep(jj, w) {
					if (!room[ii][jj]) {
						tmp[ii][jj] = -1;
					}
				}
			}
			queue <tuple<int, int, int>> q;
			tuple<int, int, int> t = make_tuple(get<0>(s), get<1>(s), 0);
			q.push(t);
			bool sw = true;
			int cost=0;
			while (!q.empty()&&sw) {
				t = q.front(); q.pop();
				int y = get<0>(t);
				int x = get<1>(t);
				int d = get<2>(t);
				if (d < tmp[y][x]) {
					tmp[y][x] = d;
					rep(k, 4) {
						if (ran(y + dy[k], x + dx[k])) {
							if (y + dy[k] == get<0>(e)&& x + dx[k] == get<1>(e)) {
								sw = false;
								cost = d + 1;
							}
							t = make_tuple(y + dy[k], x + dx[k], d + 1);
							q.push(t);
						}
					}
				}
			}
			if (cost == 0) {
				cout << -1 << endl;
				return;
			}
			else {
				dist[i][j] = dist[j][i] = cost;
			}
		}
	}
	vector<vector<int>> dp( pow(2, dnum),  vector<int>(dnum,INF));
	rep(i, dnum) {
		dp[0][i] = dist[dnum][i];
	}
	rep(i, dp.size()) {
		rep(j, dp[i].size()) {
			if (dp[i][j] != INF) {
				rep(k, dp[i].size()) {
					if (!(i&(1 << k))) {
						dp[i + (1 << k)][k] = min(dp[i + (1 << k)][k], dp[i][j] + dist[j][k]);
					}
				}
			}
		}
	}

	cout << *min_element(all(dp.back())) << endl;
	
}

int main(void) {
	int h, w;
	while (cin >> w >> h,h) {
		solve(w, h);
	}
}

