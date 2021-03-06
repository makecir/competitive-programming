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
	ll n,k,mxw=0,ans=0;
	cin>>n>>k;
	vl v(n),w(n);
	rep(i,n)cin>>v[i]>>w[i],chmax(mxw,w[i]);
	if(n<=30){ //case1
		vector<pll> a,b,c;
		rep(i,n){
			if(i%2==0)a.push_back(pll(v[i],w[i]));
			else b.push_back(pll(v[i],w[i]));
		}
		rep(i,1<<b.size()){
			pll p;
			rep(j,b.size())if(i&(1<<j)){p.fs+=b[j].sc;p.sc+=b[j].fs;}
			c.push_back(p);
		}
		sort(all(c));
		range(i,1,c.size())chmax(c[i].sc,c[i-1].sc);
		rep(i,1<<a.size()){
			pll p;
			rep(j,a.size())if(i&(1<<j)){p.fs+=a[j].sc;p.sc+=a[j].fs;}
			ll rem=k-p.fs;
			if(rem<0)continue;
			chmax(ans,p.sc+(*(--upper_bound(all(c),pll(rem,LINF)))).sc);
		}
	}
	else if(mxw<=1000){ //case2
		vl dp(mxw*n+1);
		rep(i,n)rrep(j,mxw*n+1){
			if(j+w[i]>mxw*n)continue;
			chmax(dp[j+w[i]],dp[j]+v[i]);
		}
		ans=dp[min(k,mxw*n)];
	}
	else{
		vl dp(1000*n+1,LINF);
		dp[0]=0;
		rep(i,n)rrep(j,1000*n+1){
			if(j+v[i]>1000*n+1)continue;
			chmin(dp[j+v[i]],dp[j]+w[i]);
		}
		rep(i,1000*n+1)if(dp[i]<=k)chmax(ans,i);
	}
	puta(ans);
}
