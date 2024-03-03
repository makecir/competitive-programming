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

bool isPrime(ll n){
	if(n==1)return false;
	for(ll i=2;i*i<=n;i++)if(n%i==0)return false;
	return true;
}
vl primeFactorVec(ll n) {
	vl ret;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){ret.push_back(i);while(n%i==0){n/=i;}};
	}
	if(n>1) ret.push_back(n);
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll l,r;
	cin>>l>>r;
	vvl pls(r+1);
	range(i,2,r+1)pls[i]=primeFactorVec(i);
	ll ans=0;
	ll tmp=0;
	range(i,2,r/2+1){
		ll a=max(2,(l-1)/i+1);
		ll b=max(2,(r)/i+1);
		ll cnt=b-a;
		ll scr=cnt*(cnt-1)/2;
		for(ll j=a;j<b;j++){
			ll sub=0;
			vb used(b-a);
			for(auto x:pls[j]){
				for(ll k=j+x;k<b;k+=x){
					if(!used[k-a]){
						used[k-a]=true;
						sub++;
					}
				}
			}
			scr-=sub;
		}
		scr*=2;
		ans+=scr;
		tmp+=(b-a);
		puta(i,a,b,cnt);
		//ans+=cnt*(cnt-1);
	}
	puta(tmp);
	puta(ans);
}
