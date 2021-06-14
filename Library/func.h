constexpr ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
constexpr ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

ll extgcd(ll a,ll b,ll &x,ll &y) {
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll d=extgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

tuple<bool, ll, ll> ExtGCD(ll a, ll b, ll c)
{
	auto[v,l]=atcoder::crt({0,c%abs(b)},{abs(a),abs(b)});
	return {l!=0, v/a, (c-v)/b};
}

bool isPrime(ll n){
	if(n==1)return false;
	for(ll i=2;i*i<=n;i++)if(n%i==0)return false;
	return true;
}

vl primeFactorVec(ll n) {
	vl ret;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){ret.push_back(i);while(n%i==0){n/=i;}};
	}
	if(n>1) ret.push_back(n);
	return ret;
}

map<ll,int> primeFactorMp(ll n){
	map<ll,int> ret;
	for(ll i=2;i*i<=n;i++)if(n%i==0){n/=i;ret[i--]++;}
	if(n-1)ret[n]++;
	return ret;
}

vl enumdiv(ll n) {
	set<ll> s;
	for(ll i=1;i*i<=n;i++)if(n%i==0)s.insert(i),s.insert(n/i); 
	s.insert(n);
	return vl(s.begin(),s.end());
}

ll euler_phi(ll n){
	ll ret=n;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			ret=ret/i*(i-1);
			while(n%i==0)n/=i;
		}
	}
	if(n!=1)ret=ret/n*(n-1);
	return ret;
}

int popcnt(int x){return __builtin_popcount(x);}
int popcnt(ll x){return __builtin_popcountll(x);}
int clz(int x){return 32 - __builtin_clz(x);}
int clz(ll x){return 64 - __builtin_clzll(x);}
int ffs(int x){return __builtin_ffs(x);}
int ffs(ll x){return __builtin_ffsll(x);}


ll op(ll a, ll b) {
	return min(a, b);
}

ll e() {
	return LINF;
}


template<class H,class...T>void puta(H&&h,T&&...t){cout<<h<<' ';puta(t...);}
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s;a=0;} return os;}