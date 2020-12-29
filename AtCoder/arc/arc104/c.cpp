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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vl a(n),b(n),op(2*n+1);
	vb exist(2*n+1);
	rep(i,n){
		cin>>a[i]>>b[i];
		if((a[i]!=-1&&exist[a[i]])||(b[i]!=-1&&exist[b[i]])){
			cout<<"No"<<endl;
			return 0;
		}
		if(a[i]!=-1){
			op[a[i]]=i+1;
			exist[a[i]]=true;
		}
		if(b[i]!=-1){
			op[b[i]]=-(i+1);
			exist[b[i]]=true;
		}
	}
	vb dp(2*n+1);
	dp[0]=true;
	for(int i=2;i<=2*n;i+=2){
		for(int j=0;j<i;j+=2){
			if(!dp[j])continue;
			//j+1 ~ i 人目が成り立つか
			bool check=true;
			for(int k=j+1;k<j+1+(i-j)/2;k++){
				int l=k+(i-j)/2;
				//puta("kl",k,l);
				if(op[k]<0||op[l]>0)check=false;
				else if(op[k]==0&&op[l]==0)continue;
				else if(op[k]!=0&&op[l]==0){
					if(b[op[k]-1]!=-1&&b[op[k]-1]!=l)check=false;
				}
				else if(op[k]==0&&op[l]!=0){
					if(a[-op[l]-1]!=-1&&a[-op[l]-1]!=k)check=false;
				}
				else{
					if(op[k]!=-op[l]||(b[op[k]-1]!=-1&&b[op[k]-1]!=l)||(a[-op[l]-1]!=-1&&a[-op[l]-1]!=k))check=false;
				}
				//puta("op",op[k],op[l],check);
			}
			if(check){
				dp[i]=true;
				break;
			}
		}
	}
	Yn(dp[2*n]);
}
