using S = ll;
using F = ll;

const F ID = LINF;

S op(S a, S b){ return std::max(a, b); }
S e(){ return 0; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }
//lazy_segtree<S, op, e, F, mapping, composition, id> seg(w);