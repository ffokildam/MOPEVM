//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба 3.1
//КТбо1-6, Кравченко Александр Андреевич
//TaskB
//17.03.2024
#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<string, int> devs;
    map<string, int> min;
    
    string name, devName,wideSp = "";
    
    int coast,cnt=0;
    
    for (int i = 0; i < 6; i++)
    {
        cin >> name >> devName >> coast;
        if (devs.count(devName) == 0)
        {
            devs[devName] = 1;
            min[devName] = coast;
        }
        else
        {
            devs[devName]++;
            if (coast < min[devName]) min[devName] = coast;
        }
        if (devs[devName] > cnt)
        {
            cnt = devs[devName];
            wideSp = devName;
        }
        else if (devs[devName] == cnt)
        {
            if (min[devName] < min[wideSp])wideSp = devName;
        }
    }
    cout << wideSp;
    return 0;
}