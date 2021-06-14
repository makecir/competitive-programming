#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
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
using vpll=vector<pll>;
using tll=tuple<ll,ll>;
using tlll=tuple<ll,ll,ll>;
using vs=vector<string>;

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n) range(i,0,n)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define range(i,a,n) for(ll i=(a);i<(n);i++)
#define sz(x) (int)(x).size()

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
int popcnt(int x){return __builtin_popcount(x);}
int popcnt(ll x){return __builtin_popcountll(x);}
ll modpw(ll x,ll k){ll res=1;while(k!=0){if(k&1){res=res*x%MOD;}x=x*x%MOD;k=k>>1;}return res;}

ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}
template<class T>void puta(T&&t){cout<<t<<"\n";}
template<class H,class...T>void puta(H&&h,T&&...t){cout<<h<<' ';puta(t...);}
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;}
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s;a=0;} return os;}

string add(string s){
	ll n=sz(s);
	reverse(all(s));
	int t=1,k=0;
	while(t){
		if(k==n){
			s+="1";
			break;
		}
		int x=t+(s[k]-'0');
		s[k]=(x%10)+'0';
		if(x<10)break;
		k++;
	}
	reverse(all(s));
	return s;
}

vi calc(string s){
	ll n=sz(s);
	string ret;
	reverse(all(s));
	vi v(n*2);
	rep(i,n)rep(j,n){
		int x=(s[i]-'0')*(s[j]-'0');
		int k=j;
		while(x){
			int y=v[i+k]+x%10;
			if(y>=10)x+=10;
			v[i+k]=y%10;
			x/=10;
			k++;
		}
	}
	return v;
}

string rev(string s){
	reverse(all(s));
	return s;
}

string scr(string s){
	string ret;
	bool zero=true;
	for(auto x:s){
		zero&=x=='0';
		if(!zero)ret+=x;
	}
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	vi a,b;
	cin>>s;
	a=calc(s);
	b=calc(add(s));
	string sa,sb,ans;
	bool fl=false,diff=false;
	if(sz(a)!=sz(b))rep(_,2)a.push_back(0);
	rrep(i,sz(a)){
		sa+=a[i]+'0';
		sb+=b[i]+'0';
		diff|=(a[i]!='0'||a[i]!=b[i]);
		if(i%2==0&&diff){
			bool zeroa=true,zerob=true;
			rrep(j,i)zeroa&=(a[j]==0);
			rrep(j,i)zerob&=(b[j]==0);
			if(zeroa){
				ans=scr(sa);
				break;
			}
			else{
				if(sa!=sb&&((!zerob)||add(sa)!=sb)){
					ans=scr(add(sa));
					break;
				}
			}
		}
	}
	puta(ans);
}
