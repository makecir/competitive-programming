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

vl fact, finv;
ll modpw(ll x, ll k) { 
	ll res = 1;
	while (k != 0) {
		if (k & 1) res = res*x % MOD;
		x = x*x % MOD;
		k = k >> 1;
	}
	return res;
}
ll comb(ll n, ll k) {
	if (n == 0 && k == 0)return 1;
	if (n < k || n < 0)return 0;
	return fact[n] * finv[n - k] % MOD * finv[k] % MOD;
}

struct ferm{
	ferm(ll n){
		fact.resize(n);
		finv.resize(n);
		fact[0] = 1;
		finv[0] = 1;
		rep (i,n-1) {
			fact[i + 1] = (fact[i] * (i + 1)) % MOD;
			finv[i + 1] = modpw(fact[i + 1], MOD-2);
		}
	}
};



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ferm(100010);
	ll q,n;
	string s;
	cin>>s;
	n=s.size();
	map<char,ll> mp;
	rep(i,n){
		mp[s[i]]++;
	}
	ll div=1;
	for(auto x:mp){
		div*=x.sc;
		div%=MOD;
	}
	cin>>q;
	ll x,y;
	rep(i,q){
		cin>>x>>y;
		x--;y--;
		ll num,ans;
		if(s[x]==s[y])num=mp[s[x]];
		else{
			num=mp[s[x]]+mp[s[y]];
		}
		if(num*2>n)ans=0;
		else{
			ans=(comb(n/2,num)*fact[n-num])%MOD;
			ans*=mp[s[x]];ans%=MOD;
			if(s[x]!=s[y]){
				ans*=comb(num,mp[s[x]]);ans%=MOD;
				ans*=mp[s[y]];ans%=MOD;
			}
			ans*=modpw(div,MOD-2);ans%=MOD;
			ans*=2;ans%=MOD;
		}

		cout<<ans<<"\n";
	}
}