#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
int target1,target2;
vector<int> arr[101];
int check[101];

int BFS(){
    queue<int> q;
    q.push(target1);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur==target2){
            return check[target2];
        }

        for(int i=0;i<arr[cur].size();i++){
            int next=arr[cur][i];

            if(check[next]==0){
                q.push(next);
                check[next]=check[cur]+1;
            }
        }
    }
    return -1;
}

int main(){
    cin>>N;

    cin>>target1>>target2;

    cin>>M;
    for(int i=0;i<M;i++){
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;

        arr[tmp1].push_back(tmp2);
        arr[tmp2].push_back(tmp1);
    }
    cout<<BFS()<<endl;
    return 0;
}