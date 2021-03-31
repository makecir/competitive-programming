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
	ll h,w;
	cin>>h>>w;
	vvb bd(h,vb(w));
	rep(i,h)rep(j,w){
		char ch;
		cin>>ch;
		bd[i][j]=ch=='#';
	}
	vvl dp(h,vl(w));
	vvl a(h,vl(w)),b(h,vl(w)),c(h,vl(w));
	dp[0][0]=1;
	a[0][0]=1;
	b[0][0]=1;
	c[0][0]=1;
	rep(i,h){
		rep(j,w){
			if(bd[i][j])continue;
			if(i!=0&&(!bd[i-1][j]))dp[i][j]+=a[i-1][j];
			if(j!=0&&(!bd[i][j-1]))dp[i][j]+=b[i][j-1];
			if(i!=0&&j!=0&&(!bd[i-1][j-1]))dp[i][j]+=c[i-1][j-1];
			dp[i][j]%=MOD;
			a[i][j]=b[i][j]=c[i][j]=dp[i][j];
			if(i!=0)a[i][j]=(a[i-1][j]+a[i][j])%MOD;
			if(j!=0)b[i][j]=(b[i][j-1]+b[i][j])%MOD;
			if(i!=0&&j!=0)c[i][j]=(c[i-1][j-1]+c[i][j])%MOD;
		}
	}
	puta(dp[h-1][w-1]);
}
