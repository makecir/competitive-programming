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

template<class T=ll>struct Graph{
	int n;
	vector<vector<tuple<ll,T>>>edge;
	Graph(int N=1):n(N){edge.resize(n);}
	void add(ll f,ll t,T c,bool d=false){
		edge[f].emplace_back(t,c);
		if(!d)edge[t].emplace_back(f,c);
	}
	void view(){
		rep(i,n)for(auto&e:edge[i])
			puta(i,"=>",get<0>(e),", cost :",get<1>(e));
	}
};

template<class T=ll>struct Dijkstra:Graph<T>{
	using Graph<T>::Graph;
	Dijkstra(int N=1):Graph<T>::Graph(N){}
	const T mval=numeric_limits<T>::max()/2;
	vector<T>dist(ll s){
		vector<T> ret(this->n,mval);
		priority_queue<tuple<T,ll>> q;
		q.emplace(T(),s);
		while(!q.empty()){
			T c; ll p; tie(c,p)=q.top(); q.pop();
			if(ret[p]!=mval)continue;
			ret[p]=c=-c;
			for(auto&e:this->edge[p]){
				ll nxt;T cost;
				tie(nxt,cost)=e;
				if(ret[nxt]<=ret[p]+cost)continue;
				q.emplace(-ret[p]-cost,nxt);
			}
		}
		return ret;
	}
	T dist(ll s,ll t){return dist(s)[t];}
}; 

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m,a,b,c;
	cin>>n>>m;
	vector<vpll> g(n);
	rep(_,m){
		cin>>c>>a>>b;
		g[a].emplace_back(b,c);
		g[b].emplace_back(a,c);
	}
	vl dist(n,LINF);
	vl ans(n,LINF);
	priority_queue<pll,vpll,greater<pll>> pq;
	pq.emplace(0,0);
	rep(i,n){
		vl next(n,LINF);
		priority_queue<pll,vpll,greater<pll>> pq_next;
		while(!pq.empty()){
			auto x=pq.top();pq.pop();
			if(next[x.sc]!=LINF||dist[x.sc]<x.fs)continue;
			next[x.sc]=x.fs;
			chmin(ans[x.sc],next[x.sc]);
			for(auto y:g[x.sc]){
				if(y.sc==0){
					if(min({dist[y.fs],next[y.fs],ans[y.fs]+n-i})<=next[x.sc]+1)continue;
					pq.emplace(next[x.sc]+1,y.fs);
				}
				else{
					if(min({dist[y.fs],next[y.fs],ans[y.fs]+n-i})<=next[x.sc]+i+1)continue;
					pq_next.emplace(next[x.sc]+i+1,y.fs);
				}
			}
		}
		dist=next;
		pq=pq_next;
	}
	rep(i,n)puta(ans[i]);
}