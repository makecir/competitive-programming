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
int bsr(int x) { return 31 - __builtin_clz(x); }
int bsr(ll x) { return 63 - __builtin_clzll(x); }
int bsf(int x) { return __builtin_ctz(x); }
int bsf(ll x) { return __builtin_ctzll(x); }

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
	ll s=0;
	vl v(n),sum(n+1),val;
	rep(i,n){
		cin>>v[i];
		s+=v[i];
		sum[i+1]=s;
	}
	rep(i,n+1){
		rep(j,i){
			val.push_back(sum[i]-sum[j]);
		}
	}
	ll ans=0;
	vb b(val.size(),true);
	rep(i,41){
		int d=40-i;
		int cnt=0;
		ll tmp=(1ll<<d);
		rep(j,val.size()){
			if(b[j]&&((val[j]&tmp)==tmp)){
				cnt++;
			}
		}
		if(cnt>=k){
			rep(j,val.size()){
				if(b[j]&&((val[j]&tmp)==0)){
					b[j]=false;
				}
			}
			ans|=tmp;
		}
	}
	cout<<ans<<endl;
}