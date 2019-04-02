template<class T=ll>struct Graph{
	int n;
	vector<vector<tuple<ll,T>>>edge;
	Graph(int N=1):n(N){edge.resize(n);}
	void add(ll f,ll t,T c,bool d=false){
		edge[f].emplace_back(t,c);
		if(!d)edge[t].emplace_back(f,c);
	}
	void view(){
		rep(i,n)for(auto&e:edge[i])
			puta(i,"=>",get<0>(e),", cost :",get<1>(e));
	}
};

template<class T=ll>struct Dijkstra:Graph<T>{
	using Graph<T>::Graph;
	Dijkstra(int N=1):Graph<T>::Graph(N){}
	const T mval=numeric_limits<T>::max()/2;
	vector<T>dist(ll s){
		vector<T> ret(this->n,mval);
		priority_queue<tuple<T,ll>> q;
		q.emplace(T(),s);
		while(!q.empty()){
			T c; ll p; tie(c,p)=q.top(); q.pop();
			if(ret[p]!=mval)continue;
			ret[p]=c=-c;
			for(auto&e:this->edge[p]){
				ll nxt;T cost;
				tie(nxt,cost)=e;
				if(ret[nxt]<=ret[p]+cost)continue;
				q.emplace(-ret[p]-cost,nxt);
			}
		}
		return ret;
	}
	T dist(ll s,ll t){return dist(s)[t];}
};

template<class T=ll>struct BellmanFord:Graph<T>{
	using Graph<T>::Graph;
	BellmanFord(int N=1):Graph<T>::Graph(N){}
	const T mval=numeric_limits<T>::max()/2;
	vector<T>dist(ll s){
		vector<T> ret(this->n,mval);
		ret[s]=0;
		rep(i,2*this->n){
			rep(f,this->n)for(auto&e:this->edge[f]){
				ll t; T c; tie(t,c)=e;
				if(ret[f]!=mval && chmin(ret[t],ret[f]+c) && i+1>=this->n){
					ret[t]=-mval;
				}
			}
		}
		return ret;
	}
	T dist(ll s,ll t){return dist(s)[t];}
};

template<class T=ll>struct WarshallFloyd:Graph<T>{
	bool negativeCycle=false;
	using Graph<T>::Graph;
	WarshallFloyd(int N=1):Graph<T>::Graph(N){}
	const T mval=numeric_limits<T>::max()/2;
	vector<vector<T>>dist(){
		vector<vector<T>> ret(this->n,vector<T>(this->n,mval));
		rep(i,this->n)ret[i][i]=0;
		rep(f,this->n)for(auto&e:this->edge[f]){
			ll t; T c; tie(t,c)=e; ret[f][t]=c;
		}
		rep(k,this->n)rep(i,this->n)if(ret[i][k]!=mval)
			rep(j,this->n)if(ret[k][j]!=mval)
				chmin(ret[i][j],ret[i][k]+ret[k][j]);
		rep(i,this->n)negativeCycle|=ret[i][i]<0;
		return ret;
	}
};
