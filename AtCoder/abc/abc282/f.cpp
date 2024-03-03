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

#define _GLIBCXX_DEBUG 1

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
    ll n, m = 0, q;
    ll in_l, in_r, a = 1, b = 1;
    cin >> n;
    map<pll, ll> mp;

    // calc m;
    ll k = 9;
    set<pll> spr;
    vpll v;
    ll mn = LINF;
    set<ll> cdt;
    const function<void(ll, ll, ll)> rec = [&](ll div, ll l, ll r) {
        ll sep = (r + l) / 2;
        cdt.insert(sep);
        chmin(mn, sep - l + 1);

        range(i, l, r + 1) {
            pll p = minmax(i, sep);
            spr.insert(p);
        }
        if(div < k) {
            rec(div + 1, l, sep - 1);
            rec(div + 1, 1 + sep, r);
        } else if(div == k) {
            range(i, l, r + 1) {
                range(j, i, r + 1) {
                    pll p = minmax(i, j);
                    spr.insert(p);
                }
            }
        }
    };
    rec(0, 1, n);

    for(auto x : spr) {
        v.push_back(x);
        mp[x] = ++m;
    }

    assert(m < 50000);

    cout << m << endl;
    rep(i, m) { cout << v[i].fs << " " << v[i].sc << endl; }

    function<pll(ll, ll, ll)> revrec = [&](ll div, ll l, ll r) {
        ll sep = (r + l) / 2;
        // cout << l << " " << r << " " << sep << endl;
        if(in_l <= sep && sep <= in_r) {
            // cout << "@" << (mp.find(pll(in_l, sep)) != mp.end())
            //      << (mp.find(pll(sep, in_r)) != mp.end()) << endl;
            // cout << "@@" << mp[pll(in_l, sep)] << " " << mp[pll(sep, in_r)]
            //      << endl;
            return pll(mp[pll(in_l, sep)], mp[pll(sep, in_r)]);
        } else if(div < k) {
            if(in_r < sep)
                return revrec(div + 1, l, sep - 1);
            else
                return revrec(div + 1, sep + 1, r);
        } else {
            // cout << "!" << (mp.find(pll(in_l, in_r)) != mp.end()) << endl;
            // cout << "!!" << mp[pll(in_l, in_r)] << endl;
            return pll(mp[pll(in_l, in_r)], mp[pll(in_l, in_r)]);
        }
    };

    // for(auto x : cdt) {
    //     cout << "!!!" << x << " " << endl;
    //     ;
    // }

    cin >> q;
    while(q--) {
        cin >> in_l >> in_r;
        // l--;
        // r--;
        tie(a, b) = revrec(0, 1, n);

        cout << a << " " << b << endl;
        // cout << "[ " << v[--a] << " " << v[--b] << " ]" << endl;
    }
}
