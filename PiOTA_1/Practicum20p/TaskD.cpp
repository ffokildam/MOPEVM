#include <bits/stdc++.h>

using namespace std;

struct team{
    char name[100];
    int num;
};

int main(){
    int p,n,k;
    cin>>p>>n>>k;
    team *teams = (team *)calloc(p, sizeof(team));
    for (int i = 0; i < p; i++)
    {
        gets_s(teams[i].name, 100);
    }
    for (int i = 0; i < p; i++)
    {
        cin>>teams[i].num;
    }

    int invcount=0;

    while(invcount<n){
        for (int i = 0; i < p; i++)
        {
            if(teams[i].num<=k){
                if(strcmp(teams[i].name,"TAKEN")){
                    cout<<teams[i].name<<" "<<"#"<<teams[i].num<<endl;
                    strcpy(teams[i].name,"TAKEN");
                    invcount++;
                }
            }
        }
        
    }
    
}