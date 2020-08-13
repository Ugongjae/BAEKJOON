#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> node[300001];
vector<pair<int,int> > edge;

long long D=0;
long long G=0;

long long Comb(int a,int b){
    long long ret=1;

    if(a-b<b)
        b=a-b;
    for(int i=a-b+1;i<a+1;i++){
        ret*=i;
    }
    for(int i=1;i<b+1;i++){
        ret/=i;
    }
    return ret;
}

int main(){
    cin>>N;
    for(int i=0;i<N-1;i++){
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        node[tmp1].push_back(tmp2);
        node[tmp2].push_back(tmp1);
        edge.push_back(make_pair(tmp1,tmp2));
    }

    for(int i=0;i<edge.size();i++){
        int left=edge[i].first;
        int right=edge[i].second;

        if(node[left].size()>=2&&node[right].size()>=2){
            D+=(node[left].size()-1)*(node[right].size()-1);
        }
    }

    for(int i=1;i<=N;i++){
        if(node[i].size()>=3){
            G+=Comb(node[i].size(),3);
        }
    }

    if(D>G*3){
        cout<<"D"<<endl;
    }else if(D==G*3){
        cout<<"DUDUDUNGA"<<endl;
    }else{
        cout<<"G"<<endl;
    }

    return 0;
}