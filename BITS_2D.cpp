#include<bits/stdc++.h>
using namespace std;
int T[1003][1003];
void actualizar(int p1,int p2,int v){
	p1++;
	p2++;
	for(int i=p1;i<1003;i=(i|(i+1))){
		for(int j=p2;j<1003;j=(j|(j+1))){
			T[i][j]+=v;
		}
	}
}
int consultar(int p1,int p2){
	p1++;
	p2++;
	int s=0;
	for(int i=p1;i>0;i=(i&(i+1))-1){
		for(int j=p2;j>0;j=(j&(j+1))-1){
			s+=T[i][j];
		}
	}
	return s;
	
}

int main(){
	memset(T,0,sizeof(T));
	int a;
	cin>>a;
	for(int i=0;i<a;i++){
		int g;cin>>g;
		if(g){
			int x,y,v;cin>>x>>y>>v;
			actualizar(x,y,v);
		}
		else{
			int x,y;cin>>x>>y;
			cout<<consultar(x,y)<<endl;
		}
	}
}
