#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string new_id){
    string answer = "";
    int len=new_id.size();
    bool isDot=false;
    for(int i=0;i<new_id.size();i++){
        if(new_id[i]>='A'&&new_id[i]<='Z'){
            new_id[i]=new_id[i]-('A'-'a');
        }
    }
    for(int i=0;i<new_id.size();i++){
        if(!(new_id[i]=='-'||new_id[i]=='_'||new_id[i]=='.'||(new_id[i]>='0'&&new_id[i]<='9')||(new_id[i]>='a'&&new_id[i]<='z'))){
            new_id.erase(new_id.begin()+i);
            i--;
        }
    }
    for(int i=0;i<new_id.size();i++){
        if(new_id[i]=='.'){
            int idx=i+1;
            while(new_id[idx]=='.'){
                idx++;
            }
            new_id.erase(new_id.begin()+i+1,new_id.begin()+idx);
        }
    }
    if(new_id.size()>0){
    if(new_id[0]=='.'){
        new_id.erase(new_id.begin());
    }
    }
    if(new_id.size()>0){
    if(new_id[new_id.size()-1]=='.'){
        new_id.erase(new_id.end()-1);
    }
    }
    if(new_id.size()==0){
        new_id+="a";
    }
    if(new_id.size()>15){
        new_id=new_id.substr(0,15);
        if(new_id[14]=='.'){
            new_id.erase(new_id.end()-1);
        }
    }
    if(new_id.size()<=2){
        while(new_id.size()!=3){
            new_id+=new_id[new_id.size()-1];
        }
    }

    return new_id;
}

int main(){

    cout<<solution("abcdefghijklmn.p")<<endl;


    return 0;
}