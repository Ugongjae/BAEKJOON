#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
priority_queue<int,vector<int>,greater<int>> pq;
int sum=0;

int main(){

    cin>>N;

    if(N==1){
        int tmp;
        cin>>tmp;
        cout<<tmp<<endl;
        return 0;
    }
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        pq.push(tmp);
    }
    

    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();

        int tmp=a+b;
        sum+=tmp;
        pq.push(tmp);
    }

    cout<<sum<<endl;

    return 0;
}