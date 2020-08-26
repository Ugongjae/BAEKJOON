#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int sum=0;
vector<int> arr;

int main(){

    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());

    if(N==1){
        cout<<arr[0]<<endl;
        return 0;
    }

    sum+=arr[0]*(N-1);
    
    for(int i=1;i<N;i++){
        sum+=arr[i]*(N-i);
    }

    cout<<sum<<endl;


    return 0;
}