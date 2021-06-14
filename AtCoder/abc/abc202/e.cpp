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
	int n;
	cin>>n;
	vvl g(n);
	vector<vector<unordered_set<int>>> mpv(n,vector<unordered_set<int>>(19));
	rep(i,n-1){
		int a,b;
		cin>>a;
		--a;
		b=i+1;
		g[a].push_back(b);
		g[b].push_back(a);
		mpv[a][0].insert(b);
	}
	vi dist(n,INF);
	function<void(int,int)> rec=[&](int cur,int d){
		for(auto x:g[cur]){
			if(dist[x]<=d)continue;
			dist[x]=d;
			rec(x,d+1);
		}
	};
	dist[0]=0;
	rec(0,1);

	rep(k,18){
		rep(i,n){
			for(auto x:mpv[i][k]){
				for(auto y:mpv[x][k]){
					mpv[i][k+1].insert(y);
				}
			}
		}
	}
	// rep(k,3){
	// 	puta(k);
	// 	rep(i,n){
	// 		cout<<i+1<<" : ";
	// 		for(auto x:mpv[i][k])cout<<x+1<<' ';
	// 		cout<<endl;
	// 	}
	// }

	int q;
	cin>>q;
	while(q--){
		ll u,d,ans=0;
		cin>>u>>d;
		unordered_set<int> cdt;
		u--;
		ll r=d-dist[u];
		if(r<0)ans=0;
		else if(r==0)ans=1;
		else{

			cdt.insert(u);
			//puta(u+1,r);
			rrep(k,19){
				if((1<<k)<=r){
					if(r==(1<<k)){
						for(auto x:cdt)ans+=sz(mpv[x][k]);
					}
					else{
						unordered_set<int> nxt;
						for(auto x:cdt)for(auto y:mpv[x][k])nxt.insert(y);
						cdt=nxt;
					}
					r-=(1<<k);
				}
			}
			//ans=cdt.size();
		}
		puta(ans);
	}
}
