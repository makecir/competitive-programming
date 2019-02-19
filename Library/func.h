constexpr ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
constexpr ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

ll exgcd(ll a,ll b,ll &x,ll &y) {
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

bool isPrime(ll n){
    for(ll i=2;i*i<=n;i++)if(n%i==0)return false;
    return true;
}

map<ll,int> primeFactor(ll n){
    map<ll,int> ret;
    for(ll i=2;i*i<=n;i++)if(n%i==0){n/=i;ret[i--]++;}
    if(n-1)ret[n]++;
    return ret;
}
