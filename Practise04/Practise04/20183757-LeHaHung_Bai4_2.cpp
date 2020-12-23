#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>; 

double area(Point a, Point b, Point c) {
    double S;
    double A = (c.first - a.first) * (b.second - a.second);
    double B = (b.first - a.first) * (c.second - a.second);
    S = abs(A - B) / 2;
    return S;
}

int main() {
    
    cout << setprecision(2) << fixed;
    cout << area({ 1, 2 }, { 2.5, 10 }, { 15, -5.25 }) << endl;
    return 0;
}
