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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m,a,b,ans=0,t;
	cin>>n>>m;
	t=n/2;
	vl v(n);
	rep(i,m){
		cin>>a>>b;
		--a;--b;
		v[a]|=(1ll<<b);
		v[b]|=(1ll<<a);
	}
	ll ma=0,mb=0;
	rep(i,n){
		if(i<t) ma|=(1ll<<i);
		else mb|=(1ll<<i);
	}
	vl dp(1ll<<t);
	rep(i,1ll<<t){
		ll cnt=0,con=0;
		rep(j,t)if(i&(1ll<<j)){
			cnt++;
			con|=(v[j]&ma);
			if(con&i){
				cnt=-1;break;
			}
		}
		chmax(dp[i],cnt);
		rep(j,t)if(!(i&(1ll<<j))){
			chmax(dp[i|(1ll<<j)],dp[i]);
		}
	}
	rep(i,1ll<<(n-t)){
		ll cnt=0,con=0,outer=0;
		rep(j,n-t)if(i&(1ll<<j)){
			cnt++;
			con|=(v[j+t]&mb);
			outer|=(v[j+t]&ma);
			if(con&(i<<t)){
				cnt=-1;break;
			}
		}
		if(cnt==-1)continue;
		chmax(ans,dp[outer^ma]+cnt);
		//puta(bitset<9>((i<<t)),cnt,bitset<9>(outer^ma),dp[outer^ma]);
	}
	puta(ans);
}
