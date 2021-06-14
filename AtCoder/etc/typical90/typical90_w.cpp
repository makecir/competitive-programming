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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll h,w;
	cin>>h>>w;
	vvb vv(h,vb(w));
	rep(i,h)rep(j,w){
		char ch;
		cin>>ch;
		vv[i][j]=(ch=='.');
	}
	vector<map<int,int>> mp(w),rev(w);
	vvb used(5,vb(w+2));
	vl cnt(w);
	function<void(int,int,int,int,int)> rec=[&](int div,int bit,int pi,int pj,int pv){
		if(div==w+1){
			//puta(bitset<4>(bit),cnt[pv]);
			//rep(i,5)puta(used[i]);
			mp[pv][bit]=cnt[pv];
			rev[pv][cnt[pv]++]=bit;
		}
		else{
			int ni=pi,nj=pj-1;
			if(nj==0){nj=w;ni--;}
			rec(div+1,bit,ni,nj,pv);
			bool check=true;
			rep(k,8)check&=(!used[ni+dy[k]][nj+dx[k]]);
			if(check){
				//puta(bitset<4>(bit),cnt[pv],ni,nj);
				//rep(i,5)puta(used[i]);
				used[ni][nj]=true;
				rec(div+1,bit|(1<<(div)),ni,nj,pv);
				used[ni][nj]=false;
			}
		}
	};
	rep(j,w)rec(0,0,3,j+1,j);
	vvl nxt0(w),nxt1(w);
	rep(j,w){
		nxt0[j].resize(cnt[j]);
		nxt1[j].resize(cnt[j],-1);
	}
	rep(j,w){
		rep(k,cnt[j]){
			int prev=rev[j][k];
			int msk=(1<<(w+1))-1;
			nxt0[j][k]=mp[(j+1)%w][(prev<<1)&msk];
			bool ok=true;
			if(j!=0&&w!=1)ok&=!(prev&(1<<0));
			if(j!=w-1)ok&=!(prev&(1<<(w-2)));
			ok&=!(prev&(1<<(w-1)));
			if(j!=0&&w!=1)ok&=!(prev&(1<<w));
			if(ok)nxt1[j][k]=mp[(j+1)%w][((prev<<1)|1)&msk];
		}
	}
	vector<vvl> dp(h+1,vvl(w));
	rep(i,h+1)rep(j,w)dp[i][j].resize(cnt[j]);
	dp[0][0][0]=1;
	rep(i,h)rep(j,w)rep(k,cnt[j]){
		int ni=i,nj=j+1;
		if(nj==w){ni=i+1;nj=0;}
		dp[ni][nj][nxt0[j][k]]+=dp[i][j][k];
		dp[ni][nj][nxt0[j][k]]%=MOD;
		if(vv[i][j]&&nxt1[j][k]!=-1){
			dp[ni][nj][nxt1[j][k]]+=dp[i][j][k];
			dp[ni][nj][nxt1[j][k]]%=MOD;
		}
	}
	ll ans=0;
	rep(k,cnt[0]){
		ans+=dp[h][0][k];
		ans%=MOD;
	}
	puta(ans);
}
