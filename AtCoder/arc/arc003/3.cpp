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
#define EPS (1e-10)
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
	ll n,m;
	cin>>n>>m;
	pll s,g;
	vvl vv(n+2,vl(m+2,-LINF));
	rep(i,n)rep(j,m){
		char ch;
		cin>>ch;
		if(ch=='s'){
			s.fs=i+1;
			s.sc=j+1;
			vv[i+1][j+1]=LINF;
		}
		else if(ch=='g'){
			g.fs=i+1;
			g.sc=j+1;
			vv[i+1][j+1]=LINF;
		}
		else if(ch=='#'){
			vv[i+1][j+1]=-LINF;
		}
		else{
			vv[i+1][j+1]=ch-'0';
		}
	}
	double ok=-1,ng=10;
	vd mul(m*n);
	mul[0]=1;
	range(i,1,m*n)mul[i]=mul[i-1]*0.99;
	while(ng-ok>EPS){
		double mid=(ok+ng)/2;
		vvl dist(n+2,vl(m+2,LINF));
		
		queue<pll> q;
		q.push(s);
		dist[s.fs][s.sc]=0;
		while(!q.empty()){
			ll cur;
			auto p=q.front();q.pop();
			cur=dist[p.fs][p.sc];
			rep(i,4){
				if(dist[p.fs+dx[i]][p.sc+dy[i]]<=cur+1||vv[p.fs+dx[i]][p.sc+dy[i]]<=0||mid>(vv[p.fs+dx[i]][p.sc+dy[i]]*mul[cur+1]))continue;
				dist[p.fs+dx[i]][p.sc+dy[i]]=cur+1;
				q.push({p.fs+dx[i],p.sc+dy[i]});
			}
		}
		if(dist[g.fs][g.sc]==LINF)ng=mid;
		else ok=mid;
	}
	if(ok==-1)puta(-1);
	else fcout(10)<<ok<<endl;
}
