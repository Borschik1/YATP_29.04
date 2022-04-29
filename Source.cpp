#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;



int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    int n, m, ans = 1;
    bool bFlag;
    fin >> n >> m;
    vector<bool> vec;
    for (int i = 0; i < n; ++i) {
        vec.push_back(true);
    }
    while (vec[m - 1] && ans != n) {
        bFlag = true;
        for (int i = 0; i < n; ++i) {
            if (vec[i]) {
                if (!bFlag) {
                    vec[i] = false;
                    bFlag = true;
                    if (i == m - 1) {
                        break;
                    }
                    ans++;
                }
                else {
                    bFlag = false;
                }
            }
        }
    }
    fout << ans;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}