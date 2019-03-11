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
#define _cTime (chrono::system_clock::now())
#define progress (chrono::duration_cast<chrono::milliseconds>(_cTime-_sTime).count())
#define reset _sTime=_cTime
auto reset;

int blue[2001][2001];
int cc[2001][2001];
int rc[2001][2001];
bool tab[2001][2001];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,m,q;
	char ch;
	cin>>n>>m>>q;
	rep(i,n){
		rep(j,m){
			cin>>ch;
			tab[i+1][j+1]=(ch=='1');
		}
	}
	range(i,1,n+1){
		range(j,1,m+1){
			blue[i][j]=blue[i][j-1]+(blue[i-1][j]-blue[i-1][j-1]);
			blue[i][j]+=tab[i][j];
			rc[i][j]=rc[i][j-1];
			cc[i][j]=cc[i][j-1];
			if(tab[i][j]){
				rc[i][j]+=tab[i-1][j];
				cc[i][j]+=tab[i][j-1];
			}
		}
	}
	range(i,1,n+1){
		range(j,1,m+1){
			rc[i][j]+=rc[i-1][j];
			cc[i][j]+=cc[i-1][j];
		}
	}
	int a,b,c,d;
	while(q--){
		cin>>a>>b>>c>>d;
		int node=blue[c][d]+blue[a-1][b-1]-blue[c][b-1]-blue[a-1][d];
		int edge=0;
		edge+=rc[c][d]+rc[a][b-1]-rc[c][b-1]-rc[a][d];
		edge+=cc[c][d]+cc[a-1][b]-cc[c][b]-cc[a-1][d];
		cout<<node-edge<<"\n";
	}
}
