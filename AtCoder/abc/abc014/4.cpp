#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
using tlll=tuple<ll,ll,ll>;
using vs=vector<string>;

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n) range(i,0,n)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define range(i,a,n) for(ll i=(a);i<(n);i++)

#define LINF ((ll)1ll<<60)
#define INF ((int)1<<30)
#define EPS (1e-9)
#define MOD (1000000007ll)
//#define MOD (998244353ll)
#define fcout(a) cout<<setprecision(a)<<fixed
#define fs first
#define sc second
#define PI 3.1415926535897932384

int dx[]={1,0,-1,0,1,-1,-1,1},dy[]={0,1,0,-1,1,1,-1,-1};

template<class T>bool chmax(T&a,T b){if(a<b){a=b; return true;}return false;}
template<class T>bool chmin(T&a,T b){if(a>b){a=b; return true;}return false;}
template<class S>S acm(vector<S>&a){return accumulate(all(a),S());}
template<class S>S max(vector<S>&a){return *max_element(all(a));}
template<class S>S min(vector<S>&a){return *min_element(all(a));}
void YN(bool b){cout<<(b?"YES":"NO")<<"\n";}
void Yn(bool b){cout<<(b?"Yes":"No")<<"\n";}
void yn(bool b){cout<<(b?"yes":"no")<<"\n";}
int sgn(const double&r){return (r>EPS)-(r<-EPS);} // a>0  : sgn(a)>0
int sgn(const double&a,const double&b){return sgn(a-b);} // b<=c : sgn(b,c)<=0

ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}
template<class T>void puta(T&&t){cout<<t<<"\n";}
template<class H,class...T>void puta(H&&h,T&&...t){cout<<h<<' ';puta(t...);}
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;}
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s;a=0;} return os;}

ll n,q,logn;
vl depth;
vvl g,par;

void rec(ll c,ll p,ll d){
	depth[c]=d;
	par[c].resize(logn);
	par[c][0]=p;
	for(auto x:g[c]){
		if(depth[x]<depth[c])continue;
		rec(x,c,d+1);
	}
}

void init_par(){
	rec(0,-1,0);
	rep(i,logn-1)rep(j,n){
		if(par[j][i]==-1) par[j][i+1]=-1;
		else par[j][i+1]=par[par[j][i]][i];
	}
}

ll lca(ll a,ll b){
	if(depth[a]>depth[b])swap(a,b);
	rep(i,logn){
		if((depth[b]-depth[a])&(1ll<<i))b=par[b][i];
	}
	if(a==b)return a;
	rrep(i,logn){
		if(par[a][i]!=par[b][i]){
			a=par[a][i];
			b=par[b][i];
		}
	}
	return par[a][0];
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll a,b;
	cin>>n;
	logn=(log(n)/log(2))+1;
	g.resize(n);
	depth.resize(n,LINF);
	par.resize(n);
	rep(i,n-1){
		cin>>a>>b;
		--a,--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	init_par();
	cin>>q;
	while(q--){
		cin>>a>>b;
		--a,--b;
		ll c=lca(a,b);
		ll ans=depth[a]+depth[b]-2*depth[c]+1;
		puta(ans);
	}
}
