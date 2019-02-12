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

template<class S>S sum(vector<S>&a){return accumulate(all(a),S());}
template<class S>S max(vector<S>&a){return *max_element(all(a));}
template<class S>S min(vector<S>&a){return *min_element(all(a));}

template<class T>bool chmax(T&a,T b){if(a<b){a=b; return true;}return false;}
template<class T>bool chmin(T&a,T b){if(a>b){a=b; return true;}return false;}
void YN(bool b){cout<<(b?"YES":"NO")<<"\n";}
void Yn(bool b){cout<<(b?"Yes":"No")<<"\n";}
void yn(bool b){cout<<(b?"yes":"no")<<"\n";}

ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}
template<class T>void puta(T&&t){cout<<t<<"\n";}
template<class H,class...T>void puta(H&&h,T&&...t){cout<<h<<' ';puta(t...);}
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s;a=0;} return os;}
mt19937 _mt(chrono::steady_clock::now().time_since_epoch().count());
ll getrnd(ll l,ll r){return uniform_int_distribution<ll>(l,r-1)(_mt);}
#define _cTime (chrono::system_clock::now())
#define progress (chrono::duration_cast<chrono::milliseconds>(_cTime-_sTime).count())
#define reset _sTime=_cTime
auto reset;

constexpr ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}

int stage=550;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,in1,in2;
	cin>>n;
	vl out(n);
	vector<tlll> t(n);
	vector<pll> p(n);
	vi ord(n);
	iota(all(ord),0);
	rep(i,n){
		cin>>in1>>in2;
		p[i]=pll(in1,in2);
		t[i]=tlll(in1,in2,i);
	}

	vvd dist(200,vd(200,INF));
	rep(i,n)dist[i][i]=0;
	rep(i,n){
		rep(j,i){
			double d=sqrt((p[i].fs-p[j].fs)*(p[i].fs-p[j].fs)+(p[i].sc-p[j].sc)*(p[i].sc-p[j].sc));
			dist[j][i]=dist[i][j]=d;
		}
	}
	rep(i,500){
		double r=(double)getrnd(0,1001)/1000;
		int qq=(211*i+7)%n;
		if(r<0.6)swap(ord[i%n],ord[qq]);
	}
	double best=0;
	rep(i,n) best+=dist[ord[i]][ord[(i+1)%n]];
	rep(i,n)out[i]=ord[i];

	int ti=progress;
	rep(div,4){
			rep(i,500){
		double r=(double)getrnd(0,1001)/1000;
		int qq=(211*i+7)%n;
		if(r<0.6)swap(ord[i%n],ord[qq]);
	}
	int st=0;
	while(ti<1500,st++<stage){
		double temp=stage-pow(stage,((double)st/stage));
		temp*=0.00000005;
		int cnt=0;
		rep(i,n-2){
			range(j,i+2,n){
				double be=0,af=0;
				be=dist[ord[i]][ord[i+1]]+dist[ord[j]][ord[(j+1)%n]];
				af=dist[ord[i]][ord[j]]+dist[ord[i+1]][ord[(j+1)%n]];
				double p=(double)getrnd(0,1001)/1000;
				if((af<be)||(p<exp((be-af)/temp))){
					swap(ord[i+1],ord[j]);
					cnt++;
				}
			}
		}
		//cout<<cnt<<endl;
		double sum=0;
		rep(i,n) sum+=dist[ord[i]][ord[(i+1)%n]];
		if(chmin(best,sum)){
			rep(i,n)out[i]=ord[i];
			
		}
		//cout<<ord<<endl;
		//cout<<"dis= "<<sum<<"   best= "<<best<<endl;
	}
	}
	rep(i,n)cout<<out[i]<<"\n";
	//cout<<best<<endl;
}

		//cout<<cnt<<endl;
		double sum=0,sumv=0;
		rep(i,n) sum+=dist[ord[i]][ord[(i+1)%n]];
		rep(i,n) sumv+=(dist[ord[i]][ord[(i+1)%n]]-(sum/n))*(dist[ord[i]][ord[(i+1)%n]]-(sum/n));;
		if(chmin(bestv,sumv)){
			rep(i,n)out[i]=ord[i];
		}
		//cout<<ord<<endl;
		//cout<<"dis= "<<sum<<"   best= "<<best<<endl;
	}
	}
	rep(i,n)cout<<out[i]<<"\n";
	//cout<<best<<endl;
}
