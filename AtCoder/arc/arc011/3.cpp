#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define range(i,a,n) for(ll i=(a);i<(n);i++)

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

ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}
template<class T>void puta(T&&t){cout<<t<<"\n";}
template<class H,class...T>void puta(H&&h,T&&...t){cout<<h<<' ';puta(t...);}
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;}
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

template<class T=ll>struct Dijkstra:Graph<T>{
	using Graph<T>::Graph;
	Dijkstra(int N=1):Graph<T>::Graph(N){}
	const T mval=numeric_limits<T>::max()/2;
	vector<T>dist(ll s){
		vector<T> ret(this->n,mval);
		priority_queue<tuple<T,ll>> q;
		q.emplace(T(),s);
		while(!q.empty()){
			T c; ll p; tie(c,p)=q.top(); q.pop();
			if(ret[p]!=mval)continue;
			ret[p]=c=-c;
			for(auto&e:this->edge[p]){
				ll nxt;T cost;
				tie(nxt,cost)=e;
				if(ret[nxt]<=ret[p]+cost)continue;
				q.emplace(-ret[p]-cost,nxt);
			}
		}
		return ret;
	}
	T dist(ll s,ll t){return dist(s)[t];}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	string st,go;
	cin>>st>>go;
	cin>>n;
	vs wo(n);
	rep(i,n)cin>>wo[i];
	if(st==go){
		puta(0);
		puta(st);
		puta(go);
	}
	else{
		ll cnt=2;
		map<string,ll> sl;
		map<ll,string> ls;
		sl[st]=0;
		sl[go]=1;
		ls[0]=st;
		ls[1]=go;
		rep(i,n){
			if(sl.find(wo[i])==sl.end()){
				ls[cnt]=wo[i];
				sl[wo[i]]=cnt;
				cnt++;
			}
		}
		Dijkstra<ll> g(cnt);
		rep(i,cnt)rep(j,i){
			ll dif=0;
			rep(k,ls[i].size()){
				if(ls[i][k]!=ls[j][k])dif++;
			}
			if(dif==1)g.add(i,j,1);
		}
		vl dist=g.dist(0);
		if(dist[1]==numeric_limits<ll>::max()/2)puta(-1);
		else{
			ll cur=1;
			puta(dist[1]-1);
			vs ans;
			ans.push_back(go);
			rrep(i,dist[1]){
				for(auto x:g.edge[cur]){
					if(dist[get<0>(x)]==dist[cur]-1){
						ans.push_back(ls[get<0>(x)]);
						cur=get<0>(x);
						break;
					}
				}
			}
			rrep(i,ans.size()){
				puta(ans[i]);
			}
		}
	}
}
