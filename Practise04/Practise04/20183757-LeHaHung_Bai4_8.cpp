#include <iostream>
#include <map>
#include <math.h>

using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double>& a, const map<T, double>& b) {
   
    map<T, double> res;
    for (pair<T, double> i : a) {
        if (b.find(i.first) != b.end()) {
            res.insert(pair<T, double>(i.first, max(i.second, b.find(i.first)->second)));
        }
        else res.insert(pair<T, double>(i.first, i.second));
    }
    for (pair<T, double> i : b) {
        if (a.find(i.first) == a.end()) {
            res.insert(pair<T, double>(i.first, i.second));
        }
    }
    return res;

}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double>& a, const map<T, double>& b) {

    map<T, double> res;
    for (pair<T, double> i : a) {
        if (b.find(i.first) != b.end()) {
            res.insert(pair<T, double>(i.first, min(i.second, b.find(i.first)->second)));
        }
    }
    return res;
}

template<class T>
void print_fuzzy_set(const map<T, double>& a) {
    cout << "{ ";
    for (const auto& x : a) {
        cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    cout << endl;
}

int main() {
    map<int, double> a = { {1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7} };
    map<int, double> b = { {1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1} };
    cout << "A = "; print_fuzzy_set(a);
    cout << "B = "; print_fuzzy_set(b);
    map<int, double> c = fuzzy_set_union(a, b);
    map<int, double> d = fuzzy_set_intersection(a, b);
    cout << "Union: "; print_fuzzy_set(c);
    cout << "Intersection: "; print_fuzzy_set(d);
}
