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
void OUT(bool b){cout<<(b?"YES":"NO")<<endl;}
void Out(bool b){cout<<(b?"Yes":"No")<<endl;}
void out(bool b){cout<<(b?"yes":"no")<<endl;}
int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int clz(int x) { return 31 - __builtin_clz(x); }
int clz(ll x) { return 63 - __builtin_clzll(x); }
int ctz(int x) { return __builtin_ctz(x); }
int ctz(ll x) { return __builtin_ctzll(x); }

class compare {
public:
	bool operator()(tuple<ll, ll> a, tuple<ll, ll> b) {
		return (get<1>(a) > get<1>(b));
	}
};

double dp[2][70][50][40];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s,ans;
	cin>>s;
	bool ast=false;
	ll n=s.size(),k,mn=0;
	vl a,q;
	cin>>k;
	rep(i,n){
		if(s[i]=='*'){
			ast=true;
			a.push_back(i);
			mn--;
		}
		else if(s[i]=='?'){
			q.push_back(i);
			mn--;
		}
		else mn++;
	}
	if(k<mn||(!ast&&(mn+q.size()<k))){
		cout<<"Impossible"<<endl;
		return 0;
	}
	else{
		if(ast){
			ll tab=k-mn;
			rrep(i,n){
				if(s[i]=='*'){
					i--;
					if(ast){
						ast=false;
						rep(j,tab){
							ans.push_back(s[i]);
						}
					}
				}
				else if(s[i]=='?'){
					i--;
					//ans.push_back(s[i]);
				}
				else ans.push_back(s[i]);
			}
		}
		else{
			ll tab=k-mn;
			rrep(i,n){
				if(s[i]=='?'){
					i--;
					if(tab>0){
						tab--;
						ans.push_back(s[i]);
					}
				}
				else ans.push_back(s[i]);
			}
		}
		rrep(i,ans.size())cout<<ans[i];
		cout<<endl;
	}
}