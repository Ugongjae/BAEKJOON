#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int N;
bool arr[2002][2002]={false,};

int dfs(){
    arr[1][0]=true;
    queue<pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(1,0),0));

    while(!q.empty()){
        int onWindow=q.front().first.first;
        int onBoard=q.front().first.second;
        int depth=q.front().second;
        q.pop();

        if(onWindow==N){
            return depth;
        }

        if(onWindow>0&&onWindow<2002){
            if(!arr[onWindow][onWindow]){
                arr[onWindow][onWindow]=true;
                q.push(make_pair(make_pair(onWindow,onWindow),depth+1));
            }
            if(!arr[onWindow-1][onBoard]){
                arr[onWindow-1][onBoard]=true;
                q.push(make_pair(make_pair(onWindow-1,onBoard),depth+1));
            }
        }
        if(onBoard>0&&onBoard+onWindow<2002){
            if(!arr[onWindow+onBoard][onBoard]){
                arr[onWindow+onBoard][onBoard]=true;
                q.push(make_pair(make_pair(onWindow+onBoard,onBoard),depth+1));
            }
        }
    }
}

int main(){

    cin>>N;
    cout<<dfs()<<endl;

    return 0;
}