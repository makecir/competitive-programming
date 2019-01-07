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
#define PI			3.1415926535897932384

int dx[]={1,0,-1,0,1,-1,-1,1},dy[]={0,1,0,-1,1,1,-1,-1};
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s; a=0;} return os;}
template<class T> void chmax(T &a, const T &b){if(a<b)a=b;}
template<class T> void chmin(T &a, const T &b){if(a>b)a=b;}
void YN(bool b){cout<<(b?"YES":"NO")<<endl;}
void Yn(bool b){cout<<(b?"Yes":"No")<<endl;}
void yn(bool b){cout<<(b?"yes":"no")<<endl;}

ll dp[200001];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,W;
	cin>>n>>W;
	vl v(n),w(n);
	rep(i,n)cin>>v[i]>>w[i];
	if(n<=30){
		int a=n/2;
		int b=n-a;
		ll ans=0;
		ll vsum=0,wsum=0;
		vector<pll> v1,s1;
		rep(i,1<<a){
			vsum=0;wsum=0;
			rep(j,a){
				if((1<<j)&i){
					vsum+=v[j];
					wsum+=w[j];
				}
			}
			v1.push_back(pll(wsum,vsum));
		}
		sort(all(v1));
		int num=0;
		s1.push_back(v1[0]);
		range(i,1,v1.size()){
			if(s1.back().sc<v1[i].sc) s1.push_back(v1[i]);
		}
		rep(i,1<<b){
			vsum=0;wsum=0;
			rep(j,b){
				if((1<<j)&i){
					vsum+=v[a+j];
					wsum+=w[a+j];
				}
			}
			if(W-wsum>=0){
				auto itr=upper_bound(all(s1),pll(W-wsum,LINF));
				itr--;
				chmax(ans,(*itr).sc+vsum);
			}
		}
		cout<<ans<<endl;
	}
	else if(1000>=*max_element(all(w))){
		rep(i,n){
			rrep(j,min((i+1)*1000+1,200001)){
				if(j-w[i]>=0)chmax(dp[j],dp[j-w[i]]+v[i]);
			}
		}
		cout<<dp[min(W,n*1000)]<<endl;
	}
	else{
		fill_n(dp,200001,LINF);
		dp[0]=0;
		rep(i,n){
			rrep(j,min((i+1)*1000+1,200001)){
				if(j-v[i]>=0)chmin(dp[j],dp[j-v[i]]+w[i]);
			}
		}
		ll ans=0;
		rep(i,200001){
			if(dp[i]<=W)ans=i;
		}
		cout<<ans<<endl;
	}
}