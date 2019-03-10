#include<bits/stdc++.h>
using namespace std;
void comparar(string p, string t){
	map<long long,long long>b;
	long long i=0, j=-1;
	b[i]=j;
	long long m=p.size();
	while (i<m){
		while (j>=0 and p[i]!=p[j]) j=b[j];
			i++;j++;
		b[i]=j;
	}
	i=0; j=0;
	while (i<t.size()){
		while (j>=0 and t[i]!=p[j]) j=b[j];
			i++;j++;
		if(j==m){
			cout<<i-j<<endl;
			j=b[j];
		}
	}
}

int main(){
	string p;
	getline(cin,p);
	string ap;
	getline(cin,ap);
	comparar(ap,p);
}
