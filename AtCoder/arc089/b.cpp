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
	ll n,k;
	cin>>n>>k;
	vl x(n),y(n);
	rep(i,n){
		char c;
		cin>>x[i]>>y[i]>>c;
		if(c=='W')y[i]+=k;
		x[i]%=2*k;
		y[i]%=2*k;
	}
	vvl tb(3*k+1,vl(3*k+1,0));
	rep(i,n){
		tb[x[i]][y[i]]++;
		tb[x[i]+k][y[i]]--;
		tb[x[i]][y[i]+k]--;
		tb[x[i]+k][y[i]+k]++;
	}
	rep(i,3*k+1){
		range(j,1,3*k+1){
			tb[i][j]+=tb[i][j-1];
		}
	}
	range(i,1,3*k+1){
		rep(j,3*k+1){
			tb[i][j]+=tb[i-1][j];
		}
	}
	ll ans=0;
	ll mx=0;
	rep(i,3*k){
		rep(j,3*k){
			if(i>=2*k||j>=2*k)tb[i%(2*k)][j%(2*k)]+=tb[i][j];
		}
	}
	rep(i,2*k){
		rep(j,2*k){
			//ll tmp=0;
			//cout<<i+k-1<<" "<<j+k-1<<" "<<((i+k)%(2*k)+k-1)<<" "<<((j+k)%(2*k)+k-1)<<endl;
			//tmp=tb[i+k-1][j+k-1]+tb[(i+k)%(2*k)+k-1][(j+k)%(2*k)+k-1];
			ans=max(ans,tb[i][j]+tb[(i+k)%(2*k)][(j+k)%(2*k)]);
		}
	}
	cout<<ans<<endl;
	rep(i,3*k+1){
		rep(j,3*k+1){
			//cout<<tb[i][j]<<" ";
		}
		//cout<<endl;
	}
}
