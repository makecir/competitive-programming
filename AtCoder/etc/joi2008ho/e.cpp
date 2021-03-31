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
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define range(i,a,n) for(int i=(a);i<(n);i++)

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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int w,h,n,tx,ty,nx,ny;;
	cin>>w>>h>>n;
	vi x1(n),y1(n),x2(n),y2(n);
	map<int,int> mpx,mpy;
	rep(i,n){
		cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
		mpx[x1[i]]=0;
		mpy[y1[i]]=0;
		mpx[x2[i]]=0;
		mpy[y2[i]]=0;
	}
	mpx[0]=0;mpx[w+1]=0;mpx[1]=0;mpx[w]=0;
	mpy[0]=0;mpy[h+1]=0;mpy[1]=0;mpy[h]=0;
	int nw=0,nh=0;
	for(auto &x:mpx)x.sc=nw++;
	for(auto &x:mpy)x.sc=nh++;
	vvi bd(nh,vi(nw));
	rep(i,n){
		bd[mpy[y1[i]]+1][mpx[x1[i]]+1]--;
		bd[mpy[y1[i]]+1][mpx[x2[i]]+1]++;
		bd[mpy[y2[i]]+1][mpx[x1[i]]+1]++;
		bd[mpy[y2[i]]+1][mpx[x2[i]]+1]--;
	}
	rep(i,nh)rep(j,nw-1)bd[i][j+1]+=bd[i][j];
	rep(i,nh-1)rep(j,nw)bd[i+1][j]+=bd[i][j];
	rep(i,nh)bd[i][0]=bd[i][nw-1]=-1;
	rep(j,nw)bd[0][j]=bd[nh-1][j]=-1;
	int ans=0;
	queue<pii> q;
	range(i,1,nh-1)range(j,1,nw-1){
		if(bd[i][j]==0){
			bd[i][j]=++ans;
			q.push(pii(i,j));
			while(!q.empty()){
				tie(ty,tx)=q.front();q.pop();
				rep(k,4){
					nx=tx+dx[k];
					ny=ty+dy[k];
					if(bd[ny][nx]==0){
						bd[ny][nx]=ans;
						q.push(pii(ny,nx));
					}
				}
			}
		}
	}
	puta(ans);
}
