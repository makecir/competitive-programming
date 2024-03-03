// clang-format off

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
#define sz(x) (int)(x).size()

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

ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}

template<typename T> concept Iterable = ranges::range<T> && !is_convertible_v<T, string_view>;
template<typename T> concept RecursiveIterable = Iterable<T> && ranges::range<ranges::range_value_t<T>>;
template<typename T> concept TupleLike = !Iterable<T> && requires(T a) {
    tuple_size<T>::value;
    get<0>(a);
    !is_convertible_v<T, string_view>;
};
constexpr ostream&operator<<(ostream&os, Iterable auto a){
    if(auto b=begin(a), e=end(a) ; a.size()) for(os<<(*b++);b!=e;os<<' '<<(*b++)) ;
    return os;
}
constexpr ostream&operator<<(ostream&os, RecursiveIterable auto a){
    if(auto b=begin(a), e=end(a) ; a.size()) for(os<<(*b++);b!=e;os<<'\n'<<(*b++)) ;
    return os;
}
constexpr ostream&operator<<(ostream&os, TupleLike auto a){
    apply([&](auto&&...args){((os<<args<<' '),...);}, a);
    return os;
}
template<class T>void puta(T&&t){cout<<t<<"\n";}
template<class H,class...T>void puta(H&&h,T&&...t){cout<<h<<' ';puta(t...);}

// clang-format on

struct S
{
    ll a;
    ll a_cnt;
    ll b;
    ll b_cnt;
};

S op(S l, S r)
{
    ll new_a;
    ll new_a_cnt;
    ll new_b;
    ll new_b_cnt;
    if (l.a == r.a)
    {
        new_a = l.a;
        new_a_cnt = l.a_cnt + r.a_cnt;
        if (l.b == r.b)
        {
            new_b = l.b;
            new_b_cnt = l.b_cnt + r.b_cnt;
        }
        else if (l.b > r.b)
        {
            new_b = l.b;
            new_b_cnt = l.b_cnt;
        }
        else
        {
            new_b = r.b;
            new_b_cnt = r.b_cnt;
        }
    }
    else if (l.a > r.a)
    {
        new_a = l.a;
        new_a_cnt = l.a_cnt;
        if (r.a == l.b)
        {
            new_b = r.a;
            new_b_cnt = r.a_cnt + l.b_cnt;
        }
        else if (r.a > l.b)
        {
            new_b = r.a;
            new_b_cnt = r.a_cnt;
        }
        else
        {
            new_b = l.b;
            new_b_cnt = l.b_cnt;
        }
    }
    else
    {
        new_a = r.a;
        new_a_cnt = r.a_cnt;
        if (l.a == r.b)
        {
            new_b = l.a;
            new_b_cnt = l.a_cnt + r.b_cnt;
        }
        else if (l.a > r.b)
        {
            new_b = l.a;
            new_b_cnt = l.a_cnt;
        }
        else
        {
            new_b = r.b;
            new_b_cnt = r.b_cnt;
        }
    }
    return S{new_a, new_a_cnt, new_b, new_b_cnt};
}

S e()
{
    return S{-1, 0, -2, 0};
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    vl a(n);
    rep(i, n) cin >> a[i];
    segtree<S, op, e> seg(n);
    rep(i, n) seg.set(i, S{a[i], 1, -1, 0});
    rep(i, q)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
        {
            x--;
            seg.set(x, S{y, 1, -1, 0});
        }
        else
        {
            x--;
            y--;
            puta(seg.prod(x, y + 1).b_cnt);
        }
    }
}
