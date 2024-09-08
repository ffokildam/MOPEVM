// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 7
// КТбо1-6, Кравченко Александр Андреевич
// TaskB
// 26.05.2024
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int x1, y1, x2, y2, x0, y0, l;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x0 >> y0 >> l;
    cout << fixed << setprecision(2);
   
    double firstEdge = sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2));
    double secondEdge = sqrt(pow(x2 - x0, 2) + pow(y2 - y0, 2));
    double field = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double ans2 = max(firstEdge, secondEdge) - l; 

    double ans1;
   
    double a = firstEdge * firstEdge;
    double b = secondEdge * secondEdge;
    double c = field * field;
    
    if (a+c < b || b+c < a) {
        ans1 = min(firstEdge, secondEdge) - l;
    }
    else {
        
        double p = (firstEdge + secondEdge + field) / 2;
        //<|ENG: get square of triangle|>
        //<|RUS: poluchaem ploshad treygolnika |>
        double S = sqrt(p * (p - firstEdge) * (p - secondEdge) * (p - field));

        //<|ENG: If the area is zero and the field with pineapples does not exist (test: 2 2 2 2 3 3 1)|>
        //<|RUS: Esli ploshad ravna 0 i polia c ananasami kak bu net (test: 2 2 2 2 3 3 1)|>
        if (S == 0 && field == 0) {
            ans1 = min(firstEdge, secondEdge) - l;
        }
        //<|ENG: If the area is zero and more than one side is not zero (test: -5 0 5 0 1 0 1)|>
        //<|RUS: Esli ploshad ravna 0 i ni odna storona ne ravna 0 (test:  -5 0 5 0 1 0 1)|>
        else if (S == 0 && firstEdge != 0 && secondEdge != 0 && field != 0) {
            ans1 =  0;
        }
        else {
            //<|ENG: Default. We just look for the height using the formula|>
            //<|RUS: Obichni slychai. Prosto po formule S = a*h/2 (test:  -5 0 5 0 1 0 1)|>
            double d = 2 * S / field;
            ans1 = d - l;
        }
    }
    //<|ENG: If, after subtracting the rope, the length becomes negative, then do 0|>
    //<|RUS: Esli sle vichetania verevki otvet stal menihe nylia to delayem 0|>
    ans1 = ans1 < 0 ? 0 : ans1;
    ans2 = ans2 < 0 ? 0 : ans2;

    //<|ENG: Next just cout "round(ans1 * 100) / 100" and "round(ans2 * 100) / 100"|>
    //<|RUS: Teper prosto vivedi "round(ans1 * 100) / 100" i "round(ans2 * 100) / 100"|>

    //!!!!!!!!!!!!!!!!!!!
    //cout << round(ans1 * 100) / 100 << endl;
    //cout << round(ans2 * 100) / 100;
    return 0;

    //<|ENG: Thanks a lot for your time here!|>
    //<|RUS: Spasibo chto pochitali i uia vam pomog (navernoe)|>
    // :)

