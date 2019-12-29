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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<vector<char>> vv(n,vector<char>(n,'.'));
	if(n==2){
		cout<<-1<<endl;
		return 0;
	}
	string ans11="aa............bb............cc............dd........e..........fe..........f ...........a...........fe..........fe..........fe..........f";
	string ans9="aa.aa.aa...b..b..b..b..b..baa.aa.aa...b..b..b..b..b..baa.aa.aa...b..b..b..b..b..b";
	string ans6="aa..bc..aabccc..ab..ccabbb..ca..bbca";
	string ans4="abccabddccabddab";
	if(n%3==0){
		rep(i,n/3){
			vv[i][2*i]='a';
			vv[i][2*i+1]='a';
			vv[n-(i*2)-1][n-i-1]='a';
			vv[n-(i*2)-2][n-i-1]='a';
		}
		rep(i,n){
			rep(j,n)cout<<vv[i][j];
			cout<<endl;
		}
		return 0;
	}
	rep(a,(n+5)/4){
		rep(b,(n+5)/6){
			rep(d,(n+5)/11){
				ll c=n-a*4-b*6;
				//puta(a,b,c);
				if((c<0)||(c%9!=0))continue;
				//puta("!");
				c/=9;
				
				rep(k,b){
					rep(i,6){
						rep(j,6){
							vv[i+6*k][j+6*k]=ans6[((i%6)*6)+(j%6)];
						}
					}
				}
				rep(k,a){
					rep(i,4){
						rep(j,4){
							vv[i+6*b+4*k][j+6*b+4*k]=ans4[((i%4)*4)+(j%4)];
						}
					}
				}
				rep(k,c){
					rep(i,9){
						rep(j,9){
							vv[i+6*b+4*a+9*k][j+6*b+4*a+9*k]=ans9[((i%9)*9)+(j%9)];
						}
					}
				}
				rep(i,n){
					rep(j,n)cout<<vv[i][j];
					cout<<endl;
				}
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
