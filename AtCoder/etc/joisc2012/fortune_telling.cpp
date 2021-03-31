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
struct S{
	ll value;
	ll size;
};
using F = bool;
S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ 
	if(f) x.value = x.size-x.value;
	return x;
}
F composition(F f, F g){ return f^g; }
F id(){ return 0; }
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m,k,szx=0,szy=0,ans=0;
	cin>>m>>n>>k;
	vi a(k),b(k),c(k),d(k);
	map<int,int> mpx,mpy;
	mpx[1]=0;mpx[n+1]=0;
	mpy[1]=0;mpy[m+1]=0;
	rep(i,k){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
		b[i]++;d[i]++;
		mpy[a[i]]=0;
		mpy[b[i]]=0;
		mpx[c[i]]=0;
		mpx[d[i]]=0;
	}
	for(auto &x:mpx){
		x.sc=szx;
		szx++;
	}
	for(auto &x:mpy){
		x.sc=szy;
		szy++;
	}
	int mn=1;
	vector<S> v;
	for(auto x:mpx){
		if(x.fs==1)continue;
		v.push_back({x.fs-mn,x.fs-mn});
		mn=x.fs;
	}
	v.push_back({0,0});
	lazy_segtree<S,op,e,F,mapping,composition,id> seg(v);
	vector<vector<pii>> od(szy);
	rep(i,k){
		od[mpy[a[i]]].push_back({mpx[c[i]],mpx[d[i]]});
		od[mpy[b[i]]].push_back({mpx[c[i]],mpx[d[i]]});
	}
	mn=1;
	for(auto x:mpy){
		ans+=(ll)(x.fs-mn)*seg.all_prod().value;
		mn=x.fs;
		for(auto y:od[x.sc]){
			seg.apply(y.fs,y.sc,true);
		}
		// puta(x,ans);
		// rep(i,szx)cout<<seg.get(i).value<<" ";
		// puta("");
		// return 0;
	}
	puta(ans);
}
