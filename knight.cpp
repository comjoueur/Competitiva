#include<bits/stdc++.h>
#define c(k1,k2) (k1>=0 && k2>=0 && k1<8 && k2<8 && !estado[k1][k2])  
using namespace std;
pair<int,int>final;
int main(){
    vector<pair<int,int> >vec;
    int estado[8][8];
    int x=0;
    char p[3],q[3];
    while(cin>>p>>q){
        vec.clear();
        memset(estado,0,sizeof(estado));
        x=0;
        int g=p[0]-'a',h=p[1]-'1';
        final.first=q[0]-'a';
        final.second=q[1]-'1';
        vec.push_back(make_pair(g,h));
        bool u=1;
        while(u){
            vector<pair<int,int> >nuevo;
            for(int i=0;i<vec.size();++i){
                if(vec[i]==final){u=0;break;}
                estado[vec[i].first][vec[i].second]=1;
            }
            if(!u)break;
            x++;
            for(int i=0;i<vec.size();++i){
                int k=vec[i].first,l=vec[i].second;
                if(c(k-1,l-2))nuevo.push_back(make_pair(k-1,l-2));
                if(c(k+1,l-2))nuevo.push_back(make_pair(k+1,l-2));
                if(c(k-1,l+2))nuevo.push_back(make_pair(k-1,l+2));
                if(c(k+1,l+2))nuevo.push_back(make_pair(k+1,l+2));
                if(c(k-2,l-1))nuevo.push_back(make_pair(k-2,l-1));
                if(c(k+2,l-1))nuevo.push_back(make_pair(k+2,l-1));
                if(c(k-2,l+1))nuevo.push_back(make_pair(k-2,l+1));
                if(c(k+2,l+1))nuevo.push_back(make_pair(k+2,l+1));
            }
            vec=nuevo;
        }
        printf("To get from %s to %s takes %d knight moves.\n",p,q,x);
    }
    return 0;
}
