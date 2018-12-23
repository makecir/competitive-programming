#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vb=vector<bool>;
using vvb=vector<vb>;
using vd=vector<double>;
using vvd=vector<vd>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pll=pair<ll,ll>;
using tll=tuple<ll,ll>;
using vs=vector<string>;
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n) range(i,0,n)
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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	string s;
	cin>>s;
	n=s.size();
	ll x,y;
	cin>>x>>y;
	vl xx,yy;
	bool b=true;
	int cnt=0;
	rep(i,n){
		if(s[i]=='T'){
			if(cnt!=0||xx.size()==0){
				if(b) xx.push_back(cnt);
				else if (cnt!=0)  yy.push_back(cnt);
			}
			cnt=0;
			b=!b;
		}
		else cnt++;	
	}
	if(cnt){
		if(b) xx.push_back(cnt);
		else yy.push_back(cnt);
	}
	vvb xxx(xx.size()+1,vb(160002,false)),yyy(yy.size()+1,vb(160000,false));
	xxx[0][8000]=true;yyy[0][8000]=true;
	rep(i,xxx.size()-1){
		rep(j,xxx[i].size()){
			if(xxx[i][j]){
				xxx[i+1][j+xx[i]]=true;
				if(i!=0)xxx[i+1][j-xx[i]]=true;
			}
		}
	}
	rep(i,yyy.size()-1){
		rep(j,yyy[i].size()){
			if(yyy[i][j]){
				yyy[i+1][j+yy[i]]=true;
				yyy[i+1][j-yy[i]]=true;
			}
		}
	}
	Out(xxx[xx.size()][x+8000]&&yyy[yy.size()][y+8000]);

}
