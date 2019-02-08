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

#define LINF    	((ll)1ll<<60)
#define INF     	((int)1<<30)
#define EPS     	(1e-9)
#define MOD     	(1000000007ll)
#define fcout(a)	cout<<setprecision(a)<<fixed
#define fs 			first
#define sc			second
#define PI			(3.1415926535897932384)

int dx[]={1,0,-1,0,1,-1,-1,1},dy[]={0,1,0,-1,1,1,-1,-1};
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s; a=0;} return os;}
template<class T> void chmax(T &a, const T &b){if(a<b)a=b;}
template<class T> void chmin(T &a, const T &b){if(a>b)a=b;}
void YN(bool b){cout<<(b?"YES":"NO")<<"\n";}
void Yn(bool b){cout<<(b?"Yes":"No")<<"\n";}
void yn(bool b){cout<<(b?"yes":"no")<<"\n";}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m,in1,in2;
	cin>>n>>m;
	vvi v(n);
	rep(i,m){
		cin>>in1>>in2;
		v[in1-1].push_back(in2-1);
		v[in2-1].push_back(in1-1);
	}
	int ans=0;
	vi ta(n,0);
	rep(i,n){
		if(ta[i]==0){
			ll ang=0,dev=0;
			ta[i]=-1;ang++;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int t=q.front();q.pop();
				rep(j,v[t].size()){
					if(ta[t]==ta[v[t][j]]){
						cout<<n*(n-1)/2-m<<endl;
						return 0;
					}
					else if(ta[v[t][j]]==0){
						ta[v[t][j]]=-ta[t];
						(ta[v[t][j]]==1?dev++:ang++);
						q.push(v[t][j]);
					}
				}
			}
			cout<<dev*ang-m<<endl;
		}
	}

}
