#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Ball{
    int id;
    int color;
    int size;
};

int N;
int colors[200001]={0,};
int ans[200001]={0,};
Ball v[200001];

bool Comp(Ball& p1, Ball& p2){
    return p1.size<p2.size;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        scanf("%d %d",&v[i].color,&v[i].size);
        v[i].id=i;
    }

    sort(v,v+N,Comp);
    int sum=0;
    for(int i=0,j=0;i<N;i++){
        for(;v[i].size>v[j].size;j++){
            sum+=v[j].size;
            colors[v[j].color]+=v[j].size;
        }
        ans[v[i].id]=sum-colors[v[i].color];
    }

    for(int i=0;i<N;i++){
        printf("%d\n",ans[i]);
    }

    return 0;
}