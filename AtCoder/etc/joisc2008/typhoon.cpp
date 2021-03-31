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
	int value;
	int size;
};
using F = int;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.value + f*x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0ll; }
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,m,k,sz=0;
	cin>>n>>m>>k;
	vi a(n),b(n),p(m),q(m),r(m);
	map<int,int> mp;
	map<pii,int> memo;
	rep(i,n){
		cin>>a[i]>>b[i];
		mp[a[i]]=0;
		mp[b[i]]=0;
	}
	rep(i,m){
		cin>>p[i]>>q[i]>>r[i];
		q[i]--;
		mp[p[i]]=0;
	}
	for(auto &x:mp){
		x.sc=sz;
		sz++;
	}
	vvi vv(n+1);
	rep(i,m){
		vv[q[i]].push_back(mp[p[i]]);
		vv[r[i]].push_back(mp[p[i]]);
	}
	vector<S> v(sz,{0,1});
	lazy_segtree<S,op,e,F,mapping,composition,id> seg(v);
	rep(i,n){
		seg.apply(mp[a[i]],mp[b[i]]+1,1);
		for(auto x:vv[i+1]){
			memo[{i+1,x}]=seg.get(x).value;
		}
	}
	rep(i,m){
		ll ans=memo[{r[i],mp[p[i]]}]-memo[{q[i],mp[p[i]]}];
		puta(ans);
	}
}