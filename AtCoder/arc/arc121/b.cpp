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
	ll n;
	cin>>n;
	vvl v(3);
	rep(i,n*2){
		ll a,tar=0;
		char c;
		cin>>a>>c;
		if(c=='R')tar=0;
		else if(c=='G')tar=1;
		else tar=2;
		v[tar].push_back(a);
	}
	bool od=false;
	set<ll> x,y,z;
	vl zv;
	vb used(3);
	rep(i,3){
		if(sz(v[i])%2!=0){
			used[i]=true;
			if(od){
				for(auto t:v[i])y.insert(t);
			}
			else{
				od=true;
				for(auto t:v[i])x.insert(t);
			}
		}
	}
	ll ans=0;
	if(od){
		rep(i,3){
			if(!used[i])for(auto t:v[i])zv.push_back(t);
		}
		sort(all(zv));
		ans=LINF;
		for(auto t:x){
			auto itr=y.upper_bound(t);
			if(itr!=y.end())chmin(ans,abs(t-*itr));
			if(itr!=y.begin())chmin(ans,abs(t-*(--itr)));
		}
		if(sz(zv)!=0){
			set<pll> aa,bb;
			for(auto t:x){
				auto itr=upper_bound(all(zv),t);
				if(itr!=zv.end())aa.insert({abs(t-*itr),(itr-zv.begin())});
				if(itr!=zv.begin())aa.insert({abs(t-*(--itr)),itr-zv.begin()});
			}
			for(auto t:y){
				auto itr=upper_bound(all(zv),t);
				if(itr!=zv.end())bb.insert({abs(t-*itr),itr-zv.begin()});
				if(itr!=zv.begin())bb.insert({abs(t-*(--itr)),itr-zv.begin()});
			}
			auto ita=aa.begin();
			auto itb=bb.begin();
			auto itc=ita;
			auto itd=itb;
			if((*ita).sc!=(*itb).sc)chmin(ans,(*ita).fs+(*itb).fs);
			else if(sz(aa)!=1)chmin(ans,((*++itc).fs+(*itb).fs));
			else if(sz(bb)!=1)chmin(ans,((*ita).fs+(*++itd).fs));
		}
	}
	puta(ans);



}
