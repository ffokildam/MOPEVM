#include <bits/stdc++.h>

using namespace std;

int main(){
    
    size_t j = 0;
    for(;;){
        size_t size = 1 << 10*3;
        int8_t* chunk = new int8_t[size];

        for (int i = 0; i < size; i++)
        {
            chunk[i] = i+1;
        }
        j++;
        cout<<"Allocated: "<<j<<" GB"<<'\n';
        
    }
}