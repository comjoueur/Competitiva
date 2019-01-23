#include<bits/stdc++.h>
using namespace std;
int arr[200001];
void actualizar(int index,int val){
	index++;
	for(int i=index;i<200001;i=(i|(i+1))){
		arr[i]+=val;
	}
}
int consulta(int a){
	int y=0;
	a++;
	for(int i=a;i>0;i=(i&(i+1))-1){
		y+=arr[i];
	}
	return y;
}
int cons(int a,int b){
	--a;
	return consulta(b)-consulta(a);
}
int main(){
	memset(arr,0,sizeof(arr));
	int a;
	cin>>a;
	for(int i=0;i<a;i++){
		int g;
		cin>>g;
		if(g){
			int n1,n2;
			cin>>n1>>n2;
			cout<<cons(n1,n2)<<endl;
		}
		else{
			int n,v;
			cin>>n>>v;
			actualizar(n,v);
		}
	}
}
