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
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define range(i,a,n) for(int i=(a);i<(n);i++)

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
struct UnionFind{
    vl par,dist;
    UnionFind(int x){par.assign(x,-1); dist.assign(x,0);}
    ll find(ll x){return par[x]<0?x:find(par[x]);}
    ll depth(ll x){return par[x]<0?0:depth(par[x])+dist[x];}
    bool same(ll x,ll y){return find(x)==find(y);}
    ll size(ll x){return -par[find(x)];}
    ll diff(ll x,ll y){return same(x,y)?depth(x)-depth(y):LINF;}
    void unite(ll x,ll y,ll k=0){
        k+=depth(y); k-=depth(x); k=-k;
        x=find(x); y=find(y);
        if(x==y)return;
        if(size(x)<size(y)){swap(x,y);k=-k;}
        par[x]+=par[y]; par[y]=x; dist[y]=k;
    }
};
struct edge{
	int u,v;
	double cost;
};
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m;
	double ans=INF;
	cin>>n>>m;
	vd x(n),y(n),X(m),Y(m);
	vi z(n),Z(m);
	rep(i,n)cin>>x[i]>>y[i]>>z[i];
	rep(i,m)cin>>X[i]>>Y[i]>>Z[i];
	rep(i,1<<m){
		double score=0;
		vd ux,uy;
		vi uz;
		rep(j,n){
			ux.push_back(x[j]);
			uy.push_back(y[j]);
			uz.push_back(z[j]);
		}
		rep(j,m)if(i&(1<<j)){
			ux.push_back(X[j]);
			uy.push_back(Y[j]);
			uz.push_back(Z[j]);
		}
		ll un=ux.size();
		UnionFind u(un);
		vector<edge> v;
		
		rep(j,un)rep(k,j){
			edge e;
			e.u=j;e.v=k;
			e.cost=(uz[j]==uz[k]?1.0:10.0)*(hypot(fabs(ux[k]-ux[j]),fabs(uy[k]-uy[j])));
			v.push_back(e);
		}
		for(int j=0;j<v.size();j++){
			for(int k=v.size()-1;k>j;k--){
				if(v[k].cost<v[k-1].cost){
					int a,b;double c;
					a=v[k-1].u;b=v[k-1].v;c=v[k-1].cost;
					v[k-1].u=v[k].u;
					v[k-1].v=v[k].v;
					v[k-1].cost=v[k].cost;
					v[k].u=a;v[k].v=b;v[k].cost=c;

				}
			}
		}
		rep(j,v.size()){
			if(!u.same(v[j].u,v[j].v)){
				u.unite(v[j].u,v[j].v);
				score+=v[j].cost;
			}
		}
		chmin(ans,score);
	}
	fcout(8)<<ans<<endl;
}
