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
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,k=0;;
	cin>>n;
	vl v(n);
	Graph<ll> g(n);
	vb use(n,false);
	vl a(n-1),b(n-1);
	map<pll,ll> mp;
	rep(i,n-1){
		cin>>a[i]>>b[i];
		a[i]--;b[i]--;
		if(a[i]>b[i])swap(a[i],b[i]);
		g.add(a[i],b[i],0);
		mp[pll(a[i],b[i])]=0;
	}
	queue<pll> q;
	q.push(pll(0,0));
	while(!q.empty()){
		ll cnt=1;
		ll t,p;
		tie(t,p)=q.front();q.pop();
		use[t]=true;
		for(auto x:g.edge[t]){
			ll to=get<0>(x);
			if(use[to])continue;
			if(cnt==p)cnt++;
			chmax(k,cnt);
			mp[pll(min(to,t),max(to,t))]=cnt;
			//puta(pll(min(to,t)+1,max(to,t)+1),cnt);
			q.push(pll(to,cnt));
			cnt++;
		}
	}
	cout<<k<<endl;
	rep(i,n-1)puta(mp[pll(a[i],b[i])]);

}
