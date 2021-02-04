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
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define range(i,a,n) for(ll i=(a);i<(n);i++)

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

int b[3][3];
int c[3][3];

int rec(int n,int bd[3][3]){
	if(n==10){
		int score=0;
		rep(i,2)rep(j,3){
			if(bd[i][j]==bd[i+1][j])score+=b[i][j];
			else score-=b[i][j];
		}
		rep(i,3)rep(j,2){
			if(bd[i][j]==bd[i][j+1])score+=c[i][j];
			else score-=c[i][j];
		}
		return score;
	}
	else if(n%2==1){
		int ret=-INF;
		rep(i,3)rep(j,3){
			if(bd[i][j]==0){
				bd[i][j]=1;
				chmax(ret,rec(n+1,bd));
				bd[i][j]=0;
			}
		}
		return ret;
	}
	else{
		int ret=INF;
		rep(i,3)rep(j,3){
			if(bd[i][j]==0){
				bd[i][j]=2;
				chmin(ret,rec(n+1,bd));
				bd[i][j]=0;
			}
		}
		return ret;
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int sum=0;
	rep(i,2)rep(j,3)cin>>b[i][j],sum+=b[i][j];
	rep(i,3)rep(j,2)cin>>c[i][j],sum+=c[i][j];
	int bd[3][3];
	rep(i,3)rep(j,3)bd[i][j]=0;
	ll ans=rec(1,bd);
	puta((ans+sum)/2);
	puta((sum-ans)/2);
}
