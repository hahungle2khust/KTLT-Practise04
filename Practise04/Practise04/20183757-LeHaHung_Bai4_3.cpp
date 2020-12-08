#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;
using Vector = tuple<double, double, double>;

Vector cross_product(Vector a, Vector b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
}

int main() {
    cout << setprecision(2) << fixed;
    Vector a {1.2, 4, -0.5};
    Vector b {1.5, -2, 2.5};
    Vector c = cross_product(a, b);
    cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl; 
    return 0;
}