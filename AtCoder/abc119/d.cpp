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
	ll an,bn,q,x;
	cin>>an>>bn>>q;
	vl a(an),b(bn);
	rep(i,an)cin>>a[i];
	rep(i,bn)cin>>b[i];
	rep(i,q){
		cin>>x;
		vl s,t;
		auto sit=lower_bound(all(a),x);
		if(sit==a.end())sit--;
		s.push_back(*sit);
		if(sit!=a.begin()){
			sit--;
			s.push_back(*sit);
		}
		auto tit=lower_bound(all(b),x);
		if(tit==b.end())tit--;
		t.push_back(*tit);
		if(tit!=b.begin()){
			tit--;
			t.push_back(*tit);
		}
		ll ans=LINF;
		for(auto p:s){
			for(auto q:t){
				ll tmp=0;
				if((p-x)*(q-x)<0){
					tmp=abs(p-q);
					tmp+=min(abs(p-x),abs(q-x));
				}
				else{
					tmp=max(abs(p-x),abs(q-x));
				}
				chmin(ans,tmp);
			}
		}
		cout<<ans<<"\n";
	}
}