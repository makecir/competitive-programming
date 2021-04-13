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

struct S {
	ld val;
	int size;
};

using F = ld;
const F ID = 1E300;

S op(S l, S r) { return S{l.val + r.val, l.size + r.size}; }

S e() { return S{0, 0}; }

S mapping(F l, S r) { 
	if(l != ID) r.val = r.size * l;
	return S{r}; 
}

F composition(F l, F r) { return F{(l == ID ? r : l)}; }

F id() { return ID; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,que,t;
	cin>>n;
	ll MX=1E6*2;
	vector<S> initv(MX+1,{0,1});
	lazy_segtree<S,op,e,F,mapping,composition,id> lg(initv);
	rep(i,MX)lg.set(i+1,{log(i+1),1});
	vector<S> v(n-1,{0,1});
	lazy_segtree<S,op,e,F,mapping,composition,id> seg(v);
	vl p(n),q(n);
	rep(i,n)cin>>p[i]>>q[i];
	rep(i,n-1){
		ll x,y;
		x=p[i+1]-p[i];
		y=q[i+1]-q[i];
		seg.set(i,{lg.prod(y+1,x+y+1).val-lg.prod(1,x+1).val,1});
	}
	cin>>que;
	while(que--){
		cin>>t;
		if(t==2){
			ll a,b,c,d;
			cin>>a>>b>>c>>d;
			ld l=seg.prod(--a,--b).val;
			ld r=seg.prod(--c,--d).val;
			string ans=(l>r?"FIRST":"SECOND");
			puta(ans);
		}
		else{
			ll tar,a,b,x,y;
			cin>>tar>>a>>b;
			tar--;
			p[tar]=a;
			q[tar]=b;
			if(tar!=0){
				x=p[tar]-p[tar-1];
				y=q[tar]-q[tar-1];
				seg.set(tar-1,{lg.prod(y+1,x+y+1).val-lg.prod(1,x+1).val,1});
			}
			if(tar!=n-1){
				x=p[tar+1]-p[tar];
				y=q[tar+1]-q[tar];
				seg.set(tar,{lg.prod(y+1,x+y+1).val-lg.prod(1,x+1).val,1});
			}
		}
	}
}
