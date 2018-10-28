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
#define PI 3.1415926535897932384626433832795

struct edge {
	vi c;
	int depth = 0,p=-1;
};

vector<edge> G(0);

void setdepth(int n, int d) {
	G[n].depth = d;
	rep(i, G[n].c.size()) {
		setdepth(G[n].c[i], d + 1);
	}
}

int main() {
	int n,m,id,num,in;
	cin >> n;
	G.resize(n);
	rep(i, n) {
		cin >> id >> num;
		rep(j, num) {
			cin >> in;
			G[id].c.push_back(in);
			G[in].p = id;
		}
	}
	rep(i, n) {
		if (G[i].p == -1) {
			id = i;
		}
	}
	setdepth(id, 0);
	rep(i, n) {
		//"node 0: parent = -1, depth = 0, "
		cout << "node " << i << ": parent = " << G[i].p;
		cout << ", depth = " << G[i].depth << ", ";
		if (G[i].p == -1) {
			cout << "root";
		}
		else if (G[i].c.size() == 0) {
			cout << "leaf";
		}
		else cout << "internal node";
		cout << ", [";
		rep(j, G[i].c.size()){
			cout << G[i].c[j] << (j < G[i].c.size()-1 ? ", " : "");
		}
		cout << "]" << endl;
	}
}