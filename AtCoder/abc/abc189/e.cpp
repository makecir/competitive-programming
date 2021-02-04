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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m,q,p,op,a,b;
	cin>>n;
	vl x(n),y(n);
	rep(i,n)cin>>x[i]>>y[i];
	cin>>m;
	vector<vvl> v(m+1,vvl(3,vl(3)));
	vvl tmp(3,vl(3)),smp(3,vl(3));
	v[0][0][0]=1;
	v[0][1][1]=1;
	v[0][2][2]=1;
	rep(i,m){
		cin>>op;
		rep(j,3)rep(k,3)tmp[j][k]=0;
		if(op>=3)cin>>p;
		if(op==2){
			tmp[1][0]=1;
			tmp[0][1]=-1;
			tmp[2][2]=1;
		}
		else if(op==1){
			tmp[1][0]=-1;
			tmp[0][1]=1;
			tmp[2][2]=1;
		}
		else if(op==3){
			tmp[0][0]=-1;
			tmp[1][1]=1;
			tmp[2][2]=1;
		}
		else{
			tmp[0][0]=1;
			tmp[1][1]=-1;
			tmp[2][2]=1;
		}
		rep(j,3)rep(k,3)rep(l,3){
			v[i+1][j][k]+=tmp[j][l]*v[i][l][k];
		}
		if(op==3||op==4){
			rep(j,3)rep(k,3)smp[j][k]=v[i+1][j][k],v[i+1][j][k]=0;
			tmp[0][0]=1;
			tmp[1][1]=1;
			tmp[2][2]=1;
			if(op==3)tmp[0][2]=2*p;
			if(op==4)tmp[1][2]=2*p;
			rep(j,3)rep(k,3)rep(l,3){
				v[i+1][j][k]+=tmp[j][l]*smp[l][k];
			}
		}
	}
	cin>>q;
	while(q--){
		cin>>a>>b;
		b--;
		pll p;
		p.fs=v[a][0][0]*x[b]+v[a][0][1]*y[b]+v[a][0][2]*1;
		p.sc=v[a][1][0]*x[b]+v[a][1][1]*y[b]+v[a][1][2]*1;
		puta(p.fs,p.sc);
	}


}
