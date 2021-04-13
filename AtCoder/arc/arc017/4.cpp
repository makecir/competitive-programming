#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
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

ll op(ll a, ll b) {
	return gcd(abs(a), abs(b));
}

ll e() {
	return ll(0);
}

struct S {
	ll val;
	int size;
};

using F = ll;

S opl(S l, S r) { return S{l.val + r.val, l.size + r.size}; }

S el() { return S{0, 0}; }

S mapping(F l, S r) { 
	return {r.val + r.size * l,r.size};
}

F composition(F l, F r) { return l+r; }

F id() { return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m,t,l,r;
	cin>>n;
	vl a(n);
	lazy_segtree<S,opl,el,F,mapping,composition,id> lseg(n);
	segtree<ll,op,e> seg(n-1);
	rep(i,n)cin>>a[i];
	rep(i,n){
		lseg.set(i,{a[i],1});
		if(i!=0)seg.set(i-1,a[i]-a[i-1]);
	}
	cin>>m;
	rep(i,m){
		cin>>t>>l>>r;
		l--;r--;
		if(t==0){
			ll ans=gcd(lseg.get(l).val,seg.prod(l,r));
			puta(ans);
		}
		else{
			lseg.apply(l,r+1,t);
			if(l!=0)seg.set(l-1,lseg.get(l).val-lseg.get(l-1).val);
			if(r!=n-1)seg.set(r,lseg.get(r+1).val-lseg.get(r).val);
		}
	}
}
