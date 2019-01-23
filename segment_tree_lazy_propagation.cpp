#include<bits/stdc++.h>
using namespace std;
long long T[400001];
long long lazy[400001];
void actualizar_rango(long long a,long long b,long long l,long long r,long long v,long long n){
	T[n]+=lazy[n]*(r-l+1);
	if(l!=r){
		lazy[2*n]+=lazy[n];
		lazy[2*n+1]+=lazy[n];
	}
	lazy[n]=0;
	if(r<l || a>r || b<l || a>b){
		return;
	}
	if(l>=a && b>=r){
		T[n]+=v*(r-l+1);
		if(l!=r){
			lazy[2*n]+=v;
			lazy[2*n+1]+=v;
		}
		return;
	}
	actualizar_rango(a,b,l,(l+r)/2,v,2*n);
	actualizar_rango(a,b,(l+r)/2+1,r,v,2*n+1);
	T[n]=T[2*n]+T[2*n+1];
}
long long consultar_rango(long long a,long long b,long long l,long long r,long long n){
	if(a>r || b<l || a>b || r<l){
		return 0;
	}
	T[n]+=lazy[n]*(r-l+1);
	if(l!=r){
		lazy[2*n]+=lazy[n];
		lazy[2*n+1]+=lazy[n];
	}
	lazy[n]=0;
	if(a<=l && b>=r)return T[n];
	return consultar_rango(a,b,l,(l+r)/2,2*n)+consultar_rango(a,b,(l+r)/2+1,r,2*n+1);
}
int main(){
	long long k=0;
	cin>>k;
	for(;k>0;k--){
		memset(lazy,0,sizeof(lazy));
		memset(T,0,sizeof(T));
		long long a,b;
		cin>>b>>a;
		for(long long i=0;i<a;i++){
			int g;
			cin>>g;
			if(g==0){
				long long p,q,r;
				cin>>p>>q>>r;
				actualizar_rango(p,q,0,b,r,1);
			}
			else{
				long long p,q;
				cin>>p>>q;
				cout<<consultar_rango(p,q,0,b,1)<<endl;
			}
		}
	}
}
