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

int h=30,w=30;
int DEBUG=1;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int q_mx=1000;
	vvi h_cost(30,vi(29,5000));
	vvi v_cost(29,vi(30,5000));

	// DEBUG
	vvi h_correct(30,vi(29,5000));
	vvi v_correct(29,vi(30,5000));
	if(DEBUG){
		rep(i,30)rep(j,29)cin>>h_correct[i][j];
		rep(i,29)rep(j,30)cin>>v_correct[i][j];
	}
	
	rep(q,q_mx){

		// input
		int si,sj,ti,tj,ci,cj,ni,nj,cost,mi=0,mj=0,diff=0;
		cin>>si>>sj>>ti>>tj;

		if(DEBUG){
			int a;double e;
			cin>>a>>e;
		}

		// bfs
		vvi dist(30,vi(30,INF));
		dist[si][sj]=0;
		queue<pii> que;
		que.emplace(si,sj);
		while(!que.empty()){
			tie(ci,cj)=que.front();que.pop();
			rep(dir,4){
				ni=ci+dy[dir];nj=cj+dx[dir];
				cost=dist[ci][cj];
				if(ni<0||ni>=30||nj<0||nj>=30)continue;
				auto tar=&h_cost[ci][cj];
				if(dir==0)tar=&h_cost[ci][cj];
				if(dir==1)tar=&v_cost[ci][cj];
				if(dir==2)tar=&h_cost[ci][cj-1];
				if(dir==3)tar=&v_cost[ci-1][cj];
				cost+=(*tar);

				// addit
				if(abs((*tar)-5000)<(200-q))cost-=(200-q)/100;

				if(dist[ni][nj]<=cost)continue;
				dist[ni][nj]=cost;
				que.emplace(ni,nj);
			}
		}

		// restore
		string op;
		string LURD="LURD";
		ci=ti;cj=tj;
		while(ci!=si||cj!=sj){
			rep(dir,4){
				ni=ci+dy[dir];nj=cj+dx[dir];
				cost=dist[ci][cj];
				if(ni<0||ni>=30||nj<0||nj>=30)continue;
				auto tar=&h_cost[ci][cj];
				if(dir==0) tar=&h_cost[ci][cj];
				if(dir==1) tar=&v_cost[ci][cj];
				if(dir==2) tar=&h_cost[ci][cj-1];
				if(dir==3) tar=&v_cost[ci-1][cj];

				cost-=(*tar);

				// addit
				if(abs((*tar)-5000)<(200-q))cost+=(200-q)/100;

				if(dist[ni][nj]==cost){
					op+=LURD[dir];
					ci=ni;cj=nj;
					if(dir%2==0)mj++;
					else mi++;
					break;
				}
			}
		}
		reverse(all(op));

		// input
		int score=0;
		cout<<op<<endl;

		if(DEBUG){
			for(auto d:op){
				int dir;
				auto tar=&h_correct[ci][cj];
				if(d=='R'){dir=0;tar=&h_correct[ci][cj];}
				if(d=='D'){dir=1;tar=&v_correct[ci][cj];}
				if(d=='L'){dir=2;tar=&h_correct[ci][cj-1];}
				if(d=='U'){dir=3;tar=&v_correct[ci-1][cj];}
				ci+=dy[dir];cj+=dx[dir];
				score+=(*tar);
			}
			ci=si;cj=sj;
		}
		else cin>>score;

		// rewrite
		int ave=(score)/sz(op);//+max(0,(q_mx/2-q)/10);
		for(auto d:op){
			int dir;bool ver=true;
			auto tar=&(h_cost[ci][cj]);
			if(d=='R'){dir=0;tar=&h_cost[ci][cj];ver=false;}
			if(d=='D'){dir=1;tar=&v_cost[ci][cj];}
			if(d=='L'){dir=2;tar=&h_cost[ci][cj-1];ver=false;}
			if(d=='U'){dir=3;tar=&v_cost[ci-1][cj];}
			ci+=dy[dir];cj+=dx[dir];
			double nxt=((*tar)*sz(op)+ave*(ver?mi:mj))/(double)(sz(op)+(ver?mi:mj));
			(*tar)=round(nxt);
		}
	}

}
