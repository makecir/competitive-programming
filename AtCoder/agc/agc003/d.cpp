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

vb eratosthenes(ll n){
	if(n<1){
		vb ret(2,false);
		return ret;
	}
	vb ret(n+1,true);
	ret[0]=false;
	ret[1]=false;
	for(int i=2;i<=n;i++){
		if(!ret[i])continue;
		for(int j=i*2;j<=n;j+=i){
			ret[j]=false;
		}
	}
	return ret;
}

set<ll> prime_set(ll n){
	vb v=eratosthenes(n);
	set<ll> ret;
	rep(i,v.size())if(v[i])ret.insert(i);
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,tmp,ans=0,xxx,yy;
	cin>>n;
	vl s(n);
	rep(i,n)cin>>s[i];
	set<ll> p3,p2;
	p3=prime_set(2155ll);
	p2=prime_set(100000ll);
	map<ll,ll> mp;
	map<ll,bool> mpbl;
	rep(i,n){
		tmp=s[i];
		for(auto x:p3){
			xxx=x*x*x;
			while(tmp%xxx==0)tmp/=xxx;
		}
		mp[tmp]++;
		mpbl[tmp]=true;
	}
	for(auto x:mp){
		if(x.fs==1){
			ans+=min(x.sc,1ll);
		}
		else{
			tmp=x.fs;
			ll tab=0;
			bool sqr=true;
			map<ll,ll> mul;
			if(!mpbl[tmp])continue;
			for(auto y:p3){
				if(y*y*y<=x.fs){
					while(tmp%y==0){
						tmp/=y;
						mul[y]++;
					}
				}
			}
			for(auto y:p2){
				yy=y*y;
				if(tmp<yy)break;
				else if(tmp==yy){
					tab=y;
					sqr=false;
					break;
				}
			}
			if(sqr)tab=tmp*tmp;
			for(auto y:mul){
				if(y.sc==2)tab*=y.fs;
				else tab*=y.fs*y.fs;
			}
			mpbl[x.fs]=false;
			mpbl[tab]=false;
			if(mp.find(tab)==mp.end()) ans+=mp[x.fs];
			else ans+=max(mp[x.fs],mp[tab]);
		}
	}
	puta(ans);
}
