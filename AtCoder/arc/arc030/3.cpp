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
	ll n,m,k;
	cin>>n>>m>>k;
	vector<char> c(n);
	vl a(m),b(m);
	scc_graph g(n);
	rep(i,n)cin>>c[i];
	rep(i,m){
		cin>>a[i]>>b[i];
		g.add_edge(--a[i],--b[i]);
	}
	auto v=g.scc();
	ll sz=v.size();
	map<ll,ll> mp;
	rep(i,sz)for(auto x:v[i])mp[x]=i;
	vector<set<ll>> rev(sz);
	rep(i,m)if(mp[a[i]]!=mp[b[i]])rev[mp[b[i]]].insert(mp[a[i]]+1);
	vector<vs> dp(sz+1,vs(n+1));
	string tmp(k+1,'z'),ans(k+1,'z');
	rep(i,sz+1)rep(j,k+1)if(i!=0||j!=0)dp[i][j]=tmp;
	rep(i,sz){
		string cur;
		for(auto x:v[i])cur+=c[x];
		sort(all(cur));
		rev[i].insert(0);
		for(auto x:rev[i]){
			rep(j,sz(cur)+1){
				rep(l,k+1){
					if(l+j>k)continue;
					chmin(dp[i+1][l+j],dp[x][l]+cur.substr(0,j));
				}
			}
		}
		chmin(ans,dp[i+1][k]);
	}
	if(ans==tmp)puta(-1);
	else puta(ans);
}
