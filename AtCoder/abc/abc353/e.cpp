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
// #define MOD (1000000007ll)
#define MOD (67280421310721)
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

ll hash_string2(const string &s)
{
    ll ret = 0;
    for (char c : s)
    {
        ret = ret * 26 + (c - 'a');
        ret %= MOD;
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    map<ll, int> mp;
    rep(i, n)
    {
        string s;
        cin >> s;
        ll ret = 0;
        rep(j, sz(s))
        {
            ret = ret * 26 + (s[j] - 'a') + 1;
            ret %= MOD;
            mp[ret]++;
        }
    }
    ll ans = 0;
    for (auto &[k, v] : mp)
    {
        // puta(k, v);
        ans += (ll)v * (v - 1) / 2;
    }
    puta(ans);
}
