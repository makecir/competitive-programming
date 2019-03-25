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

void solve(int w,int h){
	int in;
	vvb tate(h,(vb(w-1)));
	vvb yoko(h-1,(vb(w)));
	rep(i,2*h-1){
		if(i%2==0){
			rep(j,w-1){
				cin>>in;
				tate[i/2][j]=(in==1);
			}
		}
		else{
			rep(j,w){
				cin>>in;
				yoko[i/2][j]=(in==1);
			}
		}
	}
	vvi vv(h+2,vi(w+2,-1));
	rep(i,h)rep(j,w)vv[i+1][j+1]=INF;
	vv[1][1]=1;
	queue<pii> q;
	q.push(pii(1,1));
	while(!q.empty()){
		int i,j;
		tie(i,j)=q.front();q.pop();
		if(i==h&&w==j){
			cout<<vv[i][j]<<endl;
			return;
		}
		if(vv[i][j]+1<vv[i][j+1]&&tate[i-1][j-1]==false){
			vv[i][j+1]=vv[i][j]+1;
			q.push(pii(i,j+1));
		}
		if(vv[i][j]+1<vv[i][j-1]&&tate[i-1][j-2]==false){
			vv[i][j-1]=vv[i][j]+1;
			q.push(pii(i,j-1));
		}
		if(vv[i][j]+1<vv[i+1][j]&&yoko[i-1][j-1]==false){
			vv[i+1][j]=vv[i][j]+1;
			q.push(pii(i+1,j));
		}
		if(vv[i][j]+1<vv[i-1][j]&&yoko[i-2][j-1]==false){
			vv[i-1][j]=vv[i][j]+1;
			q.push(pii(i-1,j));
		}
	}
	cout<<0<<endl;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h,w;
	while(cin>>w>>h,h)solve(w,h);
}