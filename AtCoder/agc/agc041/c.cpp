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
	else{
		vs s3(3),s4(4),s5(5),s7(7);
		s3[0]="aa.";
		s3[1]="..a";
		s3[2]="..a";
		s4[0]="aabc";
		s4[1]="ddbc";
		s4[2]="bcaa";
		s4[3]="bcdd";
		s5[0]="abbcc";
		s5[1]="ac..a";
		s5[2]="bc..a";
		s5[3]="b.aab";
		s5[4]="ccddb";
		s7[0]="aabbaa.";
		s7[1]="bba...a";
		s7[2]="c.a...a";
		s7[3]="cbb...b";
		s7[4]="...bbab";
		s7[5]="...c.ac";
		s7[6]="...cbbc";
		if(n==3||n==6){
			rep(i,n/3){
				rep(j,3)rep(k,3)vv[i*3+j][i*3+k]=s3[j][k];
			}
		}
		else if(n==7||n==11){
			rep(j,7)rep(k,7)vv[j][k]=s7[j][k];
			if(n==11)rep(j,4)rep(k,4)vv[j+7][k+7]=s4[j][k];
		}
		else{
			ll rem=n%4;
			rep(i,rem){
				rep(j,5)rep(k,5)vv[i*5+j][i*5+k]=s5[j][k];
			}
			rep(i,(n-rem*5)/4){
				rep(j,4)rep(k,4)vv[rem*5+i*4+j][rem*5+i*4+k]=s4[j][k];
			}
			
		}
		rep(i,n){
			rep(j,n)cout<<vv[i][j];
			cout<<endl;
		}
	}
	return 0;
}
