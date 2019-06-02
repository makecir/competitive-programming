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

ll x;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,sum=0,ao=0;
	cin>>n>>x;
	vl b(n),l(n),r(n);
	rep(i,n)cin>>b[i]>>l[i]>>r[i];
	vector<tlll> v(n);
	rep(i,n)v[i]=tie(b[i],l[i],r[i]);
	rep(i,n)sum+=r[i]*x,ao+=b[i]*r[i];
	sort(all(v),[](auto &a,auto &b){
		if(get<2>(a)*(x-get<0>(a)) != get<2>(b)*(x-get<0>(b))) return (get<2>(a)*(x-get<0>(a)) < get<2>(b)*(x-get<0>(b)));
		else return(get<0>(a) > get<0>(b));
	});
	puta(sum,ao);
	rep(i,n){
		puta(get<0>(v[i]),get<1>(v[i]),get<2>(v[i]));
		ao-=(get<2>(v[i])-get<1>(v[i]))*get<0>(v[i]);
		sum-=get<2>(v[i])*x;
		puta(sum,ao);
		if(sum<ao){
			ao+=(get<2>(v[i])-get<1>(v[i]))*get<0>(v[i]);
			sum+=get<2>(v[i])*x;
			ll mn=x;
			range(j,i,n){
				//ao-=(get<2>(v[j])-get<1>(v[j]))*get<0>(v[j]);
				sum-=get<2>(v[j])*x;
				puta(ao-sum);
				chmin(mn,((ao-sum+-1)/get<2>(v[j])+1));				
				puta("!",get<0>(v[j]),((ao-sum+get<0>(v[j])*(get<2>(v[j])-get<1>(v[j]))-1)/get<2>(v[j])+1));
				//ao+=(get<2>(v[j])-get<1>(v[j]))*get<0>(v[j]);
				sum+=get<2>(v[j])*x;
			}
			cout<< x*(n-i-1)+mn<<endl;
			return 0;
		}
	}
	cout<<x*n<<endl;
}
