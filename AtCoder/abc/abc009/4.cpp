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
#define MOD (1000000007ll)
//#define MOD (998244353ll)
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
template <typename T> struct Matrix {
	int H, W;
	vector<T> elem;
	typename vector<T>::iterator operator[](int i) { return elem.begin() + i * W; }
	inline T &at(int i, int j) { return elem[i * W + j]; }
	inline T get(int i, int j) const { return elem[i * W + j]; }
	operator vector<vector<T>>() const {
		vector<vector<T>> ret(H);
		rep(i,H) copy(elem.begin()+i*W, elem.begin()+(i+1)*W, back_inserter(ret[i]));
		return ret;
	}
 
	Matrix() = default;
	Matrix(int N) : Matrix(N, N) {}
	Matrix(int H, int W) : H(H), W(W), elem(H * W) {}
	Matrix(const vector<vector<T>> &d) : H(d.size()), W(d.size() ? d[0].size() : 0) {
		for (auto &raw : d) copy(raw.begin(), raw.end(), back_inserter(elem));
	}
 
	static Matrix Identity(int N){ Matrix ret(N, N); rep(i,N)ret.at(i,i)=UINT_MAX; return ret; }
 
	Matrix operator-() const{ Matrix ret(H, W); rep(i,H*W)ret.elem[i]=-elem[i]; return ret; }
	Matrix operator*(const T &v) const { Matrix ret=*this; for(auto&x:ret.elem)x*=v; return ret; }
	Matrix operator/(const T &v) const { Matrix ret=*this; for(auto&x:ret.elem)x/=v; return ret; }
	Matrix operator+(const Matrix &r) const { Matrix ret=*this; rep(i,H*W)ret.elem[i]+=r.elem[i]; return ret;}
	Matrix operator-(const Matrix &r) const { Matrix ret=*this; rep(i,H*W)ret.elem[i]-=r.elem[i]; return ret; }
	Matrix operator*(const Matrix &r) const { Matrix ret(H, r.W); rep(i,H)rep(k,W)rep(j,r.W)ret.at(i, j)^=(this->get(i, k))&(r.get(k, j)); return ret; }
	Matrix &operator*=(const T &v) { return *this=*this*v; }
	Matrix &operator/=(const T &v) { return *this=*this/v; }
	Matrix &operator+=(const Matrix &r) { return *this=*this+r; }
	Matrix &operator-=(const Matrix &r) { return *this=*this-r; }
	Matrix &operator*=(const Matrix &r) { return *this=*this*r; }
	bool operator==(const Matrix &r) const { return H == r.H && W == r.W && elem == r.elem; }
	bool operator!=(const Matrix &r) const { return !(*this==r); }
	bool operator<(const Matrix &r) const { return elem < r.elem; }
	Matrix pow(int64_t n) const {
		Matrix ret=Identity(H);
		if(n)rrep(i,64-__builtin_clzll(n)){ if(ret*=ret;(n>>i)&1)ret*=*this; }
		return ret;
	}
	// 転置
	Matrix transpose() const {
		Matrix ret(W, H);
		rep(i,H)rep(j,W)ret.at(j, i)=this->get(i, j);
		return ret;
	}
	// ガウスの掃き出し法 (整数でもdoubleにすること)
	// O(H^2 W)
	Matrix gauss_jordan() const {
		int c = 0;
		Matrix mtr(*this);
		vector<int> ws;
		ws.reserve(W);
		rep(h,H) {
			if (c == W) break;
			int piv = -1;
			range(j,h,H)if(mtr.get(j, c)){piv=j; break;}
			if(piv==-1){c++; h--; continue;}
			if (h != piv)rep(w,W){
				swap(mtr[piv][w], mtr[h][w]);
				mtr.at(piv, w) *= -1;
			}
			ws.clear();
			range(w,c,W)if(mtr.at(h, w)) ws.emplace_back(w);
			rep(hh,H)if(hh!=h){
				const T coeff=mtr.at(hh, c)/mtr.at(h, c);
				for(auto&w:ws)mtr.at(hh, w)-=mtr.at(h, w)*coeff;
			}
			c++;
		}
		return mtr;
	}
	// 掃き出し済みを仮定したランク
	// ランク=変数の個数なら唯一解、ランク<変数の個数なら不定解
	// 係数行列のランク!=拡大係数行列のランクの場合、この値にかかわらず解なし
	int rank_of_gauss_jordan() const { rrep(i,H*W)if(elem[i])return i/W+1; return 0; }
	// 上三角行列（=掃き出し済み）を仮定した行列式
	T determinant_of_upper_triangle() const { T ret=1; rep(i,H)ret*=get(i, i); return ret; }
	// 逆行列
	int inverse() {
		assert(H == W);
		vector<vector<T>> ret = Identity(H), tmp = *this;
		int rank = 0;
		rep(i,H) {
			int ti = i;
			while (ti < H and tmp[ti][i] == 0) ti++;
			if (ti == H) continue;
			rank++;
			ret[i].swap(ret[ti]), tmp[i].swap(tmp[ti]);
			T inv = tmp[i][i].inv();
			rep(j,W) ret[i][j] *= inv;
			range(j,i+1,W) tmp[i][j] *= inv;
			rep(h,H)if(i!=h){
				const T c = -tmp[h][i];
				rep(j,W) ret[h][j] += ret[i][j] * c;
				range(j,i+1,W) tmp[h][j] += tmp[i][j] * c;
			}
		}
		*this = ret;
		return rank;
	}
	friend vector<T> operator*(const Matrix &m, const vector<T> &v) {
		assert(m.W == int(v.size()));
		vector<T> ret(m.H);
		rep(i,m.H)rep(j,m.W) ret[i] += m.get(i, j) * v[j];
		return ret;
	}
	friend vector<T> operator*(const vector<T> &v, const Matrix &m) {
		assert(int(v.size()) == m.H);
		vector<T> ret(m.W);
		rep(i,m.H)rep(j,m.W) ret[j] += v[i] * m.get(i, j);
		return ret;
	}
	friend ostream &operator<<(ostream &os, const Matrix &x) {
		puta((vector<vector<T>>)x, os); return os;
	}
	friend istream &operator>>(istream &is, Matrix &x) {
		return is>>x.elem;
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,k,ans;
	cin>>n>>k;
	Matrix<uint> a(n,1);
	Matrix<uint> c(n);
	rep(i,n)cin>>a[i][0];
	rrep(i,n)cin>>c[n-1][i];
	if(k<=n){
		ans=a[k-1][0];
	}
	else{
		rep(i,n-1)c[i][i+1]=UINT_MAX;
		auto ansmat=c.pow(k-n)*a;
		ans=ansmat[n-1][0];
	}
	puta(ans);
}
