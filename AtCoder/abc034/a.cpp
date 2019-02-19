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

class compare {
public:
	bool operator()(tuple<ll, ll> a, tuple<ll, ll> b) {
		return (get<1>(a) > get<1>(b));
	}
};

int V;
vector<vector<tll>> g;
vector<ll> d;

void dijkstra(int s) {
	fill(all(d),LINF);
	d[s]=0;
	vb vstd(V, false);
	priority_queue<tll, vector<tll>, compare> q;
	q.push(tll(s, 0));
	while (!q.empty()) {
		ll to, dist;
		tie(to, dist) = q.top(); q.pop();
		if (vstd[to])continue;
		vstd[to] = true;
		d[to] = dist;
		rep(i, g[to].size()) {
			ll next = get<0>(g[to][i]);
			ll cost = get<1>(g[to][i]);
			if (d[next] < dist + cost)continue;
			q.push(tll(next, dist + cost));
		}
	}
}


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll x,y;
	cin>>x>>y;
	cout<<(x<y?"Better":"Worse")<<endl;
}
