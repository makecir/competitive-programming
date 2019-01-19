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
#define PI			(3.1415926535897932384)

int dx[]={1,0,-1,0,1,-1,-1,1},dy[]={0,1,0,-1,1,1,-1,-1};
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s; a=0;} return os;}
template<class T> void chmax(T &a, const T &b){if(a<b)a=b;}
template<class T> void chmin(T &a, const T &b){if(a>b)a=b;}
void YN(bool b){cout<<(b?"YES":"NO")<<endl;}
void Yn(bool b){cout<<(b?"Yes":"No")<<endl;}
void yn(bool b){cout<<(b?"yes":"no")<<endl;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,ans=LINF;
	cin>>n;
	vl v(n),sum(n+1),lp(n),rp(n);
	rep(i,n)cin>>v[i],sum[i+1]=sum[i]+v[i];
	int pos=1;
	for(int i=1;i+2<n;i++){
		ll lsum=sum[i+1]-sum[0];
		while(abs((lsum-sum[pos])-sum[pos])>=abs((lsum-sum[pos+1])-sum[pos+1]))pos++;
		lp[i]=pos;
	}
	pos=n-1;
	for(int i=n-2;i>=2;i--){
		ll rsum=sum[n]-sum[i];
		while(abs((sum[n]-sum[pos])-(sum[pos]-sum[i]))>=abs((sum[n]-sum[pos-1])-(sum[pos-1]-sum[i])))pos--;
		rp[i]=pos;
	}
	for(int i=2;i+2<=n;i++){
		ll a=sum[lp[i-1]];
		ll b=sum[i]-a;
		ll c=sum[rp[i]]-(a+b);
		ll d=sum[n]-(a+b+c);
		//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		chmin(ans,max({a,b,c,d})-min({a,b,c,d}));
	}
	cout<<ans<<endl;
}
