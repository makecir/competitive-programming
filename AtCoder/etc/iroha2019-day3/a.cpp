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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	vl v(26);
	vs daga(8);
	daga={"a","aa","aaa","aaai","aaaji","aabaji","agabaji","dagabaji"};
	rep(i,26)cin>>v[i];
	cout<<v[0]-v[1]<<endl;
	cout<<v[2]+v[3]<<endl;
	cout<<max(0,v[5]-v[4]+1)<<endl;
	cout<<(v[6]+v[7]+v[8])/3+1<<endl;
	cout<<daga[v[9]-1]<<endl;
	ll fav1,fav2;
	ll i=1;
	while(1){
		if(i%59==v[10]&&i%61==v[11]){
			break;
		}
		i++;
	}
	fav1=i+61*59*(v[12]-1);
	ll ab[6]={6, 28, 496, 8128, 33550336, 8589869056};
	rep(i,6){
		if(abs(ab[i]-fav1)>=v[13]){fav2=ab[i];break;}
	}
	if(fav1>fav2)swap(fav1,fav2);
	cout<<fav1<<endl<<fav2<<endl;
	ll sum=1;
	rep(i,4){
		ll tmp=0;
		rep(j,3){
			tmp+=v[14+i*3+j];
		}
		sum*=tmp;
		sum%=9973;
	}
	cout<<sum<<endl;
}
