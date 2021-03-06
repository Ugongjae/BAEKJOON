#include <iostream>
#include <vector>
using namespace std;

int N;
long long arr[4][4001];
vector<long long> A;
vector<long long> B;

int main(){

    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<4;j++){
            cin>>arr[j][i];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            A.push_back(arr[0][i]+arr[1][j]);
            B.push_back(arr[2][i]+arr[3][j]);
        }
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    int nA=0;
    int nB=B.size()-1;
    long long ans=0;
    while(nA<A.size()&&nB>=0){
        if(A[nA]+B[nB]==0){
            long long l=1;
            long long r=1;
            while(1){
                if(nA+1<A.size()){
                    if(A[nA]==A[nA+1]){
                        nA++;
                        l++;
                        continue;
                    }
                }
                break;
            }
            while(1){
                if(nB-1>=0){
                    if(B[nB]==B[nB-1]){
                        r++;
                        nB--;
                        continue;
                    }
                }
                break;
            }
            ans+=(r*l);
            nA++;
            nB--;
        }else if(A[nA]+B[nB]<0){
            nA++;
        }else{
            nB--;
        }
    }

    cout<<ans<<endl;

    return 0;
}