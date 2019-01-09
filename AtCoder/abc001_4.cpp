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
#define PI			(3.1415926535897932384)

int dx[]={1,0,-1,0,1,-1,-1,1},dy[]={0,1,0,-1,1,1,-1,-1};
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s; a=0;} return os;}
template<class T> void chmax(T &a, const T &b){if(a<b)a=b;}
template<class T> void chmin(T &a, const T &b){if(a>b)a=b;}
void YN(bool b){cout<<(b?"YES":"NO")<<endl;}
void Yn(bool b){cout<<(b?"Yes":"No")<<endl;}
void yn(bool b){cout<<(b?"yes":"no")<<endl;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	vi t(24*12+2);
	int n,s,e,h,w;
	cin>>n;
	rep(i,n){
		cin>>s>>e;
		//cout<<s<<" "<<e<<endl;
		e*=-1;
		h=s/100;w=(s%100)/5;
		t[h*12+w]++;
		h=e/100;w=((e%100)+4)/5;
		t[h*12+w]--;
	}
	//rep(i,t.size())cout<<t[i]<<endl;
	range(i,1,t.size())t[i]+=t[i-1];
	bool r=false;
	int ans;
	rep(i,t.size()){
		if((!r)&&t[i]>0){
			ans=(i/12)*100+(i%12)*5;
			cout<<setfill('0')<<setw(4)<<ans<<"-";
			r=true;
		}
		else if(r&&t[i]<=0){
			ans=(i/12)*100+(i%12)*5;
			cout<<setfill('0')<<setw(4)<<ans<<"\n";
			r=false;
		}
	}
}
