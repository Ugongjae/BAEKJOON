#include <iostream>
#include <algorithm>
using namespace std;

int K,N;
long long arr[10001];
long long ans=-1;

void Input(){
    cin>>K>>N;
    for(int i=0;i<K;i++){
        cin>>arr[i];
    }
}

long long Solve(){
    long long right=INT32_MAX;
    long long left=0;
    long long mid=0;
    while(left<right){
        mid=(left+right)/2;

        long long sum=0;
        for(int i=0;i<K;i++){
            sum+=(arr[i]/mid);
        }

        if(sum>=N){
            ans=mid;
            left=mid+1;
        }else{
            right=mid;
        }
    }
    return ans;
}

int main(){
    Input();
    cout<<Solve()<<endl;


    return 0;
}