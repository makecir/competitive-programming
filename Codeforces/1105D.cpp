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

using tlll=tuple<ll,ll,ll>;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,h,w;
	char c;
	cin>>h>>w>>n;
	vl lv(n);
	vector<vector<queue<tlll>>> cas(2,vector<queue<tlll>>(n));
	rep(i,n)cin>>lv[i];
	vvl vv(h+2,vl(w+2,-1));
	rep(i,h){
		rep(j,w){
			cin>>c;
			if(c=='#')vv[i+1][j+1]=-1;
			else if(c!='.'){
				vv[i+1][j+1]=(c-'0');
				cas[0][c-'0'-1].push(tlll(i+1,j+1,0));
			}
			else vv[i+1][j+1]=0;
		}
	}
	bool pos=false;
	while(1){
		bool nothing=true;
		rep(i,n){
			while(!cas[pos][i].empty()){
				nothing=false;
				ll x,y,l;
				tie(x,y,l)=cas[pos][i].front();cas[pos][i].pop();
				l++;
				rep(j,4){
					ll tx=x+dx[j],ty=y+dy[j];
					if(vv[tx][ty]==0){
						vv[tx][ty]=i+1;
						if(l<lv[i])cas[pos][i].push(tlll(tx,ty,l));
						else cas[!pos][i].push(tlll(tx,ty,0));
					}
				}
			}
		}
		pos=!pos;
		if(nothing)break;
	}
	vl ans(n);
	rep(i,h){
		rep(j,w){
			//cout<<vv[i+1][j+1]<<"   ";
			if(vv[i+1][j+1]!=-1&&vv[i+1][j+1]!=0){
				ans[vv[i+1][j+1]-1]++;
			}
		}
		//cout<<endl;
	}
	cout<<ans<<endl;
}