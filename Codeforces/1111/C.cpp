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
using vs=vector<string>;
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n) range(i,0,n)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define range(i,a,n) for(int i=(a);i<(n);i++)

#define LINF    	((ll)1ll<<60)
#define INF     	((int)1<<30)
#define EPS     	(1e-9)
#define MOD     	(1000000007ll)
#define fcout(a)	cout<<setprecision(a)<<fixed
#define fs 			first
#define sc			second
#define PI			(3.1415926535897932384)

int dx[]={1,0,-1,0,1,-1,-1,1},dy[]={0,1,0,-1,1,1,-1,-1};
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s; a=0;} return os;}
template<class T> void chmax(T &a, const T &b){if(a<b)a=b;}
template<class T> void chmin(T &a, const T &b){if(a>b)a=b;}
void YN(bool b){cout<<(b?"YES":"NO")<<"\n";}
void Yn(bool b){cout<<(b?"Yes":"No")<<"\n";}
void yn(bool b){cout<<(b?"yes":"no")<<"\n";}

ll n,k,a,b;
vl v;

ll rec(ll l,ll r,ll mn,ll mx){
	//cout<<l<<" "<<r<<" "<<endl;
	if(mn==mx)return a;
	else{
		ll nd=(mx-mn)*(r-l+1)*b;
		if(r-l>=1){
			ll div=0;
			ll mid=l+(r-l+1)/2;
			ll miditr=lower_bound(all(v),mid)-v.begin();
			div=rec(l,mid-1,mn,miditr)+rec(mid,r,miditr,mx);
			chmin(nd,div);
		}
		//cout<<l<<" "<<r<<" "<<nd<<endl;
		return nd;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>k>>a>>b;
	v.resize(k);
	rep(i,k)cin>>v[i];
	sort(all(v));
	ll ans=rec(1ll,pow(2,n),0,k);
	cout<<ans<<endl;
}