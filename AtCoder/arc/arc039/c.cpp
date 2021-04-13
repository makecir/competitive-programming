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
#define sz(x) (int)(x).size()

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

ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}
template<class T>void puta(T&&t){cout<<t<<"\n";}
template<class H,class...T>void puta(H&&h,T&&...t){cout<<h<<' ';puta(t...);}
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;}
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s;a=0;} return os;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll k;
	string s;
	cin>>k>>s;
	ll TAB=200000;
	vector<set<pll>> stx(TAB*2+1),sty(TAB*2+1);
	stx[TAB].insert(pll(-2*k,-1));
	stx[TAB].insert(pll(1,2*k));
	sty[TAB].insert(pll(-2*k,-1));
	sty[TAB].insert(pll(1,2*k));
	rep(i,TAB*2+1)if(i!=TAB)stx[i].insert(pll(-2*k,2*k));
	rep(i,TAB*2+1)if(i!=TAB)sty[i].insert(pll(-2*k,2*k));
	ll x=0,y=0;
	rep(i,k){
		if(s[i]=='R'){
			auto itr=sty[y+TAB].upper_bound(pll(x,LINF));
			x=(*itr).fs;
			auto p=*itr;
			sty[y+TAB].erase(itr);
			if(x!=p.sc)sty[y+TAB].insert(pll(x+1,p.sc));
			itr=stx[x+TAB].upper_bound(pll(y,LINF));
			itr--;
			p=*itr;
			if(p.sc>=y){
				if(p.fs!=y)stx[x+TAB].insert(pll(p.fs,y-1));
				if(p.sc>y)stx[x+TAB].insert(pll(y+1,p.sc));
				stx[x+TAB].erase(itr);
			}
		}
		if(s[i]=='L'){
			auto itr=sty[y+TAB].upper_bound(pll(x,LINF));
			itr--;
			x=(*itr).sc;
			auto p=*itr;
			sty[y+TAB].erase(itr);
			if(x!=p.fs)sty[y+TAB].insert(pll(p.fs,x-1));
			itr=stx[x+TAB].upper_bound(pll(y,LINF));
			itr--;
			p=*itr;
			if(p.sc>=y){
				if(p.fs!=y)stx[x+TAB].insert(pll(p.fs,y-1));
				if(p.sc>y)stx[x+TAB].insert(pll(y+1,p.sc));
				stx[x+TAB].erase(itr);
			}
		}
		if(s[i]=='U'){
			auto itr=stx[x+TAB].upper_bound(pll(y,LINF));
			y=(*itr).fs;
			auto p=*itr;
			stx[x+TAB].erase(itr);
			if(y!=p.sc)stx[x+TAB].insert(pll(y+1,p.sc));
			itr=sty[y+TAB].upper_bound(pll(x,LINF));
			itr--;
			p=*itr;
			if(p.sc>=x){
				if(p.fs!=x)sty[y+TAB].insert(pll(p.fs,x-1));
				if(p.sc>x)sty[y+TAB].insert(pll(x+1,p.sc));
				sty[y+TAB].erase(itr);
			}
		}
		if(s[i]=='D'){
			auto itr=stx[x+TAB].upper_bound(pll(y,LINF));
			itr--;
			y=(*itr).sc;
			auto p=*itr;
			stx[x+TAB].erase(itr);
			if(y!=p.fs)stx[x+TAB].insert(pll(p.fs,y-1));
			itr=sty[y+TAB].upper_bound(pll(x,LINF));
			itr--;
			p=*itr;
			if(p.sc>=x){
				if(p.fs!=x)sty[y+TAB].insert(pll(p.fs,x-1));
				if(p.sc>x)sty[y+TAB].insert(pll(x+1,p.sc));
				sty[y+TAB].erase(itr);
			}
		}
	}
	puta(x,y);
}
