#include <bits/stdc++.h>

using namespace std;

int main(){
    int H,N,M,dealtdmg=0,countEven=0;
    vector<int> harp;
    cin>>H>>N>>M;
    harp.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin>>harp[i];
    }
    sort(harp.begin(),harp.end());
    reverse(harp.begin(),harp.end());
    for (int i = 0; i < M; i++)
    {
        if(harp[i]>0){
            if(harp[i]%2!=0 && countEven==0){
                countEven++;
                dealtdmg+=harp[i];
            }
            else if(harp[i]%2==0){
                dealtdmg+=harp[i];
            }
        }
    }
    cout<<dealtdmg<<endl;
    if(dealtdmg>=H) cout<<"VICTORY";
    else cout<<"DEFEAT";
}