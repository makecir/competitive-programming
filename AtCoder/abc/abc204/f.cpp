#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using vb=vector<bool>;
using vvb=vector<vb>;
using vd=vector<double>;
using vvd=vector<vd>;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii=pair<int,int>;
using pdd=pair<double,double>;
using pll=pair<ll,ll>;
using vpll=vector<pll>;
using tll=tuple<ll,ll>;
using tlll=tuple<ll,ll,ll>;
using vs=vector<string>;

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n) range(i,0,n)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define range(i,a,n) for(ll i=(a);i<(n);i++)
#define sz(x) ((ll)(x).size())

#define LINF ((ll)1ll<<60)
#define INF ((int)1<<30)
#define EPS (1e-9)
//#define MOD (1000000007ll)
#define MOD (998244353ll)
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
int popcnt(int x){return __builtin_popcount(x);}
int popcnt(ll x){return __builtin_popcountll(x);}
ll modpw(ll x,ll k){ll res=1;while(k!=0){if(k&1){res=res*x%MOD;}x=x*x%MOD;k=k>>1;}return res;}

ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}
template<class T>void puta(T&&t){cout<<t<<"\n";}
template<class H,class...T>void puta(H&&h,T&&...t){cout<<h<<' ';puta(t...);}
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;}
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s;a=0;} return os;}
template<class T=ll>struct Matrix{
	vector<vector<T>> A;
	Matrix() {};
	Matrix(size_t n):A(n,vector<T>(n,0)){};
	Matrix(size_t r,size_t c):A(r,vector<T>(c,0)){};
	size_t nrow()const{return (A.size());}
	size_t ncol()const{return (A[0].size());}
	vector<T> operator[](const int i) const {return A[i];}
	vector<T>& operator[](const int i){return A[i];}
	// Matrix op Matrix
	Matrix& operator=(const Matrix& B){assert(ncol()==B.ncol()&&nrow()==B.nrow());rep(i,nrow())rep(j,ncol())A[i][j]=B[i][j];return *this;}
	Matrix& operator+=(const Matrix& B){assert(ncol()==B.ncol()&&nrow()==B.nrow());rep(i,nrow())rep(j,ncol())A[i][j]+=B[i][j];return *this;}
	Matrix& operator-=(const Matrix& B){assert(ncol()==B.ncol()&&nrow()==B.nrow());rep(i,nrow())rep(j,ncol())A[i][j]-=B[i][j];return *this;}
	Matrix& operator*=(const Matrix& B){assert(ncol()==B.nrow());Matrix<T> tmp(nrow(),B.ncol());rep(i,nrow())rep(j,B.ncol())rep(k,ncol())tmp[i][j]=(tmp[i][j]+A[i][k]*B[k][j])%MOD;rep(i,nrow())A[i].resize(B.ncol());rep(i,nrow())rep(j,B.ncol())A[i][j]=tmp[i][j];return *this;}
	Matrix operator+(const Matrix& B)const{return Matrix(*this)+=B;}
	Matrix operator-(const Matrix& B)const{return Matrix(*this)-=B;}
	Matrix operator*(const Matrix& B)const{return Matrix(*this)*=B;}
	bool operator==(const Matrix& B){assert(ncol()==B.ncol()&&nrow()==B.nrow);bool ret=true;rep(i,nrow())rep(j,ncol())if(B[i][j]!=A[i][j])ret=false;return ret;}
	// Matrix op Scalr
	Matrix& operator+=(const T& K){rep(i,nrow())rep(j,ncol())A[i][j]+=K;return *this;}
	Matrix& operator-=(const T& K){rep(i,nrow())rep(j,ncol())A[i][j]-=K;return *this;}
	Matrix& operator*=(const T& K){rep(i,nrow())rep(j,ncol())A[i][j]*=K;return *this;}
	Matrix& operator/=(const T& K){rep(i,nrow())rep(j,ncol())A[i][j]/=K;return *this;}
	Matrix& operator%=(const T& K){rep(i,nrow())rep(j,ncol())A[i][j]%=K;return *this;}
	Matrix operator+(const T& K)const{return Matrix(*this)+=K;}
	Matrix operator-(const T& K)const{return Matrix(*this)-=K;}
	Matrix operator*(const T& K)const{return Matrix(*this)*=K;}
	Matrix operator/(const T& K)const{return Matrix(*this)/=K;}
	Matrix operator%(const T& K)const{return Matrix(*this)%=K;}
	// 
	static Matrix I(size_t n){Matrix ret(n);rep(i,n)ret[i][i]=1;return (ret);}
	Matrix<T> pow(ll K){
		assert(nrow()==ncol());
		Matrix<T> C(nrow()),ret(nrow());
		rep(i,nrow()){rep(j,ncol())C[i][j]=A[i][j];ret[i][i]=1;}
		while(K>0){if(K&1){ret=ret*C;}C=C*C;K=K>>1;}
		return ret;
	}
	T det(){
		T ret=1;
		Matrix B(*this);
		assert(nrow()==ncol());
		rep(i,ncol()){
			int idx=-1;
			range(j,i,ncol())if(B[j][i]!=0)idx=j;
			if(idx==-1)return 0;
			if(i!=idx){
				ret*=-1;
				swap(B[i],B[idx]);
			}
			ret*=B[i][i];
			T vv=B[i][i];
			rep(j,ncol())B[i][j]/=vv;
			range(j,i+1,ncol()){
				T mul=B[j][i];
				rep(k,ncol())B[j][k]-=B[i][k]*mul;
			}
		}
		return ret;
	}
	T det(ll m=MOD){
		T ret=1;
		Matrix B(*this);
		assert(nrow()==ncol());
		rep(i,ncol()){
			int idx=-1;
			range(j,i,ncol())if(B[j][i]!=0)idx=j;
			if(idx==-1)return 0;
			if(i!=idx){
				ret*=-1;
				if(ret<0)ret+=m;
				swap(B[i],B[idx]);
			}
			ret*=B[i][i];ret%=m;
			T inv=modpw(B[i][i],m-2);
			rep(j,ncol())B[i][j]*=inv,B[i][j]%=m;
			range(j,i+1,ncol()){
				T mul=B[j][i];
				rep(k,ncol())B[j][k]+=(m-B[i][k]*mul%m),B[j][k]%=m;
			}
		}
		return (ret);
	}
	void show(){rep(i,nrow())rep(j,ncol())cout<<A[i][j]<<(j!=ncol()-1?" ":"\n");}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll h,w;
	cin>>h>>w;
	ll hh=1<<h;
	Matrix a(hh,1);
	a[0][0]=1;
	Matrix b(hh,hh);
	//rep(i,hh)rep(j,hh)b[i][j]=1;
	function<void(ll,ll,ll)> rec=[&](ll div,ll cur,ll nxt){
		if(div==h){
			b[nxt][cur]++;
		}
		else{
			if(cur&(1<<div))rec(div+1,cur,nxt);
			else{
				rec(div+1,cur,nxt);
				rec(div+1,cur,nxt|(1<<div));
				if(div+1<h&&!(cur&(1<<(div+1))))rec(div+2,cur,nxt);
			}
		}
	};
	rep(i,hh){
		rec(0,i,0);
	}
	auto c=b.pow(w)*a;
	ll ans=c[0][0];
	puta(ans);
}
