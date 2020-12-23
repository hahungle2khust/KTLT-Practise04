#include <iostream>
#include <set>
#include <bits/stdc++.h>

using namespace std;


template<class T>
set<T> set_union(const set<T>& a, const set<T>& b) {
    
    set<T> res;
    bool mark[b.size()]{ 0 };
    for (T i : a) {
        for (T j : b) {
            if (j != i && !mark[j]) {
                res.insert(j);
                mark[j] = 1;
            }
        }
        res.insert(i);
    }
    return res;
}

template<class T>
set<T> set_intersection(const set<T>& a, const set<T>& b) {
    set<T> res;
    for (T i : a) {
        if (b.find(i) != b.end()) {
            res.insert(i);
        }
    }
    return res;
}

template<class T>
void print_set(const std::set<T>& a) {
    for (const T& x : a) {
        cout << x << ' ';
    }
    cout << endl;
}

int main() {
    cout << "Ho va ten: Le Ha Hung" << endl;
    cout << "MSSV: 20183757" << endl;
    set<int> a = { 1, 2, 3, 5, 7 };
    set<int> b = { 2, 4, 5, 6, 9 };
    set<int> c = set_union(a, b);
    set<int> d = set_intersection(a, b);

    cout << "Union: "; print_set(c);
    cout << "Intersection: "; print_set(d);

    return 0;
}
