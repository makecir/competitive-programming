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

double dp[2][70][50][40];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,d;
	cin>>n>>d;
	int tw=0,th=0,fi=0;
	while(d%2==0){d/=2;tw++;}
	while(d%3==0){d/=3;th++;}
	while(d%5==0){d/=5;fi++;}
	if(d!=1){
		cout<<0<<endl;
		return 0;
	}
	bool pn=false;
	dp[0][0][0][0]=1.0;
	rep(i,n){
		pn=!pn;
		rep(j,70) rep(k,50) rep(l,40) dp[pn][j][k][l]=0;
		rep(j,70){
			rep(k,50){
				rep(l,40){
					if(dp[!pn][j][k][l]==0)continue;
					dp[pn][j][k][l]+=dp[!pn][j][k][l]/6.0;
					dp[pn][min(j+1,tw)][k][l]+=dp[!pn][j][k][l]/6.0;
					dp[pn][j][min(k+1,th)][l]+=dp[!pn][j][k][l]/6.0;
					dp[pn][min(j+2,tw)][k][l]+=dp[!pn][j][k][l]/6.0;
					dp[pn][j][k][min(l+1,fi)]+=dp[!pn][j][k][l]/6.0;
					dp[pn][min(j+1,tw)][min(k+1,th)][l]+=dp[!pn][j][k][l]/6.0;
				}
			}
		}
	}
	fcout(8);
	cout<<dp[pn][tw][th][fi]<<endl;
}