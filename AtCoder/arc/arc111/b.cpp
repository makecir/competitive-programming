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
struct UnionFind{
	vl par,dist,ed;
	UnionFind(int x){par.assign(x,-1); dist.assign(x,0); ed.assign(x,0); }
	ll find(ll x){return par[x]<0?x:find(par[x]);}
	ll depth(ll x){return par[x]<0?0:depth(par[x])+dist[x];}
	bool same(ll x,ll y){return find(x)==find(y);}
	ll size(ll x){return -par[find(x)];}
	ll diff(ll x,ll y){return same(x,y)?depth(x)-depth(y):LINF;}
	void unite(ll x,ll y,ll k=0){
		k+=depth(y); k-=depth(x); k=-k;
		x=find(x); y=find(y);
		ed[x]++;
		if(x==y)return;
		if(size(x)<size(y)){swap(x,y);k=-k;}
		par[x]+=par[y]; par[y]=x; dist[y]=k;
		ed[x]+=ed[y];
	}
	ll edge(ll x){return ed[x];}
};
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,a,b;
	cin>>n;
	UnionFind u(400000);
	rep(i,n){
		cin>>a>>b;
		u.unite(--a,--b);
	}
	ll ans=0;
	rep(i,400000){
		if(u.find(i)!=i)continue;
		if(u.size(i)>u.edge(i))ans+=u.size(i)-1;
		else ans+=u.size(i);
	}
	puta(ans);
}
