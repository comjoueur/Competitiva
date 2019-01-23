#include<bits/stdc++.h>
using namespace std;
long long T[40000001];
long long consulta(long long a,long long b,long long l,long long r,long long n=1){
	if(a>r || b<l || l>r || a>b)return 0;
	if(a<=l && b>=r)return T[n];
	return consulta(a,b,l,(l+r)/2,2*n)+consulta(a,b,(l+r)/2+1,r,2*n+1);
}
void actualizar(long long a,long long v,long long l,long long r,long long n=1){
	if(l>r || a<l || a>r)return ;
	T[n]+=v;
	if(l==r && r==a){
		return ;
	}
	if(a<(l+r)/2+1){
		actualizar(a,v,l,(l+r)/2,2*n);
	}
	else{
		actualizar(a,v,(l+r)/2+1,r,2*n+1);
	}
}
int main(){
	int t;
	cin>>t;
	long long x=0;
	for(;t>0;--t){
		x=0;
		memset(T,0,sizeof(T));
		int a;
		cin>>a;
		for(int i=0;i<a;i++){
			int k;
			cin>>k;
			actualizar(k,1,0,10000000,1);
			x+=consulta(k+1,10000000,0,10000000,1);
		}
		cout<<x<<endl;
	}
}
