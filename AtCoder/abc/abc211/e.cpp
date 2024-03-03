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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,k;
	cin>>n>>k;
	vvb bw(n,vb(n));
	rep(i,n)rep(j,n){
		char ch;
		cin>>ch;
		bw[i][j]=(ch=='.');
	}
	vvi vv(n,vi(n));
	ll ans=0;
	function<void(int,int,int,int,int)> rec=[&](int y,int x,int cur,int uni,int mx){
		// puta("---");
		// puta(y,x,cur,uni,mx);
		// rep(i,n)puta(vv[i]);
		if(cur==k&&uni==1){
			ans++;
			// puta("---+++++++---");
			// puta(x,y,cur,uni);
			// rep(i,n)puta(vv[i]);

			// if(ans>10)exit(0);
			return;
		}
		else if(x==n){
			if(y==n-1)return;
			else rec(y+1,0,cur,uni,mx);
		}
		else{
			// okanai
			rec(y,x+1,cur,uni,mx);
			
			// oku
			if(bw[y][x]){
				if(x!=0&&vv[y][x-1]!=0){
					int tar=vv[y][x-1];
					vv[y][x]=tar;
					if(y!=0&&vv[y-1][x]!=0){
						if(vv[y-1][x]!=tar){
							ll ntar=max(tar,vv[y-1][x]);
							chmin(tar,vv[y-1][x]);
							vv[y][x]=tar;
							vi tmp(n);
							rep(d,n){
								tmp[d]=vv[y-1+(x+d)/n][(x+d)%n];
								if(vv[y-1+(x+d)/n][(x+d)%n]==ntar)vv[y-1+(x+d)/n][(x+d)%n]=tar;
							}
							rec(y,x+1,cur+1,uni-1,mx);
							rep(d,n)vv[y-1+(x+d)/n][(x+d)%n]=tmp[d];
						}
						else rec(y,x+1,cur+1,uni,mx);
					}
					else{
						rec(y,x+1,cur+1,uni,mx);
					}
				}
				else if(y!=0&&vv[y-1][x]!=0){
					int tar=vv[y-1][x];
					vv[y][x]=tar;
					rec(y,x+1,cur+1,uni,mx);
				}
				else {
					vv[y][x]=mx+1;
					rec(y,x+1,cur+1,uni+1,mx+1);
				}
				vv[y][x]=0;
			}
		}
	};
	rec(0,0,0,0,0);
	puta(ans);
}
