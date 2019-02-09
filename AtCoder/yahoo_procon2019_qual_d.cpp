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

template<class S>S sum(vector<S>&a){return accumulate(all(a),S());}
template<class S>S max(vector<S>&a){return *max_element(all(a));}
template<class S>S min(vector<S>&a){return *min_element(all(a));}

template<class T>bool chmax(T&a,T b){if(a<b){a=b; return true;}return false;}
template<class T>bool chmin(T&a,T b){if(a>b){a=b; return true;}return false;}
void YN(bool b){cout<<(b?"YES":"NO")<<"\n";}
void Yn(bool b){cout<<(b?"Yes":"No")<<"\n";}
void yn(bool b){cout<<(b?"yes":"no")<<"\n";}

ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}
template<class T>void puta(T&&t){cout<<t<<"\n";}
template<class H,class...T>void puta(H&&h,T&&...t){cout<<h<<' ';puta(t...);}
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s;a=0;} return os;}


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	ll mx=0;
	cin>>n;
	vl a(n+2);
	rep(i,n)cin>>a[i+1];
	vl sum(n+2);
	rep(i,n){
		ll t=(a[i+1]==0?-1:(a[i+1]+1)/2*2-1);
		sum[i+1]=sum[i]+t;
	}
	mx=accumulate(all(a),0LL);
	//cout<<sum<<endl;;
	vl rsum(n+2),lsum(n+2);
	ll cur=0,mn=0;
	rep(i,n){
		ll t=(a[i+1]==0?-2:a[i+1]/2*2);
		cur+=t;
		chmin(mn,cur);
		lsum[i+1]=cur-mn;
	}
	cur=0;mn=0;
	rrep(i,n){
		ll t=(a[i+1]==0?-2:a[i+1]/2*2);
		cur+=t;
		chmin(mn,cur);
		rsum[i+1]=cur-mn;
	}
	vl lans(n+2);
	vl rans(n+2);
	rep(i,n+2){
		lans[i]=rans[i]=sum[i];
	}
	rep(i,n){
		lans[i+1]-=lsum[i+1];
	}
	rep(i,n){
		rans[i+1]+=rsum[i+2];
	}
	ll ans=0;mn=LINF;
	ll ansmx=-LINF;
	ll l,r,rr;
	/*
	cout<<lsum<<endl;
	cout<<rsum<<endl;
	cout<<lans<<endl;
	cout<<rans<<endl;
	*/
	range(i,0,n+1){
		if(chmin(mn,lans[i]))rr=i;
		ll t=rans[i]-mn;
		if(ansmx<t){r=i;l=rr;ansmx=t;}
	}
	//cout<<l<<" "<<r<<endl;
	cout<<mx-ansmx<<endl;
}