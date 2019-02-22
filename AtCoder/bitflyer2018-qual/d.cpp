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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll h,w,n,m;
	cin>>h>>w>>n>>m;
	char c;
	vvb han(n,vb(m));
	rep(i,n){
		rep(j,m){
			cin>>c;
			han[i][j]=(c=='#');
		}
	}
	vvl board(min(h,n*2+1)+1,vl(min(w,m*2+1)+1));
	bool tate=h>n*2,yoko=w>m*2;
	rep(i,n){
		rep(j,m){
			if(han[i][j]){
				board[i][j]++;
				board[i+(tate?n+2:h-n+1)][j]--;
				board[i][j+(yoko?m+2:w-m+1)]--;
				board[i+(tate?n+2:h-n+1)][j+(yoko?m+2:w-m+1)]++;
			}
		}
	}
	rep(i,board.size()){
		rep(j,board[i].size()-1){
			board[i][j+1]+=board[i][j];
		}
	}
	rep(j,board[0].size()){
		rep(i,board.size()-1){
			board[i+1][j]+=board[i][j];
		}
	}
	ll ans=0;
	rep(i,board.size()-1){
		rep(j,board[i].size()-1){
			if(board[i][j]!=0)ans++;
		}
	}
	if(tate){
		rep(j,board[0].size()-1){
			if(board[n][j]!=0&&(j!=m||!yoko)){
				ans--;ans+=(h-2*n);
			}
		}
	}
	if(yoko){
		rep(i,board.size()-1){
			if(board[i][m]!=0&&(i!=n||!tate)){
				ans--;ans+=(w-2*m);
			}
		}
	}
	if(tate&&yoko&&board[n][m]!=0){
		ans--;ans+=(h-2*n)*(w-2*m);
	}
	cout<<ans<<endl;
}