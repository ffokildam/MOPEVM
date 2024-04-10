#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    set<char> s1set;
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    for (int i = 0; i < s1.length(); i++)
    {
        s1set.insert(toupper(s1[i]));
    }
    for (int i = 0; i < s2.length(); i++)
    {
        s1set.insert(toupper(s2[i]));
    }
    int i = 0;
    for(char c = 'A'; c <= 'Z'; ++c) {
        if(s1set.find(c)==s1set.end()){
            cout<<c;
            i =1;
        }
    }
    if(i==0) cout<<0;
    return 0;
}