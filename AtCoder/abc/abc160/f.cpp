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
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s;a=0;} return os;}

vvl e(200005);
vl dp(200005);
vl nd(200005);
ll n;
vl fact,finv;
ll modpw(ll x,ll k){
	ll res=1;
	while(k!=0){
		if(k&1)res=res*x%MOD;
		x=x*x%MOD;
		k=k>>1;
	}
	return res;
}

ll comb(ll n,ll k) {
	if(n==0&&k==0)return 1;
	if(n<k||n<0)return 0;
	return fact[n]*finv[n-k]%MOD*finv[k]%MOD;
}

struct ferm{
	ferm(ll n){
		fact.resize(n);
		finv.resize(n);
		fact[0]=1;
		finv[0]=1;
		rep(i,n-1){
			fact[i+1]=(fact[i]*(i+1))%MOD;
			finv[i+1]=modpw(fact[i+1],MOD-2);
		}
	}
};
void dfs1(ll cur,ll pre){
	nd[cur]=0;
	dp[cur]=1;
	for(auto x:e[cur]){
		if(pre==x)continue;
		dfs1(x,cur);
		(dp[cur]*=dp[x])%=MOD;
		(dp[cur]*=comb(nd[cur]+nd[x],nd[x]))%=MOD;
		nd[cur]+=nd[x];
	}
	nd[cur]++;
}
void dfs2(ll cur,ll pre,ll bt){
	(dp[cur]*=bt)%=MOD;
	(dp[cur]*=comb(n-1,nd[cur]-1))%=MOD;
	for(auto x:e[cur]){
		if(pre==x)continue;
		bt=(dp[cur]*modpw((comb(n-1,nd[x])*dp[x])%MOD,MOD-2))%MOD;
		dfs2(x,cur,bt);
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	ferm(200005);
	ll a,b;
	rep(i,n-1){
		cin>>a>>b;a--;b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs1(0,0);
	dfs2(0,0,1);
	rep(i,n)puta(dp[i]);
}
