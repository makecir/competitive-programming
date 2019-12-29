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
template<class T=ll>struct Graph{
	int n;
	vector<vector<tuple<ll,T>>>edge;
	Graph(int N=1):n(N){edge.resize(n);}
	void add(ll f,ll t,T c,bool d=false){
		edge[f].emplace_back(t,c);
		if(!d)edge[t].emplace_back(f,c);
	}
	void view(){
		rep(i,n)for(auto&e:edge[i])
			puta(i,"=>",get<0>(e),", cost :",get<1>(e));
	}
};

ll mdpow(ll x,ll k){
	ll res=1;
	while(k!=0){
		if(k&1)res=res*x%MOD;
		x=x*x%MOD;
		k=k>>1;
	}
	return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	Graph<ll> g(n);
	vl a(n-1),b(n-1);
	rep(i,n-1)cin>>a[i]>>b[i];
	rep(i,n-1)g.add(a[i]-1,b[i]-1,0);
	vvl ch(n);
	stack<ll> stk,tmp;
	stk.push(0);
	tmp.push(0);
	vb use(n,false);
	use[0]=true;
	while(!tmp.empty()){
		ll t=tmp.top();tmp.pop();
		for(auto x:g.edge[t]){
			if(use[get<0>(x)])continue;
			tmp.push(get<0>(x));
			stk.push(get<0>(x));
			use[get<0>(x)]=true;
		}
	}
	vl cnt(n,0);
	while(!stk.empty()){
		ll t=stk.top();stk.pop();
		for(auto x:g.edge[t]){
			if(cnt[get<0>(x)]==0)continue;
			cnt[t]+=cnt[get<0>(x)];
			ch[t].push_back(cnt[get<0>(x)]);
		}
		cnt[t]++;

	}
	vl two(n+1);
	ll p=0;
	two[0]=1;
	rep(i,n){
		two[i+1]=(two[i]*2)%MOD;
	}
	rep(i,n)if(n-cnt[i])ch[i].push_back(n-cnt[i]);
	rep(i,n){
		ll sum=0;
		if(ch[i].size()==1)continue;
		rep(j,ch[i].size()){
			sum+=two[ch[i][j]]-1+MOD;
			sum%=MOD;
		}
		sum++;
		//puta(sum);
		p+=(two[n-1]+MOD-sum);
		p%=MOD;
	}
	//ll cnt=
	//puta(p,two[n]);
	p=(p*mdpow(2,MOD-1-n))%MOD;
	cout<<p<<endl;
}
