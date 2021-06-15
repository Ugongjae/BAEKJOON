#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N,M;
int arr[1777][1777]={0,};
int ld[777][777]={0,};
int lu[777][777]={0,};
int rd[777][777]={0,};
int ru[777][777]={0,};
int ans=0;

int main(){

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        string s;
        cin>>s;
        for(int j=1;j<=M;j++){
            arr[i][j]=s[j-1]-'0';
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(arr[i][j]){
                ru[i][j]=ru[i-1][j+1]+1;
                lu[i][j]=lu[i-1][j-1]+1;
            }
        }
    }

    for(int i=N;i>0;i--){
        for(int j=M;j>0;j--){
            if(arr[i][j]){
                rd[i][j]=rd[i+1][j+1]+1;
                ld[i][j]=ld[i+1][j-1]+1;
            }
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            for(int k=1;k<=min(rd[i][j],ld[i][j]);k++){
                if(arr[i+2*(k-1)][j]&&lu[i+2*(k-1)][j]>=k&&ru[i+2*(k-1)][j]>=k){
                    ans=max(ans,k);
                }
            }
            for(int k=1;k<=min(rd[i][j],ru[i][j]);k++){
                if(arr[i][j+2*(k-1)]&&ld[i][j+2*(k-1)]>=k&&lu[i][j+2*(k-1)]>=k){
                    ans=max(ans,k);
                }
            }
        }
    }

    cout<<ans<<endl;


    return 0;
}