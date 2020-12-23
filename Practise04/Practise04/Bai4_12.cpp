#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct tuong {
    long num;
    long enemyleft;
    long kill;
};

bool operator <(tuong lhs, tuong rhs) {
    int left = lhs.num;
    int right = rhs.num;
    if (left == right)
        return lhs.kill < rhs.kill;
    return left < right; 
}

int main() {
    cout << "Ho va ten: Le Ha Hung" << endl;
    cout << "MSSV: 20183757" << endl;

    int n, m, a, k, enemy = 0;
    priority_queue<tuong> tuong1;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a >> k;
        enemy += a;
        tuong1.push({ (k > a) ? a : k, a, k });
    }
    tuong w = tuong1.top();
    while (m > 0) {
        long x = w.enemyleft;
        long y = w.kill;
        if (m > x / y) {
            tuong1.pop();
            if (y >= x) {
                m--;
                enemy -= x;
            }
            else {
                auto rest = x % y;
                m -= x / y;
                enemy -= x - rest;
                tuong1.push({ rest, rest, y });
            }
        }
        else {
            enemy -= m * y;
            m = 0;
        }
        w = tuong1.top();
    }

    cout << enemy << endl;
    return 0;
}
