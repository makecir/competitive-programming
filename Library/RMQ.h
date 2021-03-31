#include <atcoder/all>
using namespace atcoder;


using S = ll;
using F = ll;

S op(S a, S b){ return std::min(a, b); }
S e(){ return LINF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	vector<S> v(n*2);
	lazy_segtree<S,op,e,F,mapping,composition,id> seg(v);
	
}
