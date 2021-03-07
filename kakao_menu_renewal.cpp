#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string,int> menuMap;
int countMap[27];
vector<string> menu[27][21];

void DFS(string s, int idx, string made){
    if(made.size()>1){
        menuMap[made]++;
        countMap[made.size()]=max(countMap[made.size()],menuMap[made]);
        menu[made.size()][menuMap[made]].push_back(made);
    }
    for(int i=idx+1;i<s.size();i++){
        made+=s[i];
        DFS(s,i,made);
        made.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int i=0;i<orders.size();i++){
        sort(orders[i].begin(),orders[i].end());
        DFS(orders[i],-1,"");
    }

    for(int i=0;i<course.size();i++){
        if(countMap[course[i]]>1){
            for(int j=0;j<menu[course[i]][countMap[course[i]]].size();j++){
                answer.push_back(menu[course[i]][countMap[course[i]]][j]);
            }
        }
    }

    sort(answer.begin(),answer.end());

    return answer;
}

int main(){

    vector<string> a1,a2,a3;
    a1.push_back("ABCFG");
    a1.push_back("AC");
    a1.push_back("CDE");
    a1.push_back("ACDE");
    a1.push_back("BCFG");
    a1.push_back("ACDEH");



}