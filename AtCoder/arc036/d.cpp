#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vb=vector<bool>;
using vvb=vector<vb>;
using vd=vector<double>;
using vvd=vector<vd>;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using tll=tuple<ll,ll>;
using vs=vector<string>;
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n) range(i,0,n)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define range(i,a,n) for(int i=(a);i<(n);i++)

#define LINF    	((ll)1ll<<60)
#define INF     	((int)1<<30)
#define EPS     	(1e-9)
#define MOD     	(1000000007ll)
#define fcout(a)	cout<<setprecision(a)<<fixed
#define fs 			first
#define sc			second
#define PI			(3.1415926535897932384)

int dx[]={1,0,-1,0,1,-1,-1,1},dy[]={0,1,0,-1,1,1,-1,-1};
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s; a=0;} return os;}
template<class T> void chmax(T &a, const T &b){if(a<b)a=b;}
template<class T> void chmin(T &a, const T &b){if(a>b)a=b;}
void YN(bool b){cout<<(b?"YES":"NO")<<"\n";}
void Yn(bool b){cout<<(b?"Yes":"No")<<"\n";}
void yn(bool b){cout<<(b?"yes":"no")<<"\n";}


struct union_find {
	vector<int> rnk, par;
	union_find(int n) {
		rnk.resize(n);
		par.resize(n);
		rep(i, rnk.size()) {
			par[i] = i;
			rnk[i] = 0;
		}
	}
	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)return;
		if (rnk[x] < rnk[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (rnk[x] == rnk[y])rnk[x]++;
		}
	}
	bool same(int x, int y) {
		return (find(x) == find(y));
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,m,w,x,y,z;
	cin>>n>>m;
	union_find u(2*n);
	map<int,int> p;
	rep(i,m){
		cin>>w>>x>>y>>z;
		x--;y--;
		if(w==1){
			if(z%2==0){
				u.unite(x,y);
				u.unite(x+n,y+n);
			}
			else{
				u.unite(x+n,y);
				u.unite(x,y+n);
			}
		}
		else{
			YN(u.same(x,y));
		}

	}
}

