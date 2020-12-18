#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<string, int> my_f[1001];
map<string, int> my_df;
int my_maxf[1001];

int main() {
    cout << "Ho va ten: Le Ha Hung" << endl;
    cout << "MSSV: 20183757" << endl;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //input texts
    int N, nQ;
    string tmp;
    vector<string> T[1001];

    cin >> N;
    for (int d = 0; d < N; d++) {
        cin >> tmp;
        int i_begin = 0;
        int n = tmp.length();
        map<string, int> tmp_df;


        for (int k = 0; k <= n; k++) {
            if (tmp[k] == ',' || k == n) {
                string w = tmp.substr(i_begin, k - i_begin);
                T[d].push_back(w);
                my_f[d][w]++;
                i_begin = k + 1;
                if (++tmp_df[w] == 1) my_df[w]++;
            }
        }

        for (auto it : my_f[d]) {
            my_maxf[d] = max(my_maxf[d], it.second);
        }
    }
    int index;
    double maxScore, score;

    //input queries
    cin >> nQ;
    for (int q = 0; q < nQ; q++) {
        cin >> tmp;
        vector<string> Q;
        int i_begin = 0;
        int n = tmp.length();

        for (int k = 0; k <= n; k++) {
            if (tmp[k] == ',' || k == n) {
                string w = tmp.substr(i_begin, k - i_begin);
                Q.push_back(w);
                i_begin = k + 1;
            }
        }
        index = 0;
        maxScore = -1e9;
        for (int d = 0; d < N; d++) {
            score = 0;
            int maxf = my_maxf[d];  // maxF cua moi van ban
            for (string t : Q) {              // duyet moi tu trong tung cau truy van
                int f = my_f[d][t];
                if (f != 0)
                    score += (0.5 + 0.5 * f / maxf) * log2(1.0 * N / my_df[t]);
            }
            if (maxScore < score) {
                maxScore = score;
                index = d;
            }
        }
        cout << index + 1 << endl;
    }
    return 0;
}
