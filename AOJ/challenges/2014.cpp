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

ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}
template<class T>void puta(T&&t){cout<<t<<"\n";}
template<class H,class...T>void puta(H&&h,T&&...t){cout<<h<<' ';puta(t...);}
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s;a=0;} return os;}

void solve(int W,int h){
	vvi vv(h+2,vi(W+2));
	vvb w(h+2,vb(W+2,true)),b(h+2,vb(W+2,true));
	queue<pii> bl,wh;
	char ch;
	rep(i,h)rep(j,W){
		b[i+1][j+1]=0;
		w[i+1][j+1]=0;
		w[i+1][j+1]=false;
		b[i+1][j+1]=false;
		cin>>ch;
		if(ch=='W'){
			vv[i+1][j+1]=1;
			w[i+1][j+1]=true;
			wh.push(pii(i+1,j+1));
		}
		if(ch=='B'){
			vv[i+1][j+1]=-1;
			b[i+1][j+1]=true;
			bl.push(pii(i+1,j+1));
		}
	}
	while(!wh.empty()){
		int x,y;
		tie(x,y)=wh.front();wh.pop();
		rep(i,4){
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(!w[tx][ty]&&vv[tx][ty]!=-1){
				wh.push(pii(tx,ty));
				w[tx][ty]=true;
			}
		}
	}
	while(!bl.empty()){
		int x,y;
		tie(x,y)=bl.front();bl.pop();
		rep(i,4){
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(!b[tx][ty]&&vv[tx][ty]!=1){
				bl.push(pii(tx,ty));
				b[tx][ty]=true;
			}
		}
	}
	int answ=0,ansb=0;
	rep(i,h){
		rep(j,W){
			if(!w[i+1][j+1]&&b[i+1][j+1])ansb++;
			if(vv[i+1][j+1]==-1)ansb--;
			if(!b[i+1][j+1]&&w[i+1][j+1])answ++;
			if(vv[i+1][j+1]==1)answ--;
		}
	}
	cout<<ansb<<" "<<answ<<endl;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h,w;
	while(cin>>w>>h,h)solve(w,h);
}