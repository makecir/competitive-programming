#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
#define MOD 1000000007

ll modpw(ll x, ll k) { 
	ll res = 1;
	while (k != 0) {
		if (k & 1) res = res*x % MOD;
		x = x*x % MOD;
		k = k >> 1;
	}
	return res;
}

ll comb(ll n, ll k) {
	if (n == 0 && k == 0)return 1;
	if (n < k || n < 0)return 0;
	return fact[n] * finv[n - k] % MOD * finv[k] % MOD;;
}

vl fact(200002), finv(200002);

main() {
	fact[0] = 1;
	finv[0] = 1;
	rep (i,200001) {
		fact[i + 1] = (fact[i] * (i + 1)) % MOD;
		finv[i + 1] = modpw(fact[i + 1], MOD-2);
	}
}




