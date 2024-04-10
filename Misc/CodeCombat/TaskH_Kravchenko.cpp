#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const long double pi = acosl(-1.0);


int main(){
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    
    ld x,y,l,res=0;

    cin>>x>>y>>l;
    
    ld minS = min(x,y);
    ld maxS = max(x,y);

    bool side = 0;

    for (int i = 0; i < 4 && l>0; i++)
    {
        res+=(pi*l*l/4.0);
        if(!side) l-=minS;
        else l-=maxS;
        side = !side;
    }

    cout<<fixed<<setprecision(4)<<res;
    fclose(stdin);
    fclose(stdout);

    return 0;
}