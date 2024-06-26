#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pdd = pair<double, double>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using tll = tuple<ll, ll>;
using tlll = tuple<ll, ll, ll>;
using vs = vector<string>;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, n) range(i, 0, n)
#define rrep(i, n) for(ll i = (n)-1; i >= 0; i--)
#define range(i, a, n) for(ll i = (a); i < (n); i++)
#define sz(x) ((ll)(x).size())

#define LINF ((ll)1ll << 60)
#define INF ((int)1 << 30)
#define EPS (1e-9)
#define MOD (1000000007ll)
// #define MOD (998244353ll)
#define fcout(a) cout << setprecision(a) << fixed
#define fs first
#define sc second
#define PI 3.1415926535897932384

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

template <class T> bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class S> S acm(vector<S> &a) { return accumulate(all(a), S()); }
template <class S> S max(vector<S> &a) { return *max_element(all(a)); }
template <class S> S min(vector<S> &a) { return *min_element(all(a)); }
void YN(bool b) { cout << (b ? "YES" : "NO") << "\n"; }
void Yn(bool b) { cout << (b ? "Yes" : "No") << "\n"; }
void yn(bool b) { cout << (b ? "yes" : "no") << "\n"; }
int sgn(const double &r) { return (r > EPS) - (r < -EPS); } // a>0  : sgn(a)>0
int sgn(const double &a, const double &b) {
    return sgn(a - b);
} // b<=c : sgn(b,c)<=0
int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
ll modpw(ll x, ll k) {
    ll res = 1;
    while(k != 0) {
        if(k & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        k = k >> 1;
    }
    return res;
}

ll max(int a, ll b) { return max((ll)a, b); }
ll max(ll a, int b) { return max(a, (ll)b); }
template <class T> void puta(T &&t) { cout << t << "\n"; }
template <class H, class... T> void puta(H &&h, T &&...t) {
    cout << h << ' ';
    puta(t...);
}
template <class S, class T> ostream &operator<<(ostream &os, pair<S, T> p) {
    os << "[" << p.first << ", " << p.second << "]";
    return os;
}
template <class S> auto &operator<<(ostream &os, vector<S> t) {
    bool a = 1;
    for(auto s : t) {
        os << (a ? "" : " ") << s;
        a = 0;
    }
    return os;
}

ll n;
vs v;
vvb dp;
vvb vstd;

bool is_valid(int i, int j) { return (v[i][sz(v[i]) - 1] == v[j][0]); }

bool rec(int used, int last) {
    if(vstd[used][last])
        return dp[used][last];
    vstd[used][last] = true;
    if(used == (1 << n) - 1) {
        return dp[used][last] = false;
    }
    bool choice = false;
    rep(i, n) {
        if(used & (1 << i))
            continue;
        if(!is_valid(last, i))
            continue;
        choice = true;
        if(!rec(used | (1 << i), i))
            return dp[used][last] = true;
    }
    return dp[used][last] = false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    v.resize(n);
    dp.resize(1 << n);
    rep(i, 1 << n) dp[i].resize(n);
    vstd.resize(1 << n);
    rep(i, 1 << n) vstd[i].resize(n);
    rep(i, n) cin >> v[i];
    bool ans = false;
    rep(i, n) ans |= !rec(1 << i, i);
    puta(ans ? "First" : "Second");
}
