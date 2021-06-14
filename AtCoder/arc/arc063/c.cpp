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
#define sz(x) (int)(x).size()

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
	ll n,k,a,b;
	cin>>n;
	vvl g(n);
	vl ans(n,-1);
	vpll rng(n,{-LINF,-LINF});
	pll EMP={-LINF,-LINF};
	bool sat=true;
	rep(i,n-1){
		cin>>a>>b;
		--a;--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cin>>k;
	rep(i,k){
		cin>>a>>b;
		--a;b+=INF;
		rng[a]={b,b};
	}
	function<pll(ll,ll)>rec1=[&](ll cur,ll prev){
		pll &ret=rng[cur];
		for(auto x:g[cur]){
			if(x==prev)continue;
			auto tmp=rec1(x,cur);
			if(tmp==EMP)continue;
			else if(ret==EMP){
				tmp.fs--;tmp.sc++;
				ret=tmp;
			}
			else{
				tmp.fs--;tmp.sc++;
				if((ret.fs%2!=tmp.fs%2)||(ret.fs>tmp.sc)||(ret.sc<tmp.fs))sat=false;
				else{
					chmax(ret.fs,tmp.fs);
					chmin(ret.sc,tmp.sc);
				}
			}
		}
		return ret;
	};
	rec1(0,-1);
	if(!sat){
		puta("No");
	}
	else{
		function<void(ll,ll)>rec2=[&](ll cur,ll prev){
			if(prev==-1)ans[cur]=rng[cur].fs;
			else if(rng[cur]==EMP)ans[cur]=ans[prev]+1;
			else if(rng[cur].fs<=ans[prev]-1)ans[cur]=ans[prev]-1;
			else ans[cur]=ans[prev]+1;
			for(auto x:g[cur]){
				if(x==prev)continue;
				rec2(x,cur);
			}
		};
		rec2(0,-1);
		puta("Yes");
		for(auto x:ans)puta(x-INF);
	}
}
