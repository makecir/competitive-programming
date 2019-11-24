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

string query(vl v){
	string ret="?";
	rep(i,v.size())ret+=(" "+to_string(v[i]));
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,pnt;
	cin>>n;
	vb out(2*n);
	ll t=0,le=0,ri=n;
	bool l,r;
	vb ans(2*n,false);
	rep(i,n+1){
				//puta("@");
		vl tmp;
		rep(j,n){
			tmp.push_back(t+j+1);
		}
		cout<<query(tmp)<<endl;
		string in;
		cin>>in;
		if(in=="-1")return 0;
		out[t]=(in=="Red");
		out[t+n]=!(in=="Red");
		if(i==0){
			if(ri-le==1){
				pnt=ri;
				ans[le]=out[le];
				ans[le+n]=!out[le];//		puta(le,ri);
		//puta(ans);
				break;
			}
			l=(in=="Red");
			r=!l;
			t=n/2;
		}
		else{
			if(ri-le==1){
				pnt=ri;
				ans[le]=out[le];
				ans[le+n]=!out[le];//		puta(le,ri);
		//puta(ans);
				break;
			}
			bool an=(in=="Red");
			if(l==an)le=t;
			else ri=t;
			t=(le+ri)/2;
		}
	}
	rep(i,n-1){
		//puta("@@");
		vl tmp;
		rep(j,n-1){
			tmp.push_back((pnt+j)%(2*n) +1);
		}
		tmp.push_back((pnt+i+n)%(2*n) +1);
		cout<<query(tmp)<<endl;
		string in;
		cin>>in;
		ans[(pnt+i+n)%(2*n)]=(in=="Red");
	}
	rep(i,n-1){
				//puta("@@@");
		vl tmp;
		rep(j,n-1){
			tmp.push_back((pnt+n+j)%(2*n) +1);
		}
		tmp.push_back((pnt+i)%(2*n) +1);
		cout<<query(tmp)<<endl;
		string in;
		cin>>in;
		if(in=="-1")return 0;
		ans[(pnt+i)%(2*n)]=(in=="Red");
	}
	string answer="! ";
	rep(i,2*n)answer+=(ans[i]?"R":"B");
	cout<<answer<<endl;
}
