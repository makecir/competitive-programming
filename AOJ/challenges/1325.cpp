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

int dx[]={1,1,-1,-1},dy[]={1,-1,1,-1};

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

constexpr ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
constexpr ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

void solve(ll n, ll m){
	int cnt=0;
	for(ll pp=0;pp*pp<=n*n+m*m;pp++){
		for(ll qq=0;pp*pp+qq*qq<=n*n+m*m;qq++){
			if(pp==0&&qq==0)continue;
			rep(i,4-(pp==0?3:(qq==0?1:0))){
				ll p=dx[i]*pp;
				ll q=dy[i]*qq;
				if((m*p+n*q)%(p*p+q*q)==0&&(n*p-m*q)%(p*p+q*q)==0){
					ll x=(n*q+m*p)/(p*p+q*q);
					ll y=(m*p-q*n)/(p*p+q*q);
					cnt++;
					//puta(p,q,x,y,m,n);
				}
			}
		}
	}
	//puta(cnt);
	cout<<(cnt==8?"P":"C")<<endl;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m,q;
	cin>>q;
	while(q--){
		cin>>m>>n;
		solve(n,m);
	}
}
