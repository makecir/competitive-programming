#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
#define MOD 1000000007

vl fact,finv;
ll mdpow(ll x,ll k){
	ll res=1;
	while(k!=0){
		if(k&1)res=res*x%MOD;
		x=x*x%MOD;
		k=k>>1;
	}
	return res;
}

ll comb(ll n,ll k) {
	if(n==0&&k==0)return 1;
	if(n<k||n<0)return 0;
	return fact[n]*finv[n-k]%MOD*finv[k]%MOD;
}

struct ferm{
	ferm(ll n){
		fact.resize(n);
		finv.resize(n);
		fact[0]=1;
		finv[0]=1;
		rep(i,n-1){
			fact[i+1]=(fact[i]*(i+1))%MOD;
			finv[i+1]=mdpow(fact[i+1],MOD-2);
		}
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll h,w;
	cin>>h>>w;
	ferm(200010);
	cout<<comb(h+w-2,min(h,w)-1)<<endl;
}



