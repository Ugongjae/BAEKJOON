#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;


vector<string> split(string s, string divid) {
    vector<string> v;
    char* c = strtok((char*)s.c_str(), divid.c_str());
    while (c) {
        v.push_back(c);
        c = strtok(NULL, divid.c_str());
    }
    return v;
}

int main() {
    string s;
    getline(cin, s);
    vector<string> v = split(s, " ");

    cout << v.size() << endl;
}