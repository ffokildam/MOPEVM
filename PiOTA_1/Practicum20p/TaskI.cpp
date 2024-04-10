#include <bits/stdc++.h>

using namespace std;

struct train{
    char name[100];
    int dep_time;
    int arr_time;
    int speed;
    int r_time;
};

int main(){
    int n;
    cin>>n;
    
    train* trains = (train*)malloc(n);

    for (int i = 0; i < n; i++)
    {
        int a,b,c,d;
        scanf("\"%99[^\"]\" %d:%d %d:%d", trains[i].name, &a, &b, &c, &d);
        trains[i].dep_time = a*60+b;
        trains[i].arr_time = c*60+d;
        if(trains[i].arr_time<trains[i].dep_time){
            trains[i].r_time =  1440 - trains[i].dep_time + trains[i].arr_time;
        }
        else{
            trains[i].r_time =  trains[i].dep_time + trains[i].arr_time;
        }
        trains[i].speed = 650/trains[i].r_time*60;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<trains[i].speed;
    }
}