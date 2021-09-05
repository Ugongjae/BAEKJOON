#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point{
    int x;
    int y;
};

bool CompByX(Point& a,Point& b){
    return a.x<b.x;
}
bool CompByY(Point& a,Point& b){
    return a.y<b.y;
}

int N;
vector<Point> arr;

int getDist(Point a,Point b){
    int dx=a.x-b.x;
    int dy=a.y-b.y;

    return dx*dx+dy*dy;
}

int Binary(int left,int right){
    if(left==right){
        return INT32_MAX;
    }
    if(left+1>=right){
        return getDist(arr[left],arr[right]);
    }

    int disMin=getDist(arr[left],arr[right]);
    int mid=(left+right)/2;

    disMin=min(disMin,Binary(left,mid));
    disMin=min(disMin,Binary(mid+1,right));

    vector<Point> vy;
    int lineX=arr[mid].x;

    for(int i=mid;i>=left;i--){
        int x=arr[i].x,dist=lineX-x;
        if(disMin<=dist*dist){
            break;
        }
        vy.push_back({arr[i].x,arr[i].y});
    }
    for(int i=mid+1;i<=right;i++){
        int x=arr[i].x,dist=lineX-x;
        if(disMin<=dist*dist){
            break;
        }
        vy.push_back({arr[i].x,arr[i].y});
    }

    int len=vy.size();
    if(len==0){
        return disMin;
    }

    sort(vy.begin(),vy.end(),CompByY);

    for(int i=0;i<len;i++){
        int ix=vy[i].x;
        int iy=vy[i].y;
        for(int j=i+1;j<len;j++){
            int jX=vy[j].x;
            int jY=vy[j].y;
            int distX=jX-ix;
            int distY=jY-iy;

            if(disMin<=distY*distY){
                break;
            }
            if(disMin<=distX*distX){
                continue;
            }
            int dist=distX*distX+distY*distY;
            disMin=min(disMin,dist);
        }
    }
}

int main(){

    cin>>N;
    for(int i=0;i<N;i++){
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        arr.push_back({tmp1,tmp2});
    }
    sort(arr.begin(),arr.end(),CompByX);

    cout<<Binary(0,N-1)<<endl;

    return 0;
}