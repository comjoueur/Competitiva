#include<bits/stdc++.h>
using namespace std;
long long T1[200002];
long long T2[200002];
void actualizar(long long v,long long p,long long *T){
	++p;
	for(long long i=p;i<200001;i=(i|(i+1))){
		T[i]+=v;
	}
}
long long consulta(long long p,long long *T){
	++p;
	long long s=0;
	for(long long i=p;i>0;i=(i&(i+1))-1){
		s+=T[i];
	}
	return s;
}
void actua(long long p1,long long p2,long long v){
	p2++;
	actualizar(v,p1,T1);
	actualizar(-v,p2,T1);
	actualizar((200001-p1)*v,p1,T2);
	actualizar((200001-p2)*(-v),p2,T2);
}
long long cons(long long p1,long long p2){
	p1--;
	return (consulta(p2,T2)-consulta(p2,T1)*(200001-p2-1))-(consulta(p1,T2)-consulta(p1,T1)*(200001-p1-1));
}
int main(){
	int b;
	cin>>b;
	for(;b>0;b--){
		long long a,t;
		cin>>t>>a;
		memset(T1,0,sizeof(T1));
		memset(T2,0,sizeof(T2));
		for(long long i=0;i<a;i++){
			long long g;
			cin>>g;
			if(g){
				long long k,l;
				cin>>k>>l;
				cout<<cons(k,l)<<endl;
			}
			else{
				long long k,l,m;
				cin>>k>>l>>m;
				actua(k,l,m);
			}
		}
	}
}
