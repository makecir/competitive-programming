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
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s;a=0;} return os;}

ll zr=0,pl=0,mn=0;
ll n,k;
vl v,vpl,vzr,vmn;

ll func(ll lim){
	ll ret=0;
	if(lim>=0)ret+=(n*(n-1)/2-(n-zr)*(n-zr-1)/2);
	ll cur=0;
	rep(i,mn){
		while(cur<pl && vpl[cur]*vmn[i] > lim)cur++;
		ret+=(pl-cur);
	}
	cur=pl-1;
	rep(i,pl){
		while(cur>0 && vpl[cur]*vpl[i] > lim)cur--;
		ret+=max(0,cur-i);
	}
	cur=0;
	rrep(i,mn){
		while(cur<mn && vmn[cur]*vmn[i] > lim)cur++;
		ret+=max(0,i-cur);
	}
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	v.resize(n);
	rep(i,n)cin>>v[i];
	sort(all(v));
	rep(i,n){
		if(v[i]<0)vmn.push_back(v[i]);
		if(v[i]==0)vzr.push_back(v[i]);
		if(v[i]>0)vpl.push_back(v[i]);
	}
	mn=vmn.size();
	zr=vzr.size();
	pl=vpl.size();
	ll ng=-LINF*4,ok=LINF*4;
	while(ng+1!=ok){
		ll mid=(ng+ok)/2;
		//puta(mid,func(mid));
		if(func(mid)>=k)ok=mid;
		else ng=mid;
	}
	puta(ok);
}
