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

int name[52*52*52];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	string s;
	rep(i,n){
		cin>>s;
		int l=s.size();
		set<ll> st;
		if(l>52){
			vi bf(52,INF),af(52,-1);
			vvi sum(l+1,vi(52));
			rep(j,l){
				int t=(s[j]<='Z'?s[j]-'A':s[j]-'a'+26);
				rep(k,52)sum[j+1][k]=sum[j][k];
				sum[j+1][t]++;
			}
			rrep(j,l){
				int t=(s[j]<='Z'?s[j]-'A':s[j]-'a'+26);
				chmin(bf[t],j);
			}
			rep(j,l){
				int t=(s[j]<='Z'?s[j]-'A':s[j]-'a'+26);
				chmax(af[t],j);
			}
			rep(j,52){
				rep(k,52){
					if(bf[j]<af[k]){
						rep(x,52){
							if(sum[af[k]][x]-sum[bf[j]+1][x]>0)name[j*52*52+k+x*52]++;
						}
					}
				}
			}
		}
		else{
			rep(x,l-2)range(y,x+1,l-1)range(z,y+1,l){
				int a=(s[x]<='Z'?s[x]-'A':s[x]-'a'+26);
				int b=(s[y]<='Z'?s[y]-'A':s[y]-'a'+26);
				int c=(s[z]<='Z'?s[z]-'A':s[z]-'a'+26);
				st.insert(a*52*52+b*52+c);
			}
		}
		for(auto x:st){
			name[x]++;
		}
	}
	int ans=-1,mx=-1;;
	rep(i,52*52*52){
		if(chmax(mx,name[i]))ans=i;
	}
	rrep(i,3){
		int t=ans;
		rep(j,i)t/=52;
		t%=52;
		cout<<(t<26?char('A'+t):char('a'+t-26));
	}
	cout<<endl;
}
