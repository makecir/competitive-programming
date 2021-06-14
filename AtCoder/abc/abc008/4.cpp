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
using vvvl=vector<vvl>;
using vvvvl=vector<vvvl>;
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
	ll h,w,n;
	cin>>w>>h>>n;
	vl x(n+2),y(n+2);
	rep(i,n)cin>>x[i+1]>>y[i+1];
	x[n+1]=w+1;y[n+1]=h+1;
	vl ox=x,oy=y;
	sort(all(ox));
	sort(all(oy));
	map<ll,ll> mpx,mpy;
	rep(i,n+2)mpx[ox[i]]=i;
	rep(i,n+2)mpy[oy[i]]=i;
	vvvvl dp(n+2,vvvl(n+2,vvl(n+2,vl(n+2,-1))));
	function<ll(ll,ll,ll,ll)> rec=[&](ll x1,ll x2,ll y1,ll y2){
		auto &ret=dp[x1][x2][y1][y2];
		if(ret>=0)return ret;
		ret=0;
		vl cdt;
		rep(i,n){
			if(ox[x1]<x[i+1]&&x[i+1]<ox[x2]&&oy[y1]<y[i+1]&&y[i+1]<oy[y2])cdt.push_back(i+1);
		}
		for(auto c:cdt){
			ll scr=(ox[x2]-ox[x1]-1)+(oy[y2]-oy[y1]-1)-1;
			ll nx=mpx[x[c]];
			ll ny=mpy[y[c]];
			if(x1!=nx&&y1!=ny)scr+=rec(x1,nx,y1,ny);
			if(x1!=nx&&y2!=ny)scr+=rec(x1,nx,ny,y2);
			if(x2!=nx&&y1!=ny)scr+=rec(nx,x2,y1,ny);
			if(x2!=nx&&y2!=ny)scr+=rec(nx,x2,ny,y2);
			chmax(ret,scr);
		}
		return ret;
	};
	ll ans=rec(0,n+1,0,n+1);
	puta(ans);
}
