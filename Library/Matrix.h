template<class T=ll>struct Matrix{
	vector<vector<T>> A;
	Matrix() {};
	Matrix(size_t n):A(n,vector<T>(n,0)){};
	Matrix(size_t r,size_t c):A(r,vector<T>(c,0)){};
	size_t nrow()const{return (A.size());}
	size_t ncol()const{return (A[0].size());}
	vector<T> operator[](const int i) const {return A[i];}
	vector<T>& operator[](const int i){return A[i];}
	// Matrix op Matrix
	Matrix& operator=(const Matrix& B){assert(ncol()==B.ncol()&&nrow()==B.nrow());rep(i,nrow())rep(j,ncol())A[i][j]=B[i][j];return *this;}
	Matrix& operator+=(const Matrix& B){assert(ncol()==B.ncol()&&nrow()==B.nrow());rep(i,nrow())rep(j,ncol())A[i][j]+=B[i][j];return *this;}
	Matrix& operator-=(const Matrix& B){assert(ncol()==B.ncol()&&nrow()==B.nrow());rep(i,nrow())rep(j,ncol())A[i][j]-=B[i][j];return *this;}
	Matrix& operator*=(const Matrix& B){assert(ncol()==B.nrow());Matrix<T> tmp(nrow(),B.ncol());rep(i,nrow())rep(j,B.ncol())rep(k,ncol())tmp[i][j]=(tmp[i][j]+A[i][k]*B[k][j])%MOD;rep(i,nrow())A[i].resize(B.ncol());rep(i,nrow())rep(j,B.ncol())A[i][j]=tmp[i][j];return *this;}
	Matrix operator+(const Matrix& B)const{return Matrix(*this)+=B;}
	Matrix operator-(const Matrix& B)const{return Matrix(*this)-=B;}
	Matrix operator*(const Matrix& B)const{return Matrix(*this)*=B;}
	bool operator==(const Matrix& B){assert(ncol()==B.ncol()&&nrow()==B.nrow);bool ret=true;rep(i,nrow())rep(j,ncol())if(B[i][j]!=A[i][j])ret=false;return ret;}
	// Matrix op Scalr
	Matrix& operator+=(const T& K){rep(i,nrow())rep(j,ncol())A[i][j]+=K;return *this;}
	Matrix& operator-=(const T& K){rep(i,nrow())rep(j,ncol())A[i][j]-=K;return *this;}
	Matrix& operator*=(const T& K){rep(i,nrow())rep(j,ncol())A[i][j]*=K;return *this;}
	Matrix& operator/=(const T& K){rep(i,nrow())rep(j,ncol())A[i][j]/=K;return *this;}
	Matrix& operator%=(const T& K){rep(i,nrow())rep(j,ncol())A[i][j]%=K;return *this;}
	Matrix operator+(const T& K)const{return Matrix(*this)+=K;}
	Matrix operator-(const T& K)const{return Matrix(*this)-=K;}
	Matrix operator*(const T& K)const{return Matrix(*this)*=K;}
	Matrix operator/(const T& K)const{return Matrix(*this)/=K;}
	Matrix operator%(const T& K)const{return Matrix(*this)%=K;}
	// 
	static Matrix I(size_t n){Matrix ret(n);rep(i,n)ret[i][i]=1;return (ret);}
	Matrix<T> pow(ll K){
		assert(nrow()==ncol());
		Matrix<T> C(nrow()),ret(nrow());
		rep(i,nrow()){rep(j,ncol())C[i][j]=A[i][j];ret[i][i]=1;}
		while(K>0){if(K&1){ret=ret*C;}C=C*C;K=K>>1;}
		return ret;
	}
	T det(){
		T ret=1;
		Matrix B(*this);
		assert(nrow()==ncol());
		rep(i,ncol()){
			int idx=-1;
			range(j,i,ncol())if(B[j][i]!=0)idx=j;
			if(idx==-1)return 0;
			if(i!=idx){
				ret*=-1;
				swap(B[i],B[idx]);
			}
			ret*=B[i][i];
			T vv=B[i][i];
			rep(j,ncol())B[i][j]/=vv;
			range(j,i+1,ncol()){
				T mul=B[j][i];
				rep(k,ncol())B[j][k]-=B[i][k]*mul;
			}
		}
		return ret;
	}
	T det(ll m=MOD){
		T ret=1;
		Matrix B(*this);
		assert(nrow()==ncol());
		rep(i,ncol()){
			int idx=-1;
			range(j,i,ncol())if(B[j][i]!=0)idx=j;
			if(idx==-1)return 0;
			if(i!=idx){
				ret*=-1;
				if(ret<0)ret+=m;
				swap(B[i],B[idx]);
			}
			ret*=B[i][i];ret%=m;
			T inv=modpw(B[i][i],m-2);
			rep(j,ncol())B[i][j]*=inv,B[i][j]%=m;
			range(j,i+1,ncol()){
				T mul=B[j][i];
				rep(k,ncol())B[j][k]+=(m-B[i][k]*mul%m),B[j][k]%=m;
			}
		}
		return (ret);
	}
	void show(){rep(i,nrow())rep(j,ncol())cout<<A[i][j]<<(j!=ncol()-1?" ":"\n");}
};

