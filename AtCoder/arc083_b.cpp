#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vb=vector<bool>;
using vvb=vector<vb>;
using vd=vector<double>;
using vvd=vector<vd>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pll=pair<ll,ll>;
using tll=tuple<ll,ll>;
using vs=vector<string>;
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n) range(i,0,n)
#define range(i,a,n) for(int i=(a);i<(n);i++)

#define LINF    	((ll)1ll<<60)
#define INF     	((int)1<<30)
#define EPS     	(1e-9)
#define MOD     	(1000000007ll)
#define fcout(a)	cout<<setprecision(a)<<fixed
#define fs 			first
#define sc			second
#define PI			3.1415926535897932384

int dx[]={1,0,-1,0,1,-1,-1,1},dy[]={0,1,0,-1,1,1,-1,-1};
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s; a=0;} return os;}
void OUT(bool b){cout<<(b?"YES":"NO")<<endl;}
void Out(bool b){cout<<(b?"Yes":"No")<<endl;}
void out(bool b){cout<<(b?"yes":"no")<<endl;}
int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int clz(int x) { return 31 - __builtin_clz(x); }
int clz(ll x) { return 63 - __builtin_clzll(x); }
int ctz(int x) { return __builtin_ctz(x); }
int ctz(ll x) { return __builtin_ctzll(x); }

class compare {
public:
	bool operator()(tuple<ll, ll> a, tuple<ll, ll> b) {
		return (get<1>(a) > get<1>(b));
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,in;
	cin>>n;
	vvl vv(n,vl(n)),nvv(n,vl(n));
	ll ans=0;
	rep(i,n)rep(j,n){
		cin>>vv[i][j];
		nvv[i][j] =vv[i][j];
		ans+=nvv[i][j];
	}
	rep(i,n){
		rep(j,n){
			bool sw=true;
			rep(k,n){
				if(sw&&(i!=k)&&(j!=k)&&nvv[i][j]==vv[i][k]+nvv[k][j]){
					ans-=nvv[i][j];
					sw=false;
				}
				nvv[i][j]=min(nvv[i][j],nvv[i][k]+nvv[k][j]);
			}
		}
	}
	bool ok=true;
	rep(i,n)rep(j,n){
		if(vv[i][j]!=nvv[i][j])ok=false;
	}
	if(ok){
		cout<<ans/2<<endl;
	}
	else{
		cout<<-1<<endl;
	}
}
