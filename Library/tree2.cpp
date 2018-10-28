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

struct node {
	int p = -1, s = -1, deg = 0, dep = -1, h = -1;
	vi c;
};

vector<node> G;

void setdepth(int n,int d) {
	G[n].dep = d;
	rep(i, G[n].c.size()) {
		setdepth(G[n].c[i], d + 1);
	}
}

int setheight(int n) {
	int maxh = -1;
	rep(i, G[n].c.size()) {
		G[G[n].c[i]].h = setheight(G[n].c[i]);
		maxh = max(maxh, G[G[n].c[i]].h);
	}
	return maxh+1;
}


int main() {
	int n,ina,inb,inc;
	cin >> n;
	G.resize(n);
	rep(i, n) {
		cin >> ina >> inb >> inc;
		if (inb != -1) {
			G[ina].c.push_back(inb);
			G[inb].p = ina;
		}		
		if (inc != -1) {
			G[ina].c.push_back(inc);
			G[inc].p = ina;
		}
		if (G[ina].c.size()==2) {
			G[inc].s = inb;
			G[inb].s = inc;
		}
	}
	rep(i, n) {
		if (G[i].p == -1) {
			setdepth(i,0);
			G[i].h = setheight(i);
		}
	}
	rep(i,n){
		//node 0: parent = -1, sibling = -1, degree = 2, depth = 0, height = 3, root
		cout << "node " << i << ": parent = " << G[i].p;
		cout << ", sibling = " << G[i].s;
		cout << ", degree = " << G[i].c.size();
		cout << ", depth = " << G[i].dep;
		cout << ", height = " << G[i].h<<", ";
		if (G[i].p == -1)cout << "root";
		else if (G[i].h == 0)cout << "leaf";
		else cout << "internal node";
		cout << endl;
	}
}