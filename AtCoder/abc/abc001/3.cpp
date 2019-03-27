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
	ll k,n=0;
	cin>>k>>n;
	vs vec(16);
	vec[0]="N";
	vec[1]="NNE";
	vec[2]="NE";
	vec[3]="ENE";
	vec[4]="E";
	vec[5]="ESE";
	vec[6]="SE";
	vec[7]="SSE";
	vec[8]="S";
	vec[9]="SSW";
	vec[10]="SW";
	vec[11]="WSW";
	vec[12]="W";
	vec[13]="WNW";
	vec[14]="NW";
	vec[15]="NNW";
	k*=10;
	k=((k+1125)/2250)%16;
	string ans=vec[k];
	int ponum=0;
	int pw[12]={12,90,198,324,474,642,828,1026,1242,1464,1704,1956};
	rep(i,12)if(n>=pw[i]+3)ponum++;
	if(ponum==0)ans="C";
	cout<<ans<<" "<<ponum<<endl;
}