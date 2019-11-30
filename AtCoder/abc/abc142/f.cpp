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
template<class T=ll>struct BellmanFord:Graph<T>{
	using Graph<T>::Graph;
	BellmanFord(int N=1):Graph<T>::Graph(N){}
	const T mval=numeric_limits<T>::max()/2;
	vector<T>dist(ll s){
		vector<T> ret(this->n,mval);
		ret[s]=0;
		rep(i,2*this->n){
			rep(f,this->n)for(auto&e:this->edge[f]){
				ll t; T c; tie(t,c)=e;
				if(ret[f]!=mval && chmin(ret[t],ret[f]+c) && i+1>=this->n){
					ret[t]=-mval;
				}
			}
		}
		return ret;
	}
	T dist(ll s,ll t){return dist(s)[t];}
};

ll mv=4611686018427387903;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;
	vb v(n,true);
	vl in(n),out(n);
	BellmanFord<ll> g(n);
	vl d(n,LINF);
	vector<pll> ed;
	rep(i,m){
		ll a,b;
		cin>>a>>b;
		g.add(a-1,b-1,-1,true);
		ed.push_back(pll(a-1,b-1));
		in[a-1]++;out[b-1]++;
	}
	rep(i,n)if(in[i]==0||out[i]==0)v[i]=false;
	rep(i,n){
		if(!v[i])continue;
		vl dist=g.dist(i);
		if(dist[i]==-mv&0){
			//seikai
			d[i]=0;
			vvl gr(n);
			rep(j,n){
				for(auto x:ed){
					if(x.sc==i){
						vl ans;
						ans.push_back(x.fs);
						while(ans.back()!=i){
							for(auto y:ed){
								if(y.sc==ans.back()&&d[y.fs]+1==d[y.sc])ans.push_back(y.fs);
							}
						}
						cout<<ans.size()<<endl;
						rep(i,ans.size())ans[i]++;
						cout<<ans<<endl;

						//return 0;
					}
					chmin(d[x.sc],d[x.fs]+1);
				}
			}
		}
		else{
			rep(j,n)if(dist[j]!=mv)v[j]=false;
		}
	}
	rep(i,n)cout<<g.dist(i)<<endl;
	cout<<-1<<endl;
}