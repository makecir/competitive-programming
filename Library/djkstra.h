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

std::ostream &operator<<(std::ostream &out, const vector<int> &tgt)
{
	string s;
	for (int i = 0; i<tgt.size(); i++) {
		s += (to_string(tgt[i]) + ((i != tgt.size() - 1) ? " " : ""));
	}
	out << s;
	return out;
}

#define P pair<int,int>
struct edge { int to, cost; };

class CompareDist
{
public:
	bool operator()(pair<int, int> n1, pair<int, int> n2) {
		return n1.second > n2.second;
	}
};

int V;
vector<vector<edge>> G;
vector<int> d;

void dijkstra(int s) {
	priority_queue<P, vector<P>, CompareDist> q;
	//fill(d,d+V,INT_MAX);
	d = vector<int>(V, INT_MAX);
	d[s] = 0;
	q.push(P(s, 0));     

	while (!q.empty()) {
		P p = q.top(); q.pop();
		int v = p.first;
		if (d[v]<p.second)continue;
		for (int i = 0; i<G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to]>d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				q.push(P(e.to, d[e.to]));
			}
		}
	}
}
int main(void) {
	int n, in, t, c;
	cin >> n;
	V = n;
	G.resize(n);
	d.resize(n);
	for (int i = 0; i<n; i++) {
		cin >> in;
		int node = in;
		cin >> in;
		for (int j = 0; j<in; j++) {
			cin >> t >> c;
			edge ed = { t,c };
			G[node].push_back(ed);
		}

	}
	dijkstra(0);
	for (int i = 0; i<d.size(); i++) {
		cout << i << " " << d[i] << endl;
	}
}
