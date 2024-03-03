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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll h, w;
    cin >> h >> w;
    vvl a(h, vl(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    vector<set<ll>> wt(w + w * h), wtrev(w + w * h);
    bool ans = true;

    ll cnt = 0;
    ll utp = w;

    rep(i, h) {
        map<ll, set<ll>> mp;
        rep(j, w) {
            if(a[i][j] == 0)
                continue;
            if(mp.find(a[i][j]) == mp.end()) {
                mp[a[i][j]] = set<ll>();
            }
            mp[a[i][j]].insert(j);
        }
        for(auto itr = mp.begin(); itr != mp.end(); itr++) {
            auto itr2 = itr;
            itr2++;
            if(itr2 == mp.end()) {
                break;
            }
            for(auto itr3 = itr->second.begin(); itr3 != itr->second.end();
                itr3++) {
                wt[*itr3].insert(utp);
                wtrev[utp].insert(*itr3);
            }
            for(auto itr4 = itr2->second.begin(); itr4 != itr2->second.end();
                itr4++) {
                wt[utp].insert(*itr4);
                wtrev[*itr4].insert(utp);
            }
            utp++;
        }
    }
    queue<ll> q;
    rep(j, w + w * h) {
        // puta(j, sz(wtrev[j]));
        if(sz(wtrev[j]) == 0) {
            q.push(j);
        }
    }
    while(!q.empty()) {
        ll x = q.front();
        q.pop();
        // puta("w",x);
        cnt++;
        for(auto y : wt[x]) {
            wtrev[y].erase(x);
            if(sz(wtrev[y]) == 0) {
                q.push(y);
            }
        }
    }
    ans &= (cnt ==  w + w * h);

    vpll lincle(h, pll(LINF, -LINF));
    rep(i, h) {
        rep(j, w) {
            if(a[i][j] != 0) {
                chmin(lincle[i].fs, a[i][j]);
                chmax(lincle[i].sc, a[i][j]);
            }
        }
    }
    rep(i, h) if(lincle[i].fs == LINF) lincle[i].sc = LINF;
    sort(all(lincle));
    rep(i, h - 1) ans &= (lincle[i].sc <= lincle[i + 1].fs);

    Yn(ans);
}
