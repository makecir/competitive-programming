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
using pll=pair<ll,ll>;
using tll=tuple<ll,ll>;
using vs=vector<string>;
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n) range(i,0,n)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define range(i,a,n) for(int i=(a);i<(n);i++)

#define LINF    	((ll)1ll<<60)
#define INF     	((int)1<<30)
#define EPS     	(1e-9)
#define MOD     	(1000000007ll)
#define fcout(a)	cout<<setprecision(a)<<fixed
#define fs 			first
#define sc			second
#define PI			(3.1415926535897932384)

int dx[]={1,0,-1,0,1,-1,-1,1},dy[]={0,1,0,-1,1,1,-1,-1};
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s; a=0;} return os;}
template<class T> void chmax(T &a, const T &b){if(a<b)a=b;}
template<class T> void chmin(T &a, const T &b){if(a>b)a=b;}
void YN(bool b){cout<<(b?"YES":"NO")<<endl;}
void Yn(bool b){cout<<(b?"Yes":"No")<<endl;}
void yn(bool b){cout<<(b?"yes":"no")<<endl;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll h,w,ans=0;
	string s;
	cin>>h>>w;
	vvi vv(h+2,vi(w+2));
	vvb vstd(h+2,vb(w+2,true));
	rep(i,h){
		cin>>s;
		rep(j,w){
			if(s[j]=='.')vv[i+1][j+1]=1;
			else vv[i+1][j+1]=-1;
			vstd[i+1][j+1]=false;
		}
	}
	rep(i,h){
		rep(j,w){
			if(vstd[i+1][j+1]==false){
				ll bl=0,wh=0;
				vstd[i+1][j+1]=true;
				queue<pll> q;
				q.push(pll(i+1,j+1));
				while(!q.empty()){
					ll x,y;
					tie(x,y)=q.front(),q.pop();
					(vv[x][y]==-1?bl++:wh++);
					rep(k,4){
						if(vstd[x+dx[k]][y+dy[k]]==false&&(vv[x+dx[k]][y+dy[k]]==-1*vv[x][y])){
							vstd[x+dx[k]][y+dy[k]]=true;
							q.push(pll(x+dx[k],y+dy[k]));
						}
					}
				}
				ans+=(bl*wh);
			}
		}
	}
	cout<<ans<<endl;
}

 
