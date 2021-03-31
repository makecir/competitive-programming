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

map<pll,bool> mp;

bool memo(ll a,ll b){
	if(mp.find({a,b})!=mp.end())return mp[{a,b}];
	else{
		bool ret=gcd(a,b)==1;
		mp[{a,b}]=ret;
		return ret;
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll a,b,tar;
	cin>>a>>b;
	vvl v;
	v.emplace_back();
	vl tw,th;
	for(ll c=a;c<=b;c++){
		if(c%2!=0&&c%3!=0){
			tar=v.size();
			rep(i,tar){
				bool pr=true;
				vl tmp;
				for(auto x:v[i]){
					if(memo(x,c)!=1){
						pr=false;break;
					}
					tmp.push_back(x);
				}
				if(pr){
					tmp.push_back(c);
					v.push_back(tmp);
				}
			}
		}
		if(c%2==0)tw.push_back(c);
		if(c%3==0)th.push_back(c);
	}
	ll ans=0;
	tar=v.size();
	for(auto y:tw){
		rep(i,tar){
			bool pr=true;
			vl tmp;
			for(auto x:v[i]){
				if(gcd(x,y)!=1){
					pr=false;break;
				}
				tmp.push_back(x);
			}
			if(pr){
				tmp.push_back(y);
				v.push_back(tmp);
			}
		}
	}
	tar=v.size();
	for(auto y:th){
		rep(i,tar){
			bool pr=true;
			vl tmp;
			for(auto x:v[i]){
				if(gcd(x,y)!=1){
					pr=false;break;
				}
				tmp.push_back(x);
			}
			if(pr){
				tmp.push_back(y);
				v.push_back(tmp);
			}
		}
	}
	puta(v.size());
}