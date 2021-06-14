#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using vb=vector<bool>;
using vvb=vector<vb>;
using vd=vector<double>;
using vvd=vector<vd>;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii=pair<int,int>;
using pdd=pair<double,double>;
using pll=pair<ll,ll>;
using vpll=vector<pll>;
using tll=tuple<ll,ll>;
using tlll=tuple<ll,ll,ll>;
using vs=vector<string>;

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n) range(i,0,n)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define range(i,a,n) for(ll i=(a);i<(n);i++)
#define sz(x) ((ll)(x).size())

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
int popcnt(int x){return __builtin_popcount(x);}
int popcnt(ll x){return __builtin_popcountll(x);}
ll modpw(ll x,ll k){ll res=1;while(k!=0){if(k&1){res=res*x%MOD;}x=x*x%MOD;k=k>>1;}return res;}

ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}
template<class T>void puta(T&&t){cout<<t<<"\n";}
template<class H,class...T>void puta(H&&h,T&&...t){cout<<h<<' ';puta(t...);}
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;}
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s;a=0;} return os;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;
	vl a(n),b(n),c(n),d(m),e(m),f(m);
	rep(i,n)cin>>a[i]>>b[i]>>c[i];
	rep(i,m)cin>>d[i]>>e[i]>>f[i];
	map<ll,ll> mpy,mpx,revx,revy;
	rep(i,n)mpx[a[i]]=0,mpx[b[i]]=0,mpy[c[i]]=0;
	rep(i,m)mpx[d[i]]=0,mpy[e[i]]=0,mpy[f[i]]=0;
	mpx[0]=0;mpy[0]=0;
	ll szx=0,szy=0;
	for(auto &x:mpx)x.sc=szx++,revx[x.sc]=x.fs;
	for(auto &y:mpy)y.sc=szy++,revy[y.sc]=y.fs;
	ll w=szx+1,h=szy+1;
	vvb lx(szy,vb(w)),ly(h,vb(szx));
	rep(i,n){
		ll st=mpx[a[i]],en=mpx[b[i]],pos=mpy[c[i]];
		range(j,st+1,en+1)lx[pos][j]=true;
	}
	rep(i,m){
		ll st=mpy[e[i]],en=mpy[f[i]],pos=mpx[d[i]];
		range(j,st+1,en+1)ly[j][pos]=true;
	}
	dsu u(w*h);
	vl wht(w*h);
	rep(i,h)rep(j,w){
		if(i!=h-1)if(!lx[i][j])u.merge(i*w+j,(i+1)*w+j);
		if(j!=w-1)if(!ly[i][j])u.merge(i*w+j,i*w+j+1);
		if(i!=0&&i!=h-1&&j!=0&&j!=w-1)wht[i*w+j]=(revy[i]-revy[i-1])*(revx[j]-revx[j-1]);
		else wht[i*w+j]=-1;
	}
	bool inf=false;
	ll ans=0;
	ll st=(mpy[0])*w+mpx[0];
	rep(i,w*h){
		if(!u.same(st,i))continue;
		if(wht[i]<0)inf=true;
		else ans+=wht[i];
	}
	if(inf)puta("INF");
	else puta(ans);
}
