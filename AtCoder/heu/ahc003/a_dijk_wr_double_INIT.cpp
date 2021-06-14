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
int SEP=400;

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
		int si,sj,ti,tj,ci,cj,ni,nj,cur,cost,mi=0,mj=0,diff=0;
		pii p;
		cin>>si>>sj>>ti>>tj;

		if(DEBUG){
			int a;double e;
			cin>>a>>e;
		}

		// geta
		int di=abs(si-ti),dj=abs(sj-tj);
		int gt=50;
		if(di>dj)	rep(i,30)rep(j,29) h_cost[i][j]-=gt*(di-dj);
		else		rep(i,29)rep(j,30) v_cost[i][j]-=gt*(dj-di);

		// dijkstra
		vvi dist(30,vi(30,INF));
		priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> que;
		que.push({0,{si,sj}});
		while(!que.empty()){
			tie(cur,p)=que.top();que.pop();
			tie(ci,cj)=p;
			if(dist[ci][cj]!=INF)continue;
			dist[ci][cj]=cur;
			if(ci==ti&&cj==tj)break;
			rep(dir,4){
				ni=ci+dy[dir];nj=cj+dx[dir];
				cost=cur;
				if(ni<0||ni>=30||nj<0||nj>=30)continue;
				auto tar=&h_cost[ci][cj];
				if(dir==0)tar=&h_cost[ci][cj];
				if(dir==1)tar=&v_cost[ci][cj];
				if(dir==2)tar=&h_cost[ci][cj-1];
				if(dir==3)tar=&v_cost[ci-1][cj];
				cost+=(*tar);

				// addit
				if(q<SEP&&abs((*tar)-5000-q)<(SEP-q)*3)cost-=(SEP-q)*2;

				if(dist[ni][nj]<=cost)continue;
				que.emplace(cost,pii(ni,nj));

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
				if(dir==0)tar=&h_cost[ci][cj];
				if(dir==1)tar=&v_cost[ci][cj];
				if(dir==2)tar=&h_cost[ci][cj-1];
				if(dir==3)tar=&v_cost[ci-1][cj];

				cost-=(*tar);

				// addit
				if(q<SEP&&abs((*tar)-5000-q)<(SEP-q)*3)cost+=(SEP-q)*2;


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

		// geta f
		if(di>dj)	rep(i,30)rep(j,29) h_cost[i][j]+=gt*(di-dj);
		else		rep(i,29)rep(j,30) v_cost[i][j]+=gt*(dj-di);

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
		int ave=(score)/sz(op);

		vvl h_cnt(30);
		vvl v_cnt(30);
		vvb h_change(30,vb(29,false));
		vvb v_change(29,vb(30,false));

		for(auto d:op){
			int dir;bool ver=true;
			auto tar=&(h_cost[ci][cj]);
			if(d=='R'){dir=0;	tar=&h_cost[ci][cj];	h_change[ci][cj]=true;		h_cnt[ci]++;	ver=false;}
			if(d=='D'){dir=1;	tar=&v_cost[ci][cj];	v_change[ci][cj]=true;		v_cnt[cj]++;	}
			if(d=='L'){dir=2;	tar=&h_cost[ci][cj-1];	h_change[ci][cj-1]=true;	h_cnt[ci]++;	ver=false;}
			if(d=='U'){dir=3;	tar=&v_cost[ci-1][cj];	v_change[ci-1][cj]=true;	v_cnt[cj]++;	}
			double stab=abs((ver?cj:ci)-14.5);
			double mult=(ver?mi:mj)*((14.5+stab*stab/14.5)/14.5)*1.0;
			if(*tar<ave)mult*=2;
			double nxt=((*tar)*sz(op)+ave*mult)/(double)(sz(op)+mult);
			(*tar)=round(nxt);
			ci+=dy[dir];cj+=dx[dir];
		}

		rep(i,30)rep(j,29){
			if(h_change[i][j]||h_cnt[i]==0)continue;
			auto tar=&h_cost[i][j];
			double stab=abs((i)-14.5);
			double mult=(mj)*((14.5+stab*stab/14.5)/14.5)*1.0*(h_cnt[i]/29.0);
			if(*tar<ave)mult*=2;
			double nxt=((*tar)*sz(op)+ave*mult)/(double)(sz(op)+mult);
			(*tar)=round(nxt);
		}
		rep(i,29)rep(j,30){
			if(v_change[i][j]||v_cnt[j]==0)continue;
			auto tar=&v_cost[i][j];
			double stab=abs((j)-14.5);
			double mult=(mi)*((14.5+stab*stab/14.5)/14.5)*1.0*(v_cnt[j]/29.0);
			if(*tar<ave)mult*=2;
			double nxt=((*tar)*sz(op)+ave*mult)/(double)(sz(op)+mult);
			(*tar)=round(nxt);
		}

		rep(i,30)rep(j,29)h_cost[i][j]++;
		rep(i,29)rep(j,30)v_cost[i][j]++;

	}
}
