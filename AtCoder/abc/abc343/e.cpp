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

ll f2(ll a2, ll b2, ll c2, ll a3, ll b3, ll c3)
{
    ll x = max(0ll, min(a2 + 7, a3 + 7) - max(a2, a3));
    ll y = max(0ll, min(b2 + 7, b3 + 7) - max(b2, b3));
    ll z = max(0ll, min(c2 + 7, c3 + 7) - max(c2, c3));
    return x * y * z;
}

ll f3(ll a2, ll b2, ll c2, ll a3, ll b3, ll c3)
{
    ll x = max(0ll, min({7ll, a2 + 7, a3 + 7}) - max({0ll, a2, a3}));
    ll y = max(0ll, min({7ll, b2 + 7, b3 + 7}) - max({0ll, b2, b3}));
    ll z = max(0ll, min({7ll, c2 + 7, c3 + 7}) - max({0ll, c2, c3}));
    return x * y * z;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll v1, v2, v3;
    cin >> v1 >> v2 >> v3;
    ll a1 = 0;
    ll b1 = 0;
    ll c1 = 0;
    for (ll a2 = -7; a2 <= 7; a2++)
    {
        for (ll b2 = -7; b2 <= 7; b2++)
        {
            for (ll c2 = -7; c2 <= 7; c2++)
            {
                for (ll a3 = -7; a3 <= 7; a3++)
                {
                    for (ll b3 = -7; b3 <= 7; b3++)
                    {
                        for (ll c3 = -7; c3 <= 7; c3++)
                        {
                            ll u3 = f3(a2, b2, c2, a3, b3, c3);
                            ll u2_1 = f2(a2, b2, c2, a3, b3, c3);
                            ll u2_2 = f2(0, 0, 0, a3, b3, c3);
                            ll u2_3 = f2(a2, b2, c2, 0, 0, 0);
                            if (
                                v3 == u3 &&
                                v2 == (u2_1 + u2_2 + u2_3 - u3 * 3) &&
                                v1 == (7 * 7 * 7 * 3 - (u2_1 + u2_2 + u2_3 - u3 * 3) * 2 - (u3) * 3))
                            {
                                puta("Yes");
                                puta(0, 0, 0, a2, b2, c2, a3, b3, c3);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    puta("No");
}
