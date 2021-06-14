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
#define sz(x) (int)(x).size()

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

ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}
template<class T>void puta(T&&t){cout<<t<<"\n";}
template<class H,class...T>void puta(H&&h,T&&...t){cout<<h<<' ';puta(t...);}
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;}
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s;a=0;} return os;}

ll lv=0,k;
vector<vvl> dc;
vvl ndc;
void rec(string s,ll cnt,ll cur){
	if(sz(s)==0)return;
	if(cur==k+1){
		ndc.resize(sz(s),vl(26,0));
		rep(i,sz(s))ndc[i][s[i]-'a']++;
	}
	else{
		lv=cur;
		if(sz(s)%2==1){
			dc[cur].resize(1,vl(26,0));
			dc[cur][0][s[sz(s)/2]-'a']++;
		}
		rec(s.substr(0,sz(s)/2),cnt*2,cur+1);
		string tmp=s.substr((sz(s)+1)/2,sz(s)/2);
		reverse(all(tmp));
		rec(tmp,cnt*2,cur+1);
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll ans=0;
	string s;
	cin>>k>>s;
	dc.resize(100);
	rec(s,1,1);
	if(lv+(sz(ndc)==1?1:0)!=k){
		puta("impossible");
	}
	else{
		for(auto x:dc){
			for(auto y:x){
				ll sum=0,mx=0;
				for(auto z:y){
					sum+=z;
					chmax(mx,z);
				}
				ans+=sum-mx;
			}
		}
		if(sz(ndc)!=1){
			ll scr=0;
			vl tar(sz(ndc)),rev(sz(ndc));
			rep(i,sz(ndc)){
				ll sum=0,mx=0;
				rep(j,26){
					sum+=ndc[i][j];
					if(chmax(mx,ndc[i][j])){
						tar[i]=j;
						rev[sz(ndc)-i-1]=j;
					}
				}
				scr+=sum-mx;
			}
			bool same=true;
			rep(i,sz(ndc))same&=tar[i]==rev[i];
			if(same&&sz(ndc)!=0){
				ll mn=LINF;
				rep(i,sz(ndc)){
					if(i*2+1==sz(ndc))continue;
					sort(rall(ndc[i]));
					chmin(mn,ndc[i][0]-ndc[i][1]);
				}
				scr+=mn;
			}
			ans+=scr;
			puta(ans);
		}
		else puta("impossible");
	}
}
