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
#define MOD (1E9+7)
#define PI 3.1415926535897932384

class compare {
public:
	bool operator()(tuple<ll, ll> a, tuple<ll, ll> b) {
		return (get<1>(a) > get<1>(b));
	}
};

int V;
vector<vector<tll>> g;
vector<ll> d;

void dijkstra(int s) {
	fill(all(d),LINF);
	d[s]=0;
	vb vstd(V, false);
	priority_queue<tll, vector<tll>, compare> q;
	q.push(tll(s, 0));
	while (!q.empty()) {
		ll to, dist;
		tie(to, dist) = q.top(); q.pop();
		if (vstd[to])continue;
		vstd[to] = true;
		d[to] = dist;
		rep(i, g[to].size()) {
			ll next = get<0>(g[to][i]);
			ll cost = get<1>(g[to][i]);
			if (d[next] < dist + cost)continue;
			q.push(tll(next, dist + cost));
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m,t;
	cin>>n>>m;
	vl x(m),y(m),z(m);
	V=(int)n;
	g.resize(n);
	d.resize(n);
	rep(i,m){
		cin>>x[i]>>y[i]>>z[i];
		x[i]--;y[i]--;//0indexed
		g[x[i]].push_back(tll(y[i],z[i]));
	}
	dijkstra(0);
}


/*

vector<ll> dijkstra(int s,int V,vector<vector<tll>> g) {
	vector<ll> d(V);
	fill(all(d),LINF);
	d[s]=0;
	vb vstd(V, false);
	priority_queue<tll, vector<tll>, compare> q;
	q.push(tll(s, 0));
	while (!q.empty()) {
		ll to, dist;
		tie(to, dist) = q.top(); q.pop();
		if (vstd[to])continue;
		vstd[to] = true;
		d[to] = dist;
		rep(i, g[to].size()) {
			ll next = get<0>(g[to][i]);
			ll cost = get<1>(g[to][i]);
			if (d[next] < dist + cost)continue;
			q.push(tll(next, dist + cost));
		}
	}
	return d;
}
*/